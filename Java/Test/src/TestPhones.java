class TestPhones {
    public static void main(String[] args) {
        //12.（1）创建一个手机类Phones，定义操作系统（os）和类型（type）属性，构造方法，一系列GET/SET方法及打电话方法call（）。
        //（2）创建两个子类：苹果手机Iphone 和windows手机类Wphone，并在各自类中重写方法call（）；在WPhone类中定义特有成员方法playMusic（）。
        //（3）创建主类TestPhones，编写程序入口main（）
        // 方法中采用类型多态行实现两种手机打电话，定义一个Phones类的引用，先实现IPhone打电话，再修改代码实现WPhone打电话。
        //结果如下：
        Phone phone = new Iphone();
        phone.call();
        phone = new Wphone();
        phone.call();
    }

}

class Iphone extends Phone {
    @Override
    void call() {
        System.out.println("IPhone8.0打电话");
    }
}

class Wphone extends Phone {
    @Override
    void call() {
        System.out.println("WPhone7.5打电话");
    }

    void playMusic() {
        System.out.println("WPhone播放xbox Music");
    }
}

class Phone {
    String os;
    String type;

    public String getOs() {
        return os;
    }

    public void setOs(String os) {
        this.os = os;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    void call() {
        System.out.println("我用手机打电话");
    }

}
