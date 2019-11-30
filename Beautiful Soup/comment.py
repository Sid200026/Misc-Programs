from bs4 import BeautifulSoup
markup = "<b><!--Hey, buddy. Want to buy a used parser?--></b>"
soup = BeautifulSoup(markup, 'lxml')
# print(soup.prettify())
# print(soup.b.string) # This returns a comment
# com = soup.b.string
# print(type(com))
print(soup.b.prettify())