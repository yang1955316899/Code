window.addEventListener('DOMContentLoaded', function () {
    function GetQueryString(name) {
        var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)", "i");
        var r = window.location.search.substr(1).match(reg);
        if (r != null) return (r[2]); return null;
    }
    var phone = GetQueryString("phone");
    if (phone == null) {
        phone = '请登录！';
    }
    document.querySelector('.uesrname').innerHTML = phone;
    document.querySelector('.hi').innerHTML = 'Hi!' + phone;
    //二维码关闭
    var top = document.querySelector('.top')
    var qr = top.querySelector('.qr');
    var close = qr.querySelector('.close');
    close.addEventListener('click', function () {
        qr.style.display = 'none';
    })
    //搜索框状态栏选择
    var search_nav_li = top.querySelector('.switchable-nav').querySelector('ul').querySelectorAll('li');
    for (var i = 0; i < search_nav_li.length; i++) {
        search_nav_li[i].addEventListener('click', function () {
            for (var temp = 0; temp < 3; temp++) {
                search_nav_li[temp].className = 'unselected font-12';
            }
            this.className = 'selected font-12 background-image-linear-gradient';
        })
    }
    //搜索框放大镜图标隐藏
    var search_input = top.querySelector('.search').querySelector('input');
    var search_span = top.querySelector('form').querySelector('span');
    search_input.addEventListener('keyup', function () {
        if (this.value == '') {
            search_span.innerHTML = '';
        }
        else {
            search_span.innerHTML = '';
        }
    })
    //右边栏精灵图填充
    var smallapp_icon = document.querySelector('.smallapp').querySelectorAll('span');
    for (var i = 0; i < smallapp_icon.length; i++) {
        // 让索引号 乘以 44 就是每个li 的背景y坐标  index就是我们的y坐标
        var index = i * 44;
        smallapp_icon[i].style.backgroundPosition = '0 -' + index + 'px';
    }

    //左边栏鼠标经过事件
    var ad_item = document.querySelector('.ad').querySelectorAll('li');
    var item_banner = document.querySelector('.item-banner');
    var item_banner_function = function () {
        var items = [
            '女装/内衣/家居',
            '女鞋/男鞋/箱包',
            '母婴/童装/玩具',
            '男装/运动户外',
            '美妆/彩妆/个护',
            '手机/数码/企业',
            '大家电/生活电器',
            '零食/生鲜/茶酒',
            '厨具/收纳/清洁',
            '家纺/家饰/鲜花',
            '图书音像/文具',
            '医药保健/进口',
            '汽车/二手车/用品',
            '房产/装修家具/建材',
            '手表/眼镜/珠宝饰品'
        ]
        if (this.getAttribute('item') - 1 != -1) {
            item_banner.innerHTML = items[this.getAttribute('item') - 1];
        }

        item_banner.style.display = 'block';
    }
    for (var temp = 0; temp < ad_item.length; temp++) {
        ad_item[temp].addEventListener('mouseover', item_banner_function);
        item_banner.addEventListener('mouseover', item_banner_function)
        ad_item[temp].addEventListener('mouseleave', function () {
            item_banner.style.display = 'none';
        })
        item_banner.addEventListener('mouseleave', function () {
            item_banner.style.display = 'none';
        })
    }

    //右侧导航条
    var wangwang = document.querySelector('.wangwang');
    var wangwang_li = wangwang.querySelectorAll('li');
    var search_fixed = document.querySelector('.search-fixed');
    function wangwang_li_selected(number) {
        for (let temp = 0; temp < 4; temp++) {
            wangwang_li[temp].className = '';
        }
        wangwang_li[number].className = 'wangwang-selected';
    }
    //解决定位问题

    window.addEventListener("scroll", function () {
        if (document.documentElement.scrollTop >= 399.44) {
            wangwang.style.position = 'fixed';
            wangwang.style.top = '75px';
        }
        else {
            wangwang.style.position = 'absolute';
            wangwang.style.right = 'calc(50vw - 665px)';
            wangwang.style.top = '474.44px';
        }
    })
    function search() {
        // 下翻显示搜索框
        if (document.documentElement.scrollTop >= 121) {
            search_fixed.style.display = 'block';
        } else {
            search_fixed.style.display = 'none';
        }
    }
    window.addEventListener("scroll", function () {
        search();
        if (document.documentElement.scrollTop >= 0 && document.documentElement.scrollTop <= 716) {
            wangwang_li_selected(0);
            wangwang_li[4].style.display = 'none';
        }
        if (document.documentElement.scrollTop >= 716 && document.documentElement.scrollTop <= 1074) {
            wangwang_li_selected(1);
            wangwang_li[4].style.display = 'block';
        }
        if (document.documentElement.scrollTop >= 1164 && document.documentElement.scrollTop <= 1459) {
            wangwang_li_selected(2);
        }
        if (document.documentElement.scrollTop >= 1459) {
            wangwang_li_selected(3);
        }
    })
    //天猫导航栏页码显示
    var tianmao_swiper_div = document.querySelector('.swiper-container-tianmao').querySelector('.swiper-wrapper').querySelectorAll('div');
    var pages = document.querySelector('.tianmao-img').querySelector('span');
    function page() {
        for (let temp = 0; temp < tianmao_swiper_div.length; temp++) {
            if (tianmao_swiper_div[temp].getAttribute('class').includes('swiper-slide-active')) {
                pages.innerHTML = tianmao_swiper_div[temp].getAttribute('aria-label');
            }
        }
    }
    page();
    for (var temp = 0; temp < tianmao_swiper_div.length; temp++) {
        setInterval(page, 100)
    }
    //用户信息新闻显示
    var police_news = document.querySelector('.police').querySelectorAll('li');
    var news = document.querySelector('.news').querySelector('a');
    for (let temp = 0; temp < police_news.length; temp++) {
        police_news[temp].addEventListener('mouseover', function () {
            news.innerHTML = this.innerHTML;
            for (let items = 0; items < police_news.length; items++) {
                police_news[items].className = '';
            }
            this.className = 'police_news';
        })
    }
})