#include <iostream>
#include<stdio.h>
#include<time.h>
#include<stdint.h>
using namespace std;

int Cal_Fib(int n ){
    if( n<=1){
        return n;
    }
    return Cal_Fib(n-1) + Cal_Fib(n-2);
}

int main() {
	// Program for first 100 fibonacci numbers 
	struct timespec start, end ;
	timespec_get(&start, TIME_UTC);
	double time_s , secs, nsecs;
	
	int n = 50;
	//cout << Cal_Fib(n)<< endl ;
	
	
	timespec_get(&end, TIME_UTC);
	
	secs = end.tv_sec -start.tv_sec ;
	nsecs = end.tv_nsec - start.tv_nsec ;
	time_s = secs + nsecs*1e-9 ;
	printf("elapsed time :%.10f secs.\n", time_s);
	
	return 0;
}

