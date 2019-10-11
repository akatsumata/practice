#include <stdio.h>

int main()
{
	int c, i, cw;
           
	int ndigit[10];
	for (cw = 0; cw < 10; ++cw)
		ndigit[cw] = 0;
	cw = 0;
	while ((c = getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t')
			++cw;
		else{
			printf("%d\n", cw);
			if(cw < 10)
				++ndigit[cw];
			cw = 0;
		}	
	}
	for (cw = 1; cw < 10; ++cw){
		printf("%d |", cw);
		for(i = 0; i < ndigit[cw]; ++i ){
			printf("0");  
		}
		printf("\n");
	}
	return 0;
}
