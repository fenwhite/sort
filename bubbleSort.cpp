// bubbleSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

void inverSort(int *a, int len);       //from low to high
void two_waySort(int *a, int len);      //look up
void show(int *a, int len);
int main()
{
	int len;
	int *a;
	printf("How many number do you want to enter?\n");
	scanf_s("%d", &len);
	a = (int*)calloc(len, sizeof(int));
	printf("Now enter the numbers:\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &a[i]);
	//inverSort(a, len);
	two_waySort(a, len);
	show(a, len);
	free(a);
    return 0;
}
void inverSort(int *a, int len) {
	int temp;
	for (int i = 4; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] < a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}
void two_waySort(int *a, int len) {
	int temp;
	for (int i = 0; i < len-2; i++) 
		for(int j=len-1;j>i;j--)
			if (a[j] < a[i]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
}
void show(int *a, int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}

