#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <pmmintrin.h> /*for flaot_min and double_min*/
 
int char_min_max();
int unsigned_char_min_max();
int short_min_max();
int unsigned_min_max();
int int_min_max();
int unsigned_int_min_max();
int long_min_max();
int unsigned_long_min_max();
int float_min();
int float_max();
int double_min();
int double_max();
 
 
 
int main()
{
 
    	printf("- standard headers -\n");
    
    	printf("float min = %lf\n", FLT_MIN);
    	printf("float max = %lf\n", FLT_MAX);
    
    	printf("float exp min (E min) = %d\n", FLT_MIN_EXP); /*Exponent min*/
    	printf("float exp max (E max)= %d\n", FLT_MAX_EXP); /*Exponent max*/
 
    	printf("double min = %lf\n", DBL_MIN);
    	printf("double max = %lf\n", DBL_MAX);
    
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
 
        printf("unsigned long int min  = %u\n", 0);
        printf("unsigned long int max = %lu\n\n", ULONG_MAX);
 
    	printf("- direct computation -\n");
/*    char_min_max();
    unsigned_char_min_max();
    short_min_max();
    unsigned_min_max();
    int_min_max();
    unsigned_int_min_max();
        long_min_max();
        unsigned_long_min_max();
    float_min;
*/    	float_max();
    	double_min();
    	double_max();
}
/*
int char_min_max()
{
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
    return 0;
}
 
int unsigned_char_min_max()
{
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
        return 0;
}
 
int short_min_max()
{
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
        return 0;
}
 
int unsigned_min_max()
{
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
        return 0;
}
 
int int_min_max()
{
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
        return 0;
}
 
int unsigned_int_min_max()
{
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
        return 0;
}
 
int long_min_max()
{
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
    return 0;
}
 
int unsigned_long_min_max()
{
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
        return 0;
}
*/
 
int float_max()
{
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
    /*           	printf("%f\n", i);*/
            	}
    	}
    	printf("float max = %f\n", before);
    	return 0;
}
 
int double_min()
{
        _MM_SET_DENORMALS_ZERO_MODE(_MM_DENORMALS_ZERO_ON);
 
        int j, count;
        double i, before;
        j = 1;
        count = 0;
        i = 1;
        before = 0;
        while (j == 1){
                if (i == i / 2){ /*untill min*/
                        printf("%s%f\n", "double_min: ", before);
                /*      printf("%s%e\n", "overflow: ", i);*/
                        j = 0;
                } else if (i > i / 2) { /*over min(underflow)*/
                        before = i;
                        i = i / 2;
                        ++count;
                } else {
                        printf("%s", "finish2: ");
                        printf("%f\n", before);
                        j = 0;
                }
        }
        return 1;
}
 
 
int double_max()
{
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
        /*      	printf("i1 = %f\n", dbefore);*/
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
                    	printf("%s%f\n", "double max = ", dbefore2);
                   	dj = 0;
            	}
    	}
    	return 0;
}

