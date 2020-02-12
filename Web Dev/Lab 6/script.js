const handleDateChange = () => {
    const date = document.forms["datePicker"]["dateInp"].valueAsDate.getDate();
    getNews(date);
}

const allNews = null;
const xhttp = new XMLHttpRequest();
xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      allNews = this.responseText;
    }
  };
  xhttp.open("GET", "allNews.json", true);
  xhttp.send();

const fetchNews = date => {
    for(news of allNews) {
        if (news.date === date) {
            return news;
        }
    }
    return null;
}

const getNews = (date=new Date().getDate()) => {
    let news = fetchNews(date);
    if(!news) {
        alert("No news for the given date");
        getNews();
        return;
    }
    news = news.news;
    const lh = document.getElementsByClassName("lh")[0];
    const ll = document.getElementsByClassName("ll")[0];
    const li = document.getElementsByClassName("li")[0];
    const lt = document.getElementsByClassName("lt")[0];
    ll.href=news.left.href;
    lh.innerHTML = news.left.headline;
    li.src = news.left.img;
    lt.innerHTML = news.left.text;
    const rh = document.getElementsByClassName("rh")[0];
    const rl = document.getElementsByClassName("rl")[0];
    const ri = document.getElementsByClassName("ri")[0];
    const rt = document.getElementsByClassName("rt")[0];
    rl.href=news.right.href;
    rh.innerHTML = news.right.headline;
    ri.src = news.right.img;
    rt.innerHTML = news.right.text;
    const mh = document.getElementsByClassName("mh")[0];
    const ml = document.getElementsByClassName("ml")[0];
    const mi = document.getElementsByClassName("mi")[0];
    const mt1 = document.getElementsByClassName("mt1")[0];
    const mt2 = document.getElementsByClassName("mt2")[0];
    ml.href=news.middle.href;
    mh.innerHTML = news.middle.headline;
    mi.src = news.middle.img;
    mt1.innerHTML = news.middle.text1;
    mt2.innerHTML = news.middle.text2;
}

const leftClose = () => {
    document.querySelector("#left").style.display = 'none';
}

const rightClose = () => {
    document.querySelector("#right").style.display = 'none';
}