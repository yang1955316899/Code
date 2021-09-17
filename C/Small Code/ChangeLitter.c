#include <stdio.h> 
#include <string.h>
int reversal(char *ch)
{
	char t;
	int i,len;
	len=strlen(ch);
	for(i=0;i<len/2;i++)
    {	
		t=ch[i];
		ch[i]=ch[len-i-1];
		ch[len-i-1]=t;		
	}
}
int main()
{
    char str1[20];
    scanf("%s",str1);
    reversal(str1); 
    printf("%s",str1); 
}
