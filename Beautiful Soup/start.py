from bs4 import BeautifulSoup

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

soup = BeautifulSoup(html_doc, 'html.parser')
# print(soup.prettify()) 
# ***** Prints the entire document

# print(soup.title) 
# *** <title> ........ </title>

# print(soup.title.name)  
# *** Prints title

# print(soup.title.string) 
# *** Prints the title of the document

# print(soup.prettify())

# print(soup.a)   
# ******** Returned the first occurence of a

# print(soup.find_all('a')) 
# *** Returns all occurence of a

# print(soup.find(id='link3'))
# Get the tag having id = link3

# print(soup.title.parent.name)
# Get the parent of the tag title

# print(soup.a.string)
# Get the string enclosed between the first tags

# print(soup.find_all('a')[0].string)
# find_all returns a list of all matching cases

# print(soup.a.parent.string)

# for link in soup.find_all('a'):
#     print(link.get('href'))

# To get all the links starting with a tag

# print(soup.get_text())
# Get the text of the html_doc