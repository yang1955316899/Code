#include <stdio>
int fun(int m,int n){
	int rem;	
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//将结果返回			
}
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	printf("m和n的最大公约数为：%d",fun(m,n));
	return 0; 
}