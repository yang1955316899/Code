#include <stdio.h>
int main(){
	int step,end,i,temp;
	scanf("%d",&end);
	int *list = (int *)malloc(end * sizeof(int));
	memset (list,1,sizeof(int)*end);
	for (i = 2;i <= end;i++) 
	{
		if (list[i]){temp = 2*i; while(temp < end){list[temp] = 0;temp += i;}}
	
	} 
	for (i = 2;i <= end;i++) if(list[i]) printf("%d ",i);
	return 0;
	} 
