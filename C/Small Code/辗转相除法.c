#include <stdio>
int fun(int m,int n){
	int rem;	
	while(n > 0){
		rem = m % n;
		m = n;
		n = rem;
	}
	return m;			//���������			
}
int main(){
	int n,m;
	scanf("%d %d",&m,&n);
	printf("m��n�����Լ��Ϊ��%d",fun(m,n));
	return 0; 
}