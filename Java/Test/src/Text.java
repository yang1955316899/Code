class Account {
    //编写Java应用程序。首先定义一个描述银行账户的Account类，包括成员变
    //量“账号”和“存款余额”，成员方法有“存款”、“取款”和“余额查询”。其次，
    //编写一个主类，在主类中测试Account类的功能。
    protected String AccountNumber;
    protected float balance;

    Account() {
        this("", 0);
    }

    Account(String Number, float balance) {
        AccountNumber = Number;
        this.balance = balance;
    }

    float desposit(float amout) {
        balance += amout;
        return balance;
    }

    float withdraw(float amout) {
        balance -= amout;
        return balance;
    }

    void show() {
        System.out.printf("账号:%s的余额是:%f", AccountNumber, balance);
    }
}

public class Text {
    public static void main(String[] args) {
        Account a1 = new Account("1000001", 2000f);
        a1.desposit(1000f);
        a1.withdraw(500f);
        a1.show();
    }
}
