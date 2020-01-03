import requests
from bs4 import BeautifulSoup as bs
import re
import sys

def parseByUsername():
    print("Enter the username\n")
    name = input()
    website = f"https://github.com/{name}"
    site = requests.get(website)
    if(site.status_code != 200):
        print("No such user exists")
        sys.exit()
    print("\n")
    soup = bs(site.content, "lxml")
    bio = soup.find('div', class_ = re.compile("p-note user-profile-bio js-user-profile-bio"))
    if bio is not None:
        res = ""
        for string in bio.strings:
            res = res + string.strip()
        print(f"Bio : {res}")
    contribs = soup.find('h2', class_=re.compile("text-normal mb-2"))
    if contribs is not None:
        string = 'Contributions : '
        for i in contribs.string.strip():
            if i=='\t' or i=='\n':
                continue
            else:
                if string[-1] == ' ' and i ==' ':
                    continue
                string = string+i
        print(string)
    website = r"https://github.com/{}?tab=repositories".format(name)
    site = requests.get(website)
    if(site.status_code != 200):
        print("No such user exists")
        sys.exit()
    print("\n")
    soup = bs(site.content, "lxml")
    print("\n")
    count = 0
    for repos in soup.find_all(itemprop="name codeRepository"):
        count = count + 1
        print(f"{str(count)}. {repos.string.strip()}\n")
        repoweb = r"https://github.com/{}".format(repos.attrs['href'])
        site = requests.get(repoweb)
        reposoup = bs(site.content, "lxml")
        detail = reposoup.find(itemprop='about')
        fork = reposoup.find('span', class_="fork-flag")
        if fork is not None:
            print(f"Project is Forked from {fork.a.attrs['href']}")
        if detail is not None:
            print(f"Description {detail.string.strip()}")
        else:
            print("Description: Not Provided")
        detail = reposoup.find_all(class_=re.compile("num text-emphasized"))
        print("\n")
        if detail is None:
            continue
        print(f"Commits : {detail[0].string.strip()}")
        print(f"Branches : {detail[1].string.strip()}")
        print(f"Packages : {detail[2].string.strip()}")
        print(f"Releases : {detail[3].string.strip()}")
        print("\nDo you want to download the project")
        print("Yes / No")
        choice = input()
        if choice.lower() == "yes" or choice.lower() == 'y':
            url = f'https://github.com/{name}/{repos.string.strip()}/archive/master.zip'
            r = requests.get(url, allow_redirects=True)
            open(f'{repos.string.strip()}.zip', 'wb').write(r.content)
        print("\n\n")

parseByUsername()