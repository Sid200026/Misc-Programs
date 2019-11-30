from bs4 import BeautifulSoup

soup = BeautifulSoup("<h1 class='classname' id='notnice' notsensitive=False>Hello World</h1>", "lxml")
# print(soup)
h1tag = soup.h1
print(h1tag)
print(h1tag.name)
print(type(h1tag))
print(h1tag)
print(h1tag.attrs)
print(h1tag['id'])
h1tag['id'] = 'nice'
print(soup.prettify())