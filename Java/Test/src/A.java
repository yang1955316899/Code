import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

import static java.lang.System.out;

public class A {
    //题目：判断101-200之间有多少个素数，并输出所有素数。
    //程序分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除， 则表明此数不是素数，反之是素数。
    public static void AA(String[] args) {
        int count = 0;
        for (int i = 101; i < 201; i++) {
            boolean b = false;
            for (int x = 2; x < i; x++) {
                if (i % x == 0) {
                    b = false;
                    break;
                } else {
                    b = true;
                }
            }
            if (b = true) {
                count++;
                out.println(i);
            }
        }
    }

    //题目：打印出所有的 "水仙花数 "，所谓 "水仙花数 "是指一个三位数，其各位数字立方和等于该数本身。
    // 例如：153是一个 "水仙花数 "，因为153=1的三次方＋5的三次方＋3的三次方。
    public static void BB(String[] args) {
        for (int i = 101; i < 1000; i++) {
            int g = i % 10;
            int s = i / 10 % 10;
            int b = i / 100;
            if (g * g * g + s * s * s + b * b * b == i) {
                out.println(i);
            }
        }
    }

    public static void CC(String[] args) {
        //利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        out.println(x >= 90 ? "A" : (x >= 60) ? "B" : "C");
    }

    public static void DD(String[] args) throws IOException {
        //编写程序，将字符串“你好，欢迎学习面向对象程序设计”写入到文件Hello.txt中。
        // FileWriter类或者BufferedWriter类）
        FileWriter file = new FileWriter(new File("Hello.txt"));
        String s = "你好，欢迎学习面向对象程序设计";
        byte[] b = s.getBytes();
        for (int i = 0; i < b.length; i++) {
            file.write(b[i]);
        }
        file.close();
    }

    //6、	编写一个Java程序在屏幕上输出1！+2！+3！+……+10！的和。（循环）
    public static void EE(String[] args) {
        int sum = 0;
        int jiechen = 1;
        for (int i = 2; i < 11; i++) {
            sum += jiechen;
            jiechen *= i;
        }
        out.println(sum);
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int year = s.nextInt();
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            System.out.println(year + " 年是闰年。");
        } else {
            System.out.println(year + " 年不是闰年。");
        }
    }
}

