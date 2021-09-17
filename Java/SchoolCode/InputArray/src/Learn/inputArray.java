package Learn;

public class inputArray {
	public static void main(String[] args) {
		int [] a ={100,200,300};
		System.out.println(a.length);
		System.out.println(a);
		int b[][]={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
		System.out.println(b.length);
		System.out.println(b[4][2]);
		for (int[] tem:b){
			System.out.println(tem.length);
			System.out.println(tem);
		}
		b[4] = a;
		for (int[] tem:b){
			System.out.println(tem.length);
			System.out.println(tem);
		}
//		a[3] = 200;
		System.out.println(b[4][2]);
	}
}
