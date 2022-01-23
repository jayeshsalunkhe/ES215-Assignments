#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	//code goes here
	
	srand(time(0));
	int N = 256;
	int m1[N][N] , m2[N][N], M[N][N];
	
	for (int i=0; i<N; i++){
	    for(int j=0; j<N;j++){
	        m1[i][j] = rand()%100;
	        m2[i][j]= rand()%100;
	    }
	}
	
	/*
	for(int i =0; i<N; i++){
	    for(int j=0; j<N; j++){
	        std::cout<<m1[i][j]<<'\t';
	        std::cout<<m2[i][j]<<'\t';
	    }
	    cout<< "\n" ;
	}
	*/
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int i =0;i<N;i++){
	    for(int j=0; j<N;j++){
	        int sum_count= 0;
	        for(int k=0; k<N;k++){
	            sum_count += m1[i][k]*m2[k][j];
	        }
	        M[i][j] = sum_count;
	    }
	}
	printf("Matrix Multiplication successful with N=: %d \n", N);
	clock_gettime(CLOCK_REALTIME, &end);
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time M: %.5f  secs.\n",  elapsed );
	
		
	/*
	for(int i =0; i<N; i++){
	    for(int j=0; j<N; j++){
	        std::cout<<M[i][j]<<'\t';
	    }
	    cout<<"\n" ;
	}
	*/
	
	return 0;
}

// rand ref : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjapPDE7sX1AhUkzzgGHTEgC9sQFnoECA0QAQ&url=https%3A%2F%2Fwww.cplusplus.com%2Freference%2Fcstdlib%2Frand%2F&usg=AOvVaw2wlimyhLSseOifc95ka8sU
// https://www.codespeedy.com/generate-a-matrix-of-random-numbers-in-cpp/
// https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
