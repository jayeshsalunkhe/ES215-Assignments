
import numpy as np 
import time

p = 9
N = 2**p
print("Matrix size:")
print(N)
# Generate random matrices
m1 = np.random.randint(10, size=(N,N))
m2 = np.random.randint(10, size=(N,N))
# print(m1.dtype)

Mul= [ [ 0 for i in range(N) ] for j in range(N) ]
 

    
start = time.time()
for i in range(N):
    for j in range(N):
        sum =0
        for k in range(N):
            sum  += m1[i][k]*m2[k][j]
        Mul[i][j] = sum
    
end = time.time()
print("Exec time :", (end-start))
    
    
    
