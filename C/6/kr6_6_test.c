#include <stdio.h>

#define COUNTRY "INDIA"         // String constant
#define TRUE    1               // Integer constant
#define FALSE   0               // Integer constant
#define SUM (10 + 20)           // Macro definition

int main()
{
   	printf("COUNTRY: %s\n", COUNTRY);
	printf("TRUE: %d\n", TRUE);
	printf("FALSE: %d\n", FALSE);
	printf("SUM(10 + 20): %d\n", SUM);

	return 0;
}
