#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);

int main()
{
	char s_1[] = "123.45e-6";
	char s_2[] = "123.45";
	printf("char s_1=\n123.45e-6\ndouble=\n%f\n",atof(s_1));  
	printf("char s_2=\n123.45\ndouble=\n%f\n",atof(s_2));  
	
	return 0;
}

double atof(char s[])
{
	double val, power, n;
	int i, sign, exponent;
    
	for(i = 0; isspace(s[i]); i++){
		;
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-'){
		i++;
	}
	for(val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}
	if(s[i] == '.') {
		i++;
	}
	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	if(s[i] == 'e' || s[i] == 'E'){
		sign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-'){
			i++;
		}
		for (exponent = 0; isdigit(s[i]); i++){
			exponent = 10 * exponent + (s[i] - '0');
		}
		if(sign == 1){
			n = 10;
		} else {
			n = 1.0 / 10;
		}
		while ((exponent-1) > 0) {
			val = val * n;
		}
	}
	return val;
}
