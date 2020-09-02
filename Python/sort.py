def selectionSort(arr):
    for i in range(len(arr)):
        minValue, minLoca = arr[i], i
        for j in range(i, len(arr)):
            if minValue > arr[j]:
                minValue, minLoca = arr[j], j
        arr[i], arr[minLoca] = arr[minLoca], arr[i]
    return arr

def insertSort(arr):
    for i in range(len(arr)):
        nowValue = arr[i]
        insertPoint = i - 1
        while insertPoint >= 0 and arr[insertPoint] > nowValue:
            arr[insertPoint + 1] = arr[insertPoint]
            insertPoint -= 1
        arr[insertPoint + 1] = nowValue
    return arr

def bubbleSort(arr):
    for i in range(len(arr) - 1):
        for j in range(len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def shellSort(arr):
    h = 1
    while h < len(arr) // 3: 
        h = 3 * h + 1
    while h >= 1:
        for i in range(h, len(arr)):
            nowValue = arr[i]
            insertPoint = i - h
            while insertPoint >= 0 and arr[insertPoint] > nowValue:
                arr[insertPoint + h] = arr[insertPoint]
                insertPoint -= h
            arr[insertPoint + h] = nowValue
        h //= 3
    return arr

import heapq
def heapSort(arr):
    heap = []
    for i in arr:
        heapq.heappush(heap, i)
    for i in range(len(arr)):
        arr[i] = heapq.heappop(heap)
    return arr

def mergeSort(arr):
    _mergeSort(arr, 0, len(arr) - 1)
    return arr

def _mergeSort(arr, left, right):
    if left >= right:
        return
    mid = (left + right) // 2
    _mergeSort(arr, left, mid)
    _mergeSort(arr, mid + 1, right)
    tempArr = []
    leftPoint = left
    rightPoint = mid + 1
    while leftPoint <= mid or rightPoint <= right:
        if leftPoint > mid:
            tempArr.append(arr[rightPoint])
            rightPoint += 1
        elif rightPoint > right:
            tempArr.append(arr[leftPoint])
            leftPoint += 1
        elif arr[leftPoint] > arr[rightPoint]:
            tempArr.append(arr[rightPoint])
            rightPoint += 1
        else:
            tempArr.append(arr[leftPoint])
            leftPoint += 1
    for i in range(left, right + 1):
        arr[i] = tempArr[i - left]

def _quickSort(arr, left, right):
    if left >= right:
        return
    arr[(left + right) // 2], arr[left] = arr[left], arr[(left + right) // 2]
    pivot = arr[left]
    Lpoint, Rpoint = left + 1, right
    while True:
        while Lpoint < right and arr[Lpoint] <= pivot:
            Lpoint += 1
        while Rpoint > left and arr[Rpoint] > pivot:
            Rpoint -= 1
        if Lpoint < Rpoint:
            arr[Lpoint], arr[Rpoint] = arr[Rpoint], arr[Lpoint]
        else:
            break
    arr[left], arr[Rpoint] = arr[Rpoint], arr[left]
    _quickSort(arr, left, Lpoint - 1)
    _quickSort(arr, Rpoint + 1, right)

def quickSort(arr):
    _quickSort(arr, 0, len(arr) - 1)
    return arr

import time
import random

arr = []
for i in range(409600):
    arr.append(random.randint(0, 20000))
'''
tempArr = arr[:]
start = time.time()
selectionSort(tempArr)
end = time.time()
tempT = end - start
print('selection sort:' + str(tempT))

tempArr = arr[:]
start = time.time()
insertSort(arr)
end = time.time()
tempT = end - start
print('insert sort:' + str(tempT))

tempArr = arr[:]
start = time.time()
bubbleSort(arr)
end = time.time()
tempT = end - start
print('bubble sort:' + str(tempT))
'''

tempArr = arr[:]
start = time.time()
shellSort(arr)
end = time.time()
tempT = end - start
print('shell sort:' + str(tempT))

tempArr = arr[:]
start = time.time()
heapSort(arr)
end = time.time()
tempT = end - start
print('heap sort:' + str(tempT))

tempArr = arr[:]
start = time.time()
mergeSort(arr)
end = time.time()
tempT = end - start
print('merge sort:' + str(tempT))

tempArr = arr[:]
start = time.time()
quickSort(arr)
end = time.time()
tempT = end - start
print('quick sort:' + str(tempT))