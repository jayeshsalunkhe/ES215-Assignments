
import numpy as np 
import time


for p in range(5,10):
    N = 2**p 
    print("Matrix size:")
    print(N)
    # Generate random matrices
    m1 = np.random.randint(10, size=(N,N))
    m2 = np.random.randint(10, size=(N,N))
    
    Mul= [ [ 0 for i in range(N) ] for j in range(N) ]
    	
 
    #Mul = Mul.astype('float64')
    
    start = time.time()
    for i in range(N):
        for j in range(N):
            sum =0
            for k in range(N):
                sum  += m1[i][k]*m2[k][j]
            Mul[i][j] = sum
    
    end = time.time()
    print("Exec time :", (end-start))
    
    
   
