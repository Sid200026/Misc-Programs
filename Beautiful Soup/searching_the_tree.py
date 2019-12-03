html_doc = """
<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title"><b>The Dormouse's story</b></p>

<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>

<p class="story">...</p>
"""

from bs4 import BeautifulSoup
import re
soup = BeautifulSoup(html_doc, 'lxml')

# print(soup.find_all('a'))
# for i in soup.find_all(re.compile("t")):
#     print(i.name)

# for i in soup.find_all(['a', 'b', 'h']):
#     print(i)

# for i in soup.find_all(True):
# 	print(i.name)

# def class_but_no_id(tag):
#     return tag.has_attr('class') and not tag.has_attr('id')

# print(soup.find_all(class_but_no_id))

a_string = soup.find(string="Tillie")
# print(a_string.parent)
# print(a_string.find_parent('p'))
# print(a_string.find_parents('p'))