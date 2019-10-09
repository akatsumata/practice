#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void)
{
  	printf("%f\n", atof("123.45"));
  	printf("%f\n", atof("123.45e2"));
  	printf("%f\n", atof("123.45e-6"));

  	return 0;
}

double atof(char s[])
{
  	double val, power, e_power;
  	int i, sign, e;
  
  	for (i = 0; isspace(s[i]); i++){
    		;
  	}
  	sign = (s[i] == '-') ? -1 : 1;
  	if(s[i] == '+' || s[i] == '-'){
    		i++;
 	} 
  	for(val = 0.0; isdigit(s[i]); i++){
    		val = 10.0 * val + s[i] - '0';
  	}
  	if(s[i] == '.'){
    		i++;
  	}
  	for(power = 1.0; isdigit(s[i]); i++){
    		val = 10.0 * val + s[i] - '0';
    		power *= 0.1;
  	}
  	if(s[i] == 'e' || s[i] == 'E'){
    		i++;
  		e_power = (s[i] == '-') ? 0.1 : 10.0;
	}
	if(s[i] == '+' || s[i] == '-'){
    		i++;
 	} 
  	for(e = 0; isdigit(s[i]); i++){
    		e = 10 * e + s[i] - '0';
  	}
  	while(e--){
    		power *= e_power;
  	}
 	return sign * val * power;
}

