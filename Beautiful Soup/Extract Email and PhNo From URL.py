from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from time import sleep
from bs4 import BeautifulSoup
import re
import sys
from datetime import datetime

PHONE_NUMBER_REGEX = re.compile(
    r"(\d{3}[-\.\s]??\d{3}[-\.\s]??\d{4}|\(\d{3}\)\s*\d{3}[-\.\s]??\d{4}|\d{3}[-\.\s]??\d{4})")

EMAIL_REGEX = re.compile(
    r'([a-zA-Z0-9+._-]+@[a-zA-Z0-9._-]+\.[a-zA-Z0-9_-]+)', re.IGNORECASE)


class SeleniumDriver:
    options = Options()

    def __init__(self) -> None:
        self.options.add_argument('--headless')
        self.driver = webdriver.Chrome(options=self.options)

    def get_page_source(self, url):
        self.driver.get(url)
        htmlSource = self.driver.page_source
        soup = BeautifulSoup(htmlSource, "lxml")
        return soup.get_text()


sel_driver = SeleniumDriver()
page_text = (sel_driver.get_page_source(
    'https://vit.ac.in/contactus'))

print("Email Addresses\n")
[print(x.group()) for x in re.finditer(EMAIL_REGEX, page_text)]

print("\nPhone Numbers\n")
[print(x.group()) for x in re.finditer(PHONE_NUMBER_REGEX, page_text)]
