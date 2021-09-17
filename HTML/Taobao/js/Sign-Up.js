window.addEventListener('DOMContentLoaded', function () {
    var reg_tel = /^(13[0-9]|14[01456879]|15[0-35-9]|16[2567]|17[0-8]|18[0-9]|19[0-35-9])\d{8}$/;
    var reg_pass = /^(?![0-9]+$)(?![a-z]+$)(?![A-Z]+$)(?!([^(0-9a-zA-Z)])+$).{8,16}$/;
    var reg_password = new RegExp('(?=.*[0-9])(?=.*[a-zA-Z])(?=.*[^a-zA-Z0-9]).{8,30}');
    var phone = document.querySelector('.phone');
    var password = document.querySelector('.password');

    var btn = document.querySelector('.submit');
    var reg_phone = document.querySelector('.reg-phone');
    var reg_password = document.querySelector('.reg-password');
    window.addEventListener('keyup', function () {
        var flag = 1;
        if (phone.value.length == 0) {
            reg_phone.style.display = 'none';
            flag = 0;
        } else if (phone.value.length >= 0 && phone.value.length < 11 || phone.value.length > 11) {
            reg_phone.style.display = 'block';
            reg_phone.style.color = "red";
            reg_phone.innerHTML = "请输入您的手机号码（手机号码位数不对）！";
            flag = 0;
        } else if (reg_tel.test(phone.value)) {
            reg_phone.style.display = 'block';
            reg_phone.style.color = "green";
            reg_phone.innerHTML = "您的手机号输入正确！";
        } else {
            reg_phone.style.display = 'block';
            reg_phone.style.color = "red";
            reg_phone.innerHTML = "您输入的手机号有误（非中国大陆）！";
            flag = 0;
        }

        if (password.value.length == 0) {
            reg_password.style.display = 'none';
            flag = 0;
        } else if (password.value.length < 8 || password.value.length > 16) {
            reg_password.style.display = 'block';
            reg_password.style.color = 'red';
            reg_password.innerHTML = '请输入您的密码（密码长度8-16位）！';
            flag = 0;
        } else if (password.value.length >= 8 || password.value.length <= 16) {
            if (reg_pass.test(password.value)) {
                reg_password.style.display = 'block';
                reg_password.style.color = 'green';
                reg_password.innerHTML = '您的密码格式正确！';
            }
            else {
                reg_password.display = 'block';
                reg_password.style.color = 'red';
                reg_password.innerHTML = '密码包含数字,英文,字符中的两种以上！';
                flag = 0;
            }
        }
        if (flag) {
            btn.style.opacity = '1';
            btn.disabled = false;
        }
        else {
            btn.style.opacity = '.5';
            btn.disabled = true;
        }
    })

})