#include <iostream>
#include<time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int N = 512;
//int m1[128][128] , m2[128][128], M[128][128] ;
//int m1[256][256] , m2[256][256], M[256][256] ;
int m1[512][512] , m2[512][512], M[512][512] ;
double elapsed_time[6] ;


void f1(){
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	// i th 
	
	
	for(int i =0;i<N;i++){
	    for(int j=0; j<N;j++){
	        for(int k=0; k<N;k++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	elapsed_time[0] = elapsed ;
	printf("Time ijk: %.5f  secs.\n",  elapsed );
	elapsed_time[1] = elapsed ;
	

}


void f2(){
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int i =0;i<N;i++){
	    for(int k=0; k<N;k++){
	        for(int j=0; j<N;j++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
	
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time ikj: %.5f  secs.\n",  elapsed );	
	elapsed_time[2 ] = elapsed ;

}


void f3(){
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int j=0; j<N;j++ ){
	    for(int i =0;i<N;i++){
	        for(int k=0; k<N;k++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time jik: %.5f  secs.\n",  elapsed );
	elapsed_time[ 3] = elapsed ;
	
}

void f4(){
	
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int j=0; j<N;j++){
	    for(int k=0; k<N;k++){
	        for(int i =0;i<N;i++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time jki: %.5f  secs.\n",  elapsed );	
	elapsed_time[ 4] = elapsed ;
}


void f5(){
	
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int k=0; k<N;k++){
	    for(int i =0;i<N;i++){
	        for(int j=0; j<N;j++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
		
	
	
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time kij: %.5f  secs.\n",  elapsed );
	elapsed_time[ 5] = elapsed ;
}


void f6(){
	
	
	// Start timer
	struct timespec begin, end;
	clock_gettime(CLOCK_REALTIME, &begin);
	
	for(int k=0; k<N;k++){
	    for(int j=0; j<N;j++){
	        for(int i =0;i<N;i++){
	            M[i][j] = M[i][j] + m1[i][k]*m2[k][j];
	        }
	        
	    }
	}
	clock_gettime(CLOCK_REALTIME, &end);
	
	
	long secs = end.tv_sec -begin.tv_sec;
	long nanosecs = end.tv_nsec - begin.tv_nsec;
	double elapsed = secs + nanosecs*1e-9;
	
	printf("Time kji: %.5f  secs.\n",  elapsed );
	elapsed_time[6 ] = elapsed ;
}






int main() {
	
	//code goes here
	
	
	srand(time(0));
	
	for (int i=0; i<N; i++){
	    for(int j=0; j<N;j++){
	        m1[i][j] = rand()%100;
	        m2[i][j]= rand()%100;
	    }
	} 
	//cout << M[100];

	f1() ;
	//cout << M[100];
	
	f2() ;
	//cout << M[100];
	
	f3() ;
	//cout << M[100];
	
	f4() ;
	//cout << M[100];
	
	f5() ;
	//cout << M[100];
	
	f6() ;
	//cout << M[100];

	
	
	printf("Matrix Multiplication successful with N=: %d \n", N);


	
	
	return 0;
}

// rand ref : https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwjapPDE7sX1AhUkzzgGHTEgC9sQFnoECA0QAQ&url=https%3A%2F%2Fwww.cplusplus.com%2Freference%2Fcstdlib%2Frand%2F&usg=AOvVaw2wlimyhLSseOifc95ka8sU
// https://www.codespeedy.com/generate-a-matrix-of-random-numbers-in-cpp/
// https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9
