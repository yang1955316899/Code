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
                System.out.println(i);
            }
        }
    }


}
