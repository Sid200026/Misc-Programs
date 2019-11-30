from bs4 import BeautifulSoup

html_doc = "<p class='temp'>Hi</p>"
soup = BeautifulSoup(html_doc, 'lxml')
# print(soup.get_text())
# print(soup.name)
soup.find(text="Hi").replace_with("No")
print(soup.prettify())