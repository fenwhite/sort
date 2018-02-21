// insertSort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

void insertSort(int *a, int len);
void show(int *a, int len);
int main()
{
	int len;
	int *a;
	printf("How many numbers do you want to enter?\n");
	scanf_s("%d", &len);
	a = (int*)calloc(len, sizeof(int));
	printf("Now enter the number:\n");
	for (int i = 0; i < len; i++)
		scanf_s("%d", &a[i]);
	insertSort(a, len);
	show(a, len);
	free(a);
    return 0;
}
void insertSort(int *a, int len) {
	int temp;
	for (int i = 1; i < len; i++) {
		temp = a[i];
		for (int j = i - 1; j >= 0; j--) 
			if(temp<=a[j]){
				a[j + 1] = a[j];
				a[j] = temp;
		    }
	}
}
void show(int *a, int len) {
	for(int i=0;i<len;i++)
		printf("%d",a[i]);
}

