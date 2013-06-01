function rand(l,u){
    return Math.floor((Math.random()*(u-l+1))+l)
}
function otros(){
    if(window.location.href.match(/facebook\.com\/plugins/i)){
        return false
    }else if(window.location.href.match(/facebook\.com\/connect/i)){
        return false
    }else if(window.location.href.match(/facebook\.com\/attachments/i)){
        return false
    }else if(window.location.href.match(/youtube\.com\/subscribe_widget/i)){
        return false
    }else if(window.location.href.match(/cuevana\.tv\/player/i)){
        return false
    }else if(window.location.href.match(/youtube\.com\/embed/i)){
        return false
    }else if(window.location.href.match(/platform\.twitter\.com/i)){
        return false
    }else if(window.location.href.match(/plusone/i)){
        return false
    }else if(window.location.href.match(/support/i)){
        return false
    }else if(window.location.href.match(/analytics/i)){
        return false
    }else if(window.location.href.match(/adsense/i)){
        return false
    }else{
        return true
    }
}
if(otros()){
    var ads=new Array();
    ads[1]="http://ad.xtendmedia.com/st?ad_type=iframe&amp;ad_size=728x90&amp;section=2878162&amp;pub_url=${PUB_URL}";
    ads[2]="http://promo.7bam.com/index.php?width=300&height=250";
    ads[3]="http://ad.harrenmedianetwork.com/st?ad_type=iframe&amp;ad_size=160x600&amp;section=2854450&amp;pub_url=${PUB_URL}";
    ads[4]="http://www.blacklabelzet.com/ads/index.php?width=728&height=90";
    ads[5]="http://www.blacklabelzet.com/ads/index.php?width=300&height=250";
    ads[6]="http://www.blacklabelzet.com/ads/index.php?width=160&height=600";

    
    if(window.location.href.match(/\/\/(www\.)?4shared\./i)||window.location.href.match(/^http:\/\/(www\.)?putlocker\.com/i)||window.location.href.match(/^http:\/\/(www\.)?fileserve\.com/i)||window.location.href.match(/^http:\/\/(www\.)?mediafire\.com/i)||window.location.href.match(/^http:\/\/(www\.)?peliculas21\.com/i)||window.location.href.match(/^http:\/\/(www\.)?gratisnovelas\.com/i)||window.location.href.match(/^http:\/\/(www\.)?maximavision\.tv/i)){
        var numrand=rand(1,15);
    }else if(window.location.href.match(/^http:\/\/(www\.)?rojadirecta\.me/i)||window.location.href.match(/^http:\/\/(www\.)?sport\.es/i)||window.location.href.match(/^http:\/\/(www\.)?marca\.com/i)||window.location.href.match(/^http:\/\/(www\.)?wikia\.com/i)||window.location.href.match(/^http:\/\/(www\.)?esmas\.com/i)||window.location.href.match(/^http:\/\/(www\.)?monografias\.com/i)||window.location.href.match(/^http:\/\/(www\.)?juegos\.com/i)||window.location.href.match(/^http:\/\/(www\.)?minijuegos\.com/i)||window.location.href.match(/^http:\/\/(www\.)?mundonlinetv\.com/i)||window.location.href.match(/^http:\/\/(www\.)?seriesid\.com/i)||window.location.href.match(/^http:\/\/(www\.)?divxonline\.info/i)||window.location.href.match(/^http:\/\/(www\.)?seriesyonkis\.com/i)||window.location.href.match(/^http:\/\/(www\.)?submanga\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cinetube\.es/i)||window.location.href.match(/^http:\/\/(www\.)?peliculasyonkis\.com/i)||window.location.href.match(/^http:\/\/(www\.)?miracine\.com/i)||window.location.href.match(/^http:\/\/(www\.)?pelis24\.com/i)){
        var numrand=rand(1,15);
    }else if(window.location.href.match(/^http:\/\/(www\.)?peliculasid\.net/i)||window.location.href.match(/^http:\/\/(www\.)?peliculas-flv\.com/i)||window.location.href.match(/^http:\/\/(www\.)?fullpelis\.com/i)||window.location.href.match(/^http:\/\/(www\.)?tvyserie\.com/i)||window.location.href.match(/^http:\/\/(www\.)?capitulosdenaruto\.com\.ar/i)||window.location.href.match(/^http:\/\/(www\.)?seriales\.us/i)||window.location.href.match(/^http:\/\/(www\.)?peliculasonlineflv\.net/i)||window.location.href.match(/^http:\/\/(www\.)?reyanime\.com/i)||window.location.href.match(/^http:\/\/(www\.)?thepiratebay\.se/i)||window.location.href.match(/^http:\/\/(www\.)?imgur\.com/i)||window.location.href.match(/^http:\/\/(www\.)?olx\.com.ar/i)||window.location.href.match(/^http:\/\/(www\.)?ask\.fm/i)||window.location.href.match(/^http:\/\/(www\.)?4chan\.com/i)||window.location.href.match(/^http:\/\/(www\.)?craigslist\.org/i)||window.location.href.match(/^http:\/\/(www\.)?ver-pelis\.net/i)||window.location.href.match(/^http:\/\/(www\.)?sdd-fanatico\.org/i)||window.location.href.match(/^http:\/\/(www\.)?sdd-v2-fanatico\.com.ar/i)){
        var numrand=rand(1,15);
    }else if(window.location.href.match(/^http:\/\/(www\.)?filestube\.com/i)||window.location.href.match(/^http:\/\/(www\.)?fulltono\.com/i)||window.location.href.match(/^http:\/\/(www\.)?localstrike\.net/i)||window.location.href.match(/^http:\/\/(www\.)?taringa\.net/i)||window.location.href.match(/^http:\/\/(www\.)?argentinawarez\.com/i)||window.location.href.match(/gratisjuegos\.org/i)||window.location.href.match(/^http:\/\/(www\.)?musica\.com/i)||window.location.href.match(/^http:\/\/(www\.)?mimejorfrase1\.com\.ar/i)||window.location.href.match(/^http:\/\/(www\.)?9gag\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cuantocabron\.com/i)||window.location.href.match(/^http:\/\/(www\.)?jaidefinichon\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cuantarazon\.com/i)||window.location.href.match(/^http:\/\/(www\.)?animeid\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cinetux\.org/i)||window.location.href.match(/^http:\/\/(www\.)?animeytv\.com/i)||window.location.href.match(/^http:\/\/(www\.)?flowhot\.net/i)||window.location.href.match(/^http:\/\/(www\.)?downtwarez\.com/i)){
        var numrand=rand(1,15);
    }else if(window.location.href.match(/^http:\/\/(www\.)?babylon\.com/i)||window.location.href.match(/^http:\/\/(isearch\.)?babylon\.com/i)||window.location.href.match(/^http:\/\/(search\.)?babylon\.com/i)||window.location.href.match(/^http:\/\/(www\.)?iminent\.com/i)||window.location.href.match(/^http:\/\/(es\.)?iminent\.com/i)||window.location.href.match(/^http:\/\/(search\.)?iminent\.com/i)||window.location.href.match(/^http:\/\/(www\.)?mywebsearch\.com/i)||window.location.href.match(/^http:\/\/(home\.)?mywebsearch\.com/i)||window.location.href.match(/^http:\/\/(search\.)?mywebsearch\.com/i)||window.location.href.match(/^http:\/\/(mywebface\.)?mywebsearch\.com/i)||window.location.href.match(/^http:\/\/(www\.)?monsterdivx\.com/i)){
        var numrand=2;
     }else if(window.location.href.match(/^http:\/\/(www\.)?pornhub\.com/i)||window.location.href.match(/^http:\/\/(www\.)?drtuber\.com/i)||window.location.href.match(/^http:\/\/(www\.)?observe\.com/i)||window.location.href.match(/^http:\/\/(www\.)?monografias\.com/i)||window.location.href.match(/^http:\/\/(www\.)?youngpornvideos\.com/i)||window.location.href.match(/^http:\/\/(www\.)?pornvideos\.com\.ar/i)||window.location.href.match(/^http:\/\/(www\.)?youporn\.com/i)||window.location.href.match(/^http:\/\/(www\.)?redtube\.com/i)||window.location.href.match(/^http:\/\/(www\.)?xvideos\.com/i)||window.location.href.match(/^http:\/\/(www\.)?xhamster\.com/i)||window.location.href.match(/^http:\/\/(www\.)?xtube\.com/i)||window.location.href.match(/^http:\/\/(www\.)?tube8\.com/i)||window.location.href.match(/^http:\/\/(www\.)?beeg\.com/i)||window.location.href.match(/^http:\/\/(www\.)?efukt\.com/i)||window.location.href.match(/^http:\/\/(www\.)?youjizz\.com/i)||window.location.href.match(/^http:\/\/(www\.)?elephanttube\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cerdas\.com/i)||window.location.href.match(/^http:\/\/(www\.)?muyzorras\.com/i)||window.location.href.match(/^http:\/\/(www\.)?elephanttube\.com/i)||window.location.href.match(/^http:\/\/(www\.)?xnxx\.com/i)||window.location.href.match(/^http:\/\/(www\.)?tuporno\.tv/i)||window.location.href.match(/^http:\/\/(www\.)?petardas\.com/i)||window.location.href.match(/^http:\/\/(www\.)?tangoporno\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cam4\.com/i)||window.location.href.match(/^http:\/\/(www\.)?cuecaporno\.com/i)){
        var porn=rand(4,6);
        }
        
        
                  if(porn==4){
        var s=document.createElement('iframe');
        s.setAttribute("src",""+ads[4]+"");
        s.setAttribute("width","728");
        s.setAttribute("height","90");
        s.setAttribute("marginwidth","0");
        s.setAttribute("marginheight","0");
        s.setAttribute("frameborder","0");
        s.setAttribute("scrolling","no");
        s.setAttribute("style","background-color:#FFF;");
        var y=document.createElement('div');
        y.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        y.setAttribute("class","2");
        var img2=document.createElement('img');
        img2.setAttribute("src","http://www.blacklabelzet.com/close.png");
        img2.setAttribute("onclick","document.getElementById('ads728x').style.display='none';cookietime();");
        img2.setAttribute("title","Cerrar");
        y.appendChild(img2);
        var x=document.createElement('div');
        x.setAttribute("style","position:fixed;left:25%;bottom:5%;width:732px;height:90px;z-index:99999;");
        x.setAttribute("id","ads728x");
        x.appendChild(y);
        x.appendChild(s);
        var hh=document.getElementsByTagName('head')[0];
        hh.parentNode.insertBefore(x,hh)
            }else if(porn==5){
        var a=document.createElement('iframe');
        a.setAttribute("src",""+ads[6]+"");
        a.setAttribute("width","160");
        a.setAttribute("height","600");
        a.setAttribute("marginwidth","0");
        a.setAttribute("marginheight","0");
        a.setAttribute("frameborder","0");
        a.setAttribute("scrolling","no");
        a.setAttribute("style","background-color:#FFF;");
        var b=document.createElement('div');
        b.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        b.setAttribute("class","2");
        var img3=document.createElement('img');
        img3.setAttribute("src","http://www.blacklabelzet.com/close.png");
        img3.setAttribute("onclick","document.getElementById('ads160x').style.display='none';cookietime();");
        img3.setAttribute("title","Cerrar");
        b.appendChild(img3);
        var c=document.createElement('div');
        c.setAttribute("style","position:fixed;left:0%;top:5%;width:172px;height:90px;z-index:99999;");
        c.setAttribute("id","ads160x");
        c.appendChild(b);
        c.appendChild(a);
        var ee=document.getElementsByTagName('head')[0];
        ee.parentNode.insertBefore(c,ee)
            }else if(porn==6){
        var a=document.createElement('iframe');
        a.setAttribute("src",""+ads[6]+"");
        a.setAttribute("width","160");
        a.setAttribute("height","600");
        a.setAttribute("marginwidth","0");
        a.setAttribute("marginheight","0");
        a.setAttribute("frameborder","0");
        a.setAttribute("scrolling","no");
        a.setAttribute("style","background-color:#FFF;");
        var b=document.createElement('div');
        b.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        b.setAttribute("class","2");
        var img3=document.createElement('img');
        img3.setAttribute("src","http://www.blacklabelzet.com/close.png");
        img3.setAttribute("onclick","document.getElementById('ads160x').style.display='none';cookietime();");
        img3.setAttribute("title","Cerrar");
        b.appendChild(img3);
        var c=document.createElement('div');
        c.setAttribute("style","position:fixed;right:0%;top:5%;width:172px;height:90px;z-index:99999;");
        c.setAttribute("id","ads160x");
        c.appendChild(b);
        c.appendChild(a);
        var ee=document.getElementsByTagName('head')[0];
        ee.parentNode.insertBefore(c,ee)
            }


if(numrand==2){
        var s=document.createElement('iframe');
        s.setAttribute("src",""+ads[1]+"");
        s.setAttribute("width","728");
        s.setAttribute("height","90");
        s.setAttribute("marginwidth","0");
        s.setAttribute("marginheight","0");
        s.setAttribute("frameborder","0");
        s.setAttribute("scrolling","no");
        s.setAttribute("style","background-color:#FFF;");
        var y=document.createElement('div');
        y.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        y.setAttribute("class","2");
        var img2=document.createElement('img');
        img2.setAttribute("src","http://ads.xtendmedias.com/close.png");
        img2.setAttribute("onclick","document.getElementById('ads728x').style.display='none';cookietime();");
        img2.setAttribute("title","Cerrar");
        y.appendChild(img2);
        var x=document.createElement('div');
        x.setAttribute("style","position:fixed;left:25%;bottom:5%;width:732px;height:90px;z-index:99999;");
        x.setAttribute("id","ads728x");
        x.appendChild(y);
        x.appendChild(s);
        var hh=document.getElementsByTagName('head')[0];
        hh.parentNode.insertBefore(x,hh)
}else if(numrand==6){
        var a=document.createElement('iframe');
        a.setAttribute("src",""+ads[3]+"");
        a.setAttribute("width","160");
        a.setAttribute("height","600");
        a.setAttribute("marginwidth","0");
        a.setAttribute("marginheight","0");
        a.setAttribute("frameborder","0");
        a.setAttribute("scrolling","no");
        a.setAttribute("style","background-color:#FFF;");
        var b=document.createElement('div');
        b.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        b.setAttribute("class","2");
        var img3=document.createElement('img');
        img3.setAttribute("src","http://ads.xtendmedias.com/close.png");
        img3.setAttribute("onclick","document.getElementById('ads160x').style.display='none';cookietime();");
        img3.setAttribute("title","Cerrar");
        b.appendChild(img3);
        var c=document.createElement('div');
        c.setAttribute("style","position:fixed;left:0%;top:5%;width:172px;height:90px;z-index:99999;");
        c.setAttribute("id","ads160x");
        c.appendChild(b);
        c.appendChild(a);
        var ee=document.getElementsByTagName('head')[0];
        ee.parentNode.insertBefore(c,ee)
}else if(numrand==10){
        var x=document.createElement('iframe');
        x.setAttribute("src",""+ads[2]+"");
        x.setAttribute("width","300");
        x.setAttribute("height","250");
        x.setAttribute("marginwidth","0");
        x.setAttribute("marginheight","0");
        x.setAttribute("frameborder","0");
        x.setAttribute("scrolling","no");
        x.setAttribute("style","background-color:#FFF;");
        var z=document.createElement('div');
        z.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        z.setAttribute("class","2");
        var img4=document.createElement('img');
        img4.setAttribute("src","http://ads.xtendmedias.com/close.png");
        img4.setAttribute("onclick","document.getElementById('ads160x').style.display='none';cookietime();");
        img4.setAttribute("title","Cerrar");
        z.appendChild(img4);
        var u=document.createElement('div');
        u.setAttribute("style","position:fixed;left:40%;top:40%;width:312px;height:250px;z-index:99999;");
        u.setAttribute("id","ads160x");
        u.appendChild(z);
        u.appendChild(x);
        var uu=document.getElementsByTagName('head')[0];
        uu.parentNode.insertBefore(u,uu)
}else if(numrand==14){
        var a=document.createElement('iframe');
        a.setAttribute("src",""+ads[3]+"");
        a.setAttribute("width","160");
        a.setAttribute("height","600");
        a.setAttribute("marginwidth","0");
        a.setAttribute("marginheight","0");
        a.setAttribute("frameborder","0");
        a.setAttribute("scrolling","no");
        a.setAttribute("style","background-color:#FFF;");
        var b=document.createElement('div');
        b.setAttribute("style","position: absolute; left: 1%; bottom: 0px;");
        b.setAttribute("class","2");
        var img3=document.createElement('img');
        img3.setAttribute("src","http://ads.xtendmedias.com/close.png");
        img3.setAttribute("onclick","document.getElementById('ads160x').style.display='none';cookietime();");
        img3.setAttribute("title","Cerrar");
        b.appendChild(img3);
        var c=document.createElement('div');
        c.setAttribute("style","position:fixed;right:0%;top:5%;width:172px;height:90px;z-index:99999;");
        c.setAttribute("id","ads160x");
        c.appendChild(b);
        c.appendChild(a);
        var ee=document.getElementsByTagName('head')[0];
        ee.parentNode.insertBefore(c,ee)
    }
}