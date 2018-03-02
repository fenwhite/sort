// RadixSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
int store[10][10];

int getMax(int *A,int len);
int getFigure(int num, int list);
void radix(int *A, int len,int time);
void merge(int *A,int *amount);
void show(int *A, int len);
int pow(int base, int inex);
int main()
{
	int *A, max ,len ,time = 1 ;

	printf("How many number do you want to enter?\n");
	scanf_s("%d", &len);
	A = (int*)calloc(len, sizeof(int));
	printf("Please enter the number :\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &A[i]);

	max = getMax(A, len);
	//printf("test\nmax=%d\n", max);            //test:correct
	if (max == 0)
		;
	else
		for (int i = 10;; i *= 10) {
			if (max / i == 0)
				break;
			time += 1;
		}
	//printf("test\ntime=%d\n", time);         //test:correct
	//int test=getFigure(1234, 2);
	//printf("test\nexmple:1234\n 2:%d\n", test);      //test;correct
	radix(A, len, time);
	show(A, len);

    return 0;
}

int getMax(int *A,int len) {
	int max = 0;
	for (int i = 0; i < len; i++)
		if (max <= A[i])
			max = A[i];
	return max;
}
int getFigure(int num, int list) {
	return (num / pow(10, list - 1)) %10;
}
void radix(int *A, int len, int time) {
	for (int i = 1; i <= time; i++) {                     //statistics figure
		int store_amount[10];
		for (int i = 0; i < 10; i++)
			store_amount[i] = 0;                           //store_amount array initialize correct
		for (int j = 0; j < len; j++) {                     //through the array
			store[getFigure(A[j], i)][store_amount[getFigure(A[j], i)]] = A[j];
			store_amount[getFigure(A[j], i)]++;
		}
		merge(A,store_amount);
	}
}
void merge(int *A, int *amount) {
	int k = 0;
	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < amount[i]; j++) {
				A[k] = store[i][j];
				k++;
			}
}
void show(int *A, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", A[i]);
}
int pow(int base, int index) {
	int power = 1;
	for (int i = 0; i < index; i++)
		power *= base;
	return power;
}
