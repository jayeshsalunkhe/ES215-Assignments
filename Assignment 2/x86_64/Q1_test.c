
// #include <iostream>
#include<stdio.h>
#include<time.h>
#include<stdint.h>


int Cal_Fib(int n ){
    if( n<=1){
        return n;
    }
    int n1 = 0, n2 =1, n3;
    for(int i= 2; i<n ;i++){
    n3 = n2 + n1;
    n1 = n2;
    n2 = n3;  
    }
    return n2 ;
}
 
int main ()
{
  // Program for first 100 fibonacci numbers 
	struct timespec start, end ;
	timespec_get(&start, TIME_UTC);
	double time_s , secs, nsecs;
	
	int n = 100;
	//cout << Cal_Fib(n)<< endl ;
	
	
	timespec_get(&end, TIME_UTC);
	
	secs = end.tv_sec -start.tv_sec ;
	nsecs = end.tv_nsec - start.tv_nsec ;
	time_s = secs + nsecs*1e-9 ;
	printf("elapsed time :%.12f secs.\n", time_s);
	
	return 0;

}
