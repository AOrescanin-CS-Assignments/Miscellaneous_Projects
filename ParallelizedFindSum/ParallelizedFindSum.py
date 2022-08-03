#****************************************************************************************************
#
#       Name:         Alex Orescanin
#       Course:        COSC 2110 Computer Languages: Python
#       Assignment:   ParallelizedfindSum.py
#       Due Date:     12/09/2020
#       Description:
#               This program calculates the the sum of numbers using parallelized programming
#
#****************************************************************************************************

import numpy as np
import time
import multiprocessing as mp

np.random.RandomState(100)
arr = np.random.randint(0, 10, size=[30000, 6])
data = arr.tolist()
#We are using a 2D list because we need a large data set to see the
#Advantage of using parallel programming

#****************************************************************************************************

def calcSum(numList):
    result = 0

    for i in range(numList):
        for j in range(numList[i]):
            result += numList[i][j]

    return result

#****************************************************************************************************

if __name__ == '__main__':
    start = time.time()
    pool = mp.Pool(processes=3)
    results = pool.map(calcSum, [row for row in data])
    pool.close()
    end = time.time()
    final_result = calcSum(data)
    print('The total is: ', final_result)
    print('total time with paralleization ', end-start)
