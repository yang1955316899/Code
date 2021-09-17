window.addEventListener('DOMContentLoaded', function () {
    //下拉菜单栏

    function display(elemt) {
        elemt.addEventListener('mouseover', function () {
            elemt.querySelector('ul').style.display = 'block';
        })
        elemt.addEventListener('mouseleave', function () {
            elemt.querySelector('ul').style.display = 'none';
        })
    }
    var global = document.querySelector('.global');
    display(global);
    var mytaobao = document.querySelector('.mytaobao');
    display(mytaobao);
    var star = document.querySelector('.star');
    display(star);
})