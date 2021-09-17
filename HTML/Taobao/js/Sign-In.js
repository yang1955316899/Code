var passwords_arr = new Array(100);
var phones_arr = new Array(100);
var used = 0;
window.addEventListener('DOMContentLoaded', function () {
    function GetQueryString(name) {
        var reg = new RegExp("(^|&)" + name + "=([^&]*)(&|$)", "i");
        var r = window.location.search.substr(1).match(reg);
        if (r != null) return (r[2]); return null;
    }
    var phone = GetQueryString("phone");
    var password = GetQueryString("password")
    if (phone != null && password != null) {
        phones_arr[used] = decodeURIComponent(phone);
        passwords_arr[used] = decodeURIComponent(password);
        used++;
    }
    //表单验证
    var phone_input = document.querySelector('.phone');
    var password_input = document.querySelector('.password');
    var btn = document.querySelector('.submit');
    var error = document.querySelector('.error');

    btn.addEventListener('click', function () {
        if (phone_input.value.length >= 0 && phone_input.value.length < 11) {
            error.style.visibility = 'visible';
            error.innerHTML = '请输入正确的手机号';
        } else if (password_input.value.length == 0) {

            error.style.visibility = 'visible';
            error.innerHTML = '请输入密码';
        } else {
            for (let index = 0; index < used; index++) {
                if (phones_arr[index] == phone_input.value && passwords_arr[index] == password_input.value) {
                    document.querySelector('#form').submit();
                }
            }
            error.style.visibility = 'visible';
            error.innerHTML = '密码不正确';
        }
    })
})