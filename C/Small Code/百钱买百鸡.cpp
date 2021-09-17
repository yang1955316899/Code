#include <stdio.h>
int main()
{
	int big,medium;float small;
	for (big = 0;big <= 20;big++)
		for (medium = 0;medium <= 34-big;medium++)
			for(small = 0;small <=100-big-medium;small++)
				if(5*big+3*medium+small/3 == 100)
					printf("%d %d %g\n",big,medium,small);
	return 0;
}