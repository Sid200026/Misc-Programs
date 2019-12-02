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
soup = BeautifulSoup(html_doc, 'lxml')

# print(soup.body.p)
# print(soup.a)
# print(soup.text)
# for textsoup in soup.find_all('a'):
#     print(textsoup)

# print(soup.html.contents[2].p)
# print(len(soup.html.contents))

# print(soup.head.contents)
# print(soup.head.contents[0])
titletag = soup.head.contents[0]
# print(titletag.contents)
# titletext = titletag.contents[0]
# print(titletext)

# print(soup.head.title.string)

# print(soup.contents)

# print(soup.body.children)

# # for child in soup.body.children: # Returns a NavigableString or a Tag or a comment
# #     # print(type(child))
# #     print(child)

# # for child in soup.body.descendants:
# #     print(child)

# print(len(list(soup.contents)))
# print(len(list(soup.descendants)))

# print(titletag.string)
# print(soup.head.string)
# print(soup.body.string)

# for string in soup.strings:
#     print(string)

for string in soup.stripped_strings:
    print(string)