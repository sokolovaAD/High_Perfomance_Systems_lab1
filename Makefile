CC=gcc
CFLAGS= -g -std=c99 -Wall -pedantic


all: main.o
	gcc -fopenmp $(CFLAGS) -o main mergeSort.o heapSort.o logger.o loggerHeapSort.o main.o -lm

mergeSort.o: mergeSort.c
	gcc -fopenmp -c -o mergeSort.o mergeSort.c -lm

heapSort.o: mergeSort.c
	gcc -fopenmp -c -o heapSort.o heapSort.c -lm	
	
logger.o: logger.c
	gcc -fopenmp -c -o logger.o logger.c -lm

loggerHeapSort.o: loggerHeapSort.c
	gcc -fopenmp -c -o loggerHeapSort.o loggerHeapSort.c -lm	

main.o: mergeSort.o heapSort.o logger.o loggerHeapSort.o main.c
	gcc -fopenmp -c -o main.o main.c -lm