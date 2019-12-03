website = r"https://github.com/"
from requests import Session
from bs4 import BeautifulSoup as bs
 
with Session() as s:
    site = s.get(website)
    soup = bs(site.content, "lxml")
    print(soup.prettify())
