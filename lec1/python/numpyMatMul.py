import sys, random
from time import *
import numpy as np 

n = 4096

A = np.array(
    [[random.random()
      for row in range(n)]
     for col in range(n)]
     ,dtype=np.float64)

B = np.array(
    [[random.random()
      for row in range(n)]
     for col in range(n)]
     ,dtype=np.float64
)

C = np.array(
    [[0.0
      for row in range(n)]
     for col in range(n)]
     ,dtype=np.float64
     )

start = time()
np.dot(A,B,out=C)
end = time()

print("%0.6f"%(end-start))
print(C)
