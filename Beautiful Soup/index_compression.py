import requests
from bs4 import BeautifulSoup
import warnings
import re
import string
from collections import Counter
from tabulate import tabulate
from math import log, ceil
from struct import pack, unpack

warnings.filterwarnings("ignore")


STOPWORDS = ['ourselves', 'hers', 'between', 'yourself', 'but', 'again', 'there', 'about', 'once', 'during', 'out', 'very', 'having', 'with', 'they', 'own', 'an', 'be', 'some', 'for', 'do', 'its', 'yours', 'such', 'into', 'of', 'most', 'itself', 'other', 'off', 'is', 's', 'am', 'or', 'who', 'as', 'from', 'him', 'each', 'the', 'themselves', 'until', 'below', 'are', 'we', 'these', 'your', 'his', 'through', 'don', 'nor', 'me', 'were', 'her', 'more', 'himself', 'this', 'down', 'should', 'our', 'their', 'while',
             'above', 'both', 'up', 'to', 'ours', 'had', 'she', 'all', 'no', 'when', 'at', 'any', 'before', 'them', 'same', 'and', 'been', 'have', 'in', 'will', 'on', 'does', 'yourselves', 'then', 'that', 'because', 'what', 'over', 'why', 'so', 'can', 'did', 'not', 'now', 'under', 'he', 'you', 'herself', 'has', 'just', 'where', 'too', 'only', 'myself', 'which', 'those', 'i', 'after', 'few', 'whom', 't', 'being', 'if', 'theirs', 'my', 'against', 'a', 'by', 'doing', 'it', 'how', 'further', 'was', 'here', 'than']

WEBSITE_LIST = ["http://youtube.com/",
                "https://football.com/", "https://gitlab.com/"]
documents = []

for website in WEBSITE_LIST:
    page = requests.get(website, verify=False)
    soup = BeautifulSoup(page.text, 'lxml')
    documents.append(soup.get_text())


def to_lower(text):
    return text.lower()


def remove_url(text):
    text = re.sub(
        r"\b(?:(?:https|ftp|http|www)://)?\w[\w-]*(?:\.[\w-]+)+\S*", '', text, flags=re.MULTILINE)
    return text


PUNCT_TO_REMOVE = string.punctuation


def remove_punctuation(text):
    return text.translate(str.maketrans('', '', PUNCT_TO_REMOVE))


def remove_stopwords(text):
    return " ".join([word for word in str(text).split() if word not in STOPWORDS])


def remove_unnecessary_characters(text):
    text = re.sub("[^a-zA-Z ]+", "", text)
    text = re.sub(r'[^\w\s]', '', text)
    text = re.sub("^ *", "", text)
    text = re.sub("\n", " ", text)
    text = re.sub(' {2,}', ' ', text)
    text = re.sub("\[.*\]", " ", text)
    text = re.sub("\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}", " ", text)
    text = re.sub(r"\?", " ", text)
    return text


def preprocessing_pipeline(text):
    text = to_lower(text)
    text = remove_unnecessary_characters(text)
    text = remove_url(text)
    text = remove_punctuation(text)
    text = remove_stopwords(text)
    return text


PROCESSED_DOCUMENTS = [preprocessing_pipeline(doc) for doc in documents]

DICTIONARY_OF_DOCUMENTS = []

for doc in PROCESSED_DOCUMENTS:
    DICTIONARY_OF_DOCUMENTS = DICTIONARY_OF_DOCUMENTS + doc.split()

Counter = Counter(DICTIONARY_OF_DOCUMENTS)

most_occur = Counter.most_common(100)

inverted_indexes = []


def log2(x): return log(x, 2)


def vb_encode(number):
    bytes = []
    while True:
        bytes.insert(0, number % 128)
        if number < 128:
            break
        number /= 128
    bytes[-1] += 128
    return pack('%dB' % len(bytes), *bytes)


def binary(x, l=1):
    fmt = '{0:0%db}' % l
    return fmt.format(x)


def unary(x):
    return x*'1'+'0'


def elias_generic(lencoding, x):
    if x == 0:
        return '0'

    l = 1+int(log2(x))
    a = x - 2**(int(log2(x)))

    k = int(log2(x))

    return lencoding(l) + binary(a, k)


def elias_gamma(x):
    return elias_generic(unary, x)


def elias_delta(x):
    return elias_generic(elias_gamma, x)


for index, doc in enumerate(PROCESSED_DOCUMENTS):
    for word_pair in most_occur:
        word = word_pair[0]
        counter = doc.count(word)
        if(counter == 0):
            continue
        inverted_indexes.append([word, WEBSITE_LIST[index], counter])

print("ELIAS GAMMA ENCODING\n\n")

elias_gamma_list = []
for inv_index in inverted_indexes:
    currentList = [inv_index[0], inv_index[1], elias_gamma(inv_index[2])]
    elias_gamma_list.append(currentList)

print(tabulate(elias_gamma_list[:50], headers=[
      'Token', 'Document', 'Count'], tablefmt='orgtbl'))

print("\n\nELIAS DELTA ENCODING\n\n")

elias_delta_list = []
for inv_index in inverted_indexes:
    currentList = [inv_index[0], inv_index[1], elias_delta(inv_index[2])]
    elias_delta_list.append(currentList)

print(tabulate(elias_delta_list[:50], headers=[
      'Token', 'Document', 'Count'], tablefmt='orgtbl'))

print("\n\nVARIABLE BYTE ENCODING\n\n")

vb_list = []
for inv_index in inverted_indexes:
    bytestream = vb_encode(inv_index[2])
    vb_string = ''.join([format(b, '08b')
                         for b in unpack('%dB' % len(bytestream), bytestream)])
    currentList = [inv_index[0], inv_index[1], vb_string]
    vb_list.append(currentList)

print(tabulate(vb_list[:50], headers=[
      'Token', 'Document', 'Count'], tablefmt='orgtbl'))
