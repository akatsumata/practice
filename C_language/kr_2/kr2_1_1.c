#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

	printf("standard headers\n");
	
	printf("float min = %e\n", FLT_MIN);
	printf("float max = %e\n", FLT_MAX);
	
	printf("float exp min (E min) = %d\n", FLT_MIN_EXP); /*Exponent min*/
	printf("float exp max (E max)= %ld\n", FLT_MAX_EXP); /*Exponent max*/

	printf("double min = %e\n", DBL_MIN);
	printf("double max = %e\n", DBL_MAX);
	
	printf("double exp min (E min) = %d\n", DBL_MIN_EXP);
	printf("double exp max (E max) = %d\n", DBL_MAX_EXP);

	printf("signed char min = %d\n", SCHAR_MIN);
	printf("signed char max = %d\n", SCHAR_MAX);

	printf("unsigned char min = %d\n", 0);
        printf("unsigned char max = %d\n", UCHAR_MAX);

        printf("signed short int min = %d\n", SHRT_MIN);
        printf("signed short int max = %d\n", SHRT_MAX);

        printf("unsigned short int min = %d\n", 0);
        printf("unsigned short int max = %d\n", USHRT_MAX);

	printf("signed int min = %d\n", INT_MIN);
	printf("signed int max = %d\n", INT_MAX);
	
	printf("unsigned int min = %u\n", 0);
        printf("unsigned int max = %u\n", UINT_MAX);

        printf("signed long int min = %ld\n", LONG_MIN);
        printf("signed long int max = %ld\n", LONG_MAX);

        printf("unsigned long int min  = %lu\n", 0);
        printf("unsigned long int max = %lu\n\n", ULONG_MAX);

	printf("direct computation\n");
	signed char sc, latest;
	sc = latest = 0;
	while(sc <= 0){
		latest = sc;
		sc--;
	}
	printf("signed char min = %d\n", latest);
        while(sc >= 0){
                latest = sc;
                sc++;
        }
        printf("signed char max = %d\n", latest);
	
	unsigned char unsc, unsc1;
	unsc = unsc1 = 0;
	while(unsc1 <= 0){
                unsc = unsc1;
                unsc1--;
        }
        printf("unsigned char min = %d\n", unsc);
        while(unsc1 > 0){
                unsc = unsc1;
                unsc1++;
        }
        printf("unsigned char max = %d\n", unsc);

        signed short ss, ss1;
        ss = ss1 = 0;
        while(ss1 <= 0){
                ss = ss1;
                ss1--;
        }
        printf("signed char min = %d\n", ss);
        while(ss1 >= 0){
                ss = ss1;
                ss1++;
        }
        printf("signed char max = %d\n", ss);

        unsigned short unss, unss1;
        unss = unss1 = 0;
        while(unss1 <= 0){
                unss = unss1;
                unss1--;
        }
        printf("signed char min = %d\n", unss);
        while(unss1 > 0){
                unss = unss1;
                unss1++;
        }
        printf("signed char max = %d\n", unss);
	
        signed int si, si1;
        si = si1 = 0;
        while(si1 <= 0){
                si = si1;
                si1--;
        }
        printf("signed int min = %d\n", si);
	si = si1 = 0;
        while(si1 >= 0){
                si = si1;
                si1++;
        }
        printf("signed int max = %d\n", si);

        unsigned int uni, uni1;
        uni = uni1 = 0;
        while(uni1 <= 0){
                uni = uni1;
                uni1--;
        }
        printf("unsigned int min = %u\n", uni);
        while(uni1 > 0){
                uni = uni1;
                uni1++;
        }
        printf("unsigned int max = %u\n", uni);

	
        signed long sl, sl1;
        sl = sl1 = 0;
        while(sl1 <= 0){
                sl = sl1;
                sl1--;
        }
        printf("signed long min = %ld\n", sl);
        sl = sl1 = 0;
	while(sl1 >= 0){
                sl = sl1;
                sl1++;
        }
        printf("signed char max = %ld\n", sl);

        unsigned long unsl, unsl1;
        unsl = unsl1 = 0;
        while(unsl1 <= 0){
                unsl = unsl1;
                unsl1--;
        }
        printf("unsigned long min = %lu\n", unsl);
        while(unsl1 > 0){
                unsl = unsl1;
                unsl1++;
        }
        printf("unsigned long max = %lu\n", unsl);


	float i, n, j, before;
	before = 0;
	i = n = 1;
	j = 1;
	while(j == 1){
		if(i < i + n){
			before = i;
			i = i + n;
		} else if(i == i + n){
			n = n * 2;
			if(i == i + n){
				j = 0;
			}
	/*		printf("%e\n", i);*/
		}
	}
	printf("float max = %e\n", before);
		

	double di, dn, dj, dbefore, dbefore2;
        dbefore = 0;
        di = 1;
	dn = 2;
        dj = 1;
        while(dj == 1){
		if(di < di * 2){
			dbefore = di;
			di = di * 2;
		} else if(di ==  di * 2){
		/*	printf("i1 = %e\n", dbefore);*/
			dj = 0;
		}
	}
	dj = 1;
	di = dbefore;
	dn = 2;
	dbefore2 = 0;
	while(dj == 1){
		if(di < di + dbefore / dn){
			dbefore2 = di;
			di = di + dbefore / dn;
			dn = dn * 2;
		} else if(di == di + dbefore / dn){
			printf("%s%e\n", "double max = ", dbefore2);
			dj = 0;
		}
	}

/*	double di, dbefore;
	d = 1;
	i = 0;
		while(d > 0){
			di = di + dbefore; 
			di = di / 2;
			printf("float min all= %e\n", d);
		}
		i = d + 1.0;
		printf("%e\n", i);*/
        return 0;
}

