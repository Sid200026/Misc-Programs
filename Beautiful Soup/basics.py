from bs4 import BeautifulSoup

soup = BeautifulSoup("<h1 class='hi classname' id='notnice' notsensitive=False>Hello World</h1>", "lxml", multi_valued_attributes = None)
# print(soup)
# h1tag = soup.find_all('h1')[0]
# print(h1tag)
# print(h1tag.name)
# print(type(h1tag))
# print(h1tag)
# print(h1tag.attrs) # Get all tags
# print(h1tag['id']) # Get an individual tag
# # h1tag['id'] = 'nice'
# # h1tag.attrs.pop('class')
# # del h1tag['id']
# # css_soup = BeautifulSoup('<p id="myclass"></p>', 'lxml')
# # print(css_soup.p['id'])
# # # ["body"]
# h1tag['class'] = ['sid','singha','roy']
# print(h1tag)
# print(h1tag['class'])

h1tag = soup.find_all('h1')[0]
print(h1tag['class'])
print(h1tag.get_attribute_list('id'))