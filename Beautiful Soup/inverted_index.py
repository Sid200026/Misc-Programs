import requests
from bs4 import BeautifulSoup
import warnings
import re
import string
from collections import Counter
from tabulate import tabulate

warnings.filterwarnings("ignore")

STOPWORDS = ['ourselves', 'hers', 'between', 'yourself', 'but', 'again', 'there', 'about', 'once', 'during', 'out', 'very', 'having', 'with', 'they', 'own', 'an', 'be', 'some', 'for', 'do', 'its', 'yours', 'such', 'into', 'of', 'most', 'itself', 'other', 'off', 'is', 's', 'am', 'or', 'who', 'as', 'from', 'him', 'each', 'the', 'themselves', 'until', 'below', 'are', 'we', 'these', 'your', 'his', 'through', 'don', 'nor', 'me', 'were', 'her', 'more', 'himself', 'this', 'down', 'should', 'our', 'their', 'while',
             'above', 'both', 'up', 'to', 'ours', 'had', 'she', 'all', 'no', 'when', 'at', 'any', 'before', 'them', 'same', 'and', 'been', 'have', 'in', 'will', 'on', 'does', 'yourselves', 'then', 'that', 'because', 'what', 'over', 'why', 'so', 'can', 'did', 'not', 'now', 'under', 'he', 'you', 'herself', 'has', 'just', 'where', 'too', 'only', 'myself', 'which', 'those', 'i', 'after', 'few', 'whom', 't', 'being', 'if', 'theirs', 'my', 'against', 'a', 'by', 'doing', 'it', 'how', 'further', 'was', 'here', 'than']

WEBSITE_LIST = ["http://vit.ac.in/", "https://chennai.vit.ac.in/", "https://www.mit.edu/", "https://github.com/", "https://medium.com/",
                "https://towardsdatascience.com/", "https://www.geeksforgeeks.org/", "https://leetcode.com/", "https://www.codechef.com/", "https://www.hackerrank.com/"]
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

for index, doc in enumerate(PROCESSED_DOCUMENTS):
    for word_pair in most_occur:
        word = word_pair[0]
        counter = doc.count(word)
        if(counter == 0):
            continue
        inverted_indexes.append([word, WEBSITE_LIST[index], counter])

print(tabulate(inverted_indexes, headers=[
      'Token', 'Document', 'Count'], tablefmt='orgtbl'))
