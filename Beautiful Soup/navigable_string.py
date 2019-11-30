from bs4 import BeautifulSoup

soup = BeautifulSoup('<p class="nice">Helloooo</p>', 'lxml')
print(soup.prettify())
ptag = soup.find_all('p')[0]
# print(ptag.string) # Navigable String 
# print(type(ptag.string)) 
# # ptag.string  = "Meeee"
# # OR
# ptag.string.replace_with('Hilo')
# print(ptag)
u = str(ptag.string)
print(u)
u = "Noo"
print(ptag)