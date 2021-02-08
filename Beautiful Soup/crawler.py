"""
Given a root URL, e.g., "Vit.ac.in", Design a simple crawler using Python to return all pages that contains a string "admissions" from this site.
"""

# from bs4 import BeautifulSoup
# import requests
# from collections import deque
# import re
# import warnings

# warnings.filterwarnings("ignore")

# regex = re.compile(r'^https://vit.ac.in/', re.IGNORECASE)


# ROOT_URL = "https://vit.ac.in/"
# already_visited = []
# q = deque()
# result = []


# def extractPage(URL):
#     print(URL)
#     if(re.match(regex, URL) is not None):
#         page = requests.get(URL, verify=False)
#         if(page.status_code == 200):
#             soup = BeautifulSoup(page.text, 'lxml')
#             all_tags = soup.find_all('a')
#             if('admissions' in soup.get_text()):
#                 result.append(URL)
#             for tag in all_tags:
#                 if not tag.has_attr('href'):
#                     continue
#                 tagURL = tag['href']
#                 if(re.match(regex, tagURL) is not None and 'static' not in tagURL and 'asset' not in tagURL and 'files' not in tagURL):
#                     if(tagURL in already_visited):
#                         continue
#                     q.append(tagURL)
#                     already_visited.append(tagURL)


# q.append(ROOT_URL)
# while(q):
#     try:
#         extractPage(q.popleft())
#     except:
#         pass

# print('URLS containing the word "admissions"')
# for urlAdm in result:
#     print(urlAdm)


"""
Find documents that contain the word Data and the word analytics within the URL “vit.ac.in” using Python.
"""


# import re
# from bs4 import BeautifulSoup
# import requests
# import warnings
# warnings.filterwarnings("ignore")
# regex = re.compile(r'^https://vit.ac.in/', re.IGNORECASE)

# ROOT_URL = "https://vit.ac.in/"

# print('Documents containing the words "data" and "analytic"')
# page = requests.get(ROOT_URL, verify=False)
# if(page.status_code == 200):
#     soup = BeautifulSoup(page.text, 'lxml')
#     if ('data' in soup.get_text() or 'Data' in soup.get_text()) and ('analytic' in soup.get_text() or 'Analytic' in soup.get_text()):
#         print(ROOT_URL)
#     for tag in soup.find_all('a'):
#         if not tag.has_attr('href'):
#             continue
#         tagURL = tag['href']
#         if(re.match(regex, tagURL) is not None):
#             sub_page = requests.get(tagURL, verify=False)
#             if(sub_page.status_code == 200):
#                 sub_soup = BeautifulSoup(sub_page.text, 'lxml')
#                 all_texts = sub_soup.get_text()
#                 if ('data' in all_texts or 'Data' in all_texts) and ('analytic' in all_texts or 'Analytic' in all_texts):
#                     print(tagURL)


"""
Find documents that contain the word Programme, but not the word programming within the URL “Vit.ac.in” using Python
"""

# import re
# from bs4 import BeautifulSoup
# import requests
# import warnings
# warnings.filterwarnings("ignore")
# regex = re.compile(r'^https://vit.ac.in/', re.IGNORECASE)

# ROOT_URL = "https://vit.ac.in/"

# print('Documents containing the words "programme" and not "programming"')
# page = requests.get(ROOT_URL, verify=False)
# if(page.status_code == 200):
#     soup = BeautifulSoup(page.text, 'lxml')
#     if ('programme' in soup.get_text() or 'Programme' in soup.get_text()) and ('programming' not in soup.get_text() and 'Programming' not in soup.get_text()):
#         print(ROOT_URL)
#     for tag in soup.find_all('a'):
#         if not tag.has_attr('href'):
#             continue
#         tagURL = tag['href']
#         if(re.match(regex, tagURL) is not None):
#             sub_page = requests.get(tagURL, verify=False)
#             if(sub_page.status_code == 200):
#                 sub_soup = BeautifulSoup(sub_page.text, 'lxml')
#                 all_texts = sub_soup.get_text()
#                 if ('programme' in all_texts or 'Programme' in all_texts) and ('programming' not in all_texts and 'Programming' not in all_texts):
#                     print(tagURL)