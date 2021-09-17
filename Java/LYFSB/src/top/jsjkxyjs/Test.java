package top.jsjkxyjs;

public class Test {
    public static void main(String[] args) {
        Student student = new Student();
        student.eat();
    }
}

class Person {
    private String name;
    private int age;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    Person() {
    }

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void eat() {
        System.out.println("人都会吃饭");
    }
}

class Student extends Person {
    String className = "默认班级";

    public void Show() {
        System.out.println(className);
    }
    public void Show(String s) {
        System.out.println(s);
    }
}