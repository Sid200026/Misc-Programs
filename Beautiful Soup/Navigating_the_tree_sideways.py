from bs4 import BeautifulSoup
sibling_soup = BeautifulSoup("<a><b>text1</b><c>text2</c></b></a>", 'lxml')
# print(sibling_soup.prettify())
# print(sibling_soup.b.next_sibling)
# print(sibling_soup.c.previous_sibling)

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
soup = BeautifulSoup(html_doc, 'lxml')

# print(soup.prettify())

# for next in soup.a.next_siblings:
#     print(next)

# for prev in soup.find(id='link3').previous_siblings:
#     print(prev)

# print(soup.a.next_element)
# print(soup.a.next_sibling)

