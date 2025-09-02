#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 10 18:40:28 2024

@author: sidsahu
"""
import time
from scipy.sparse.linalg import LinearOperator
import numpy as np
from scipy.linalg import eig, eigh
from scipy.sparse.linalg import eigs, eigsh
import subprocess

# get the start time
st = time.time()

np.savetxt("residuals.txt",[0])

class mv(LinearOperator):

    def __init__(self, N, dtype='float64'):
        self.N = N
        self.shape = (self.N, self.N)
        self.dtype = np.dtype(dtype)

    def _matvec(self, x):
        np.savetxt('U_D1.txt', x)
        subprocess.call("./SC_run.sh", shell=True)
        Q_temp = np.loadtxt('U_D.txt')
        return Q_temp

start = time.process_time() 
N = 132536
DOP = mv(N, dtype=np.float64)
evals_large, evecs_large = eigs(DOP, 8, which='LM',tol=1e-3)
evecs_large_real = evecs_large.real
evecs_large_imag = evecs_large.imag

np.savetxt('Eig1.txt', evecs_large_real[:, 0])
np.savetxt('Eig2.txt', evecs_large_real[:, 1])
np.savetxt('Eig3.txt', evecs_large_real[:, 2])
np.savetxt('Eig4.txt', evecs_large_real[:, 3])
np.savetxt('Eig5.txt', evecs_large_real[:, 4])
np.savetxt('Eig6.txt', evecs_large_real[:, 5])


np.savetxt('evals_large.txt', evals_large)

et = time.time()
# get the execution time
elapsed_time = et - st
print('Execution time:', elapsed_time, 'seconds')
