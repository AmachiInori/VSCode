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



arr = [1, 2, 3, 4, 6, 5, 9, 2, 4, 5, 10, 25, 36, 55, 12, 100, 52, 97, 354, 8, 66, 102]
print(selectionSort(arr))
print(insertSort(arr))
print(bubbleSort(arr))
print(shellSort(arr))