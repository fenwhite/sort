// introductoryTheory.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#define GET_ARRAY_LEN(array,len){len=sizeof(array)/sizeof(array[0]);}

void merge(int a[], int p, int q, int r);//input subscript!
void sort(int a[], int p, int r);//input subscript!!
void show(int a[], int len);
int main()
{
	int a[] = { 25,57,857,14,87,1 };
	int len;
	GET_ARRAY_LEN(a, len)
		sort(a, 0, len-1);
		merge(a, 0, 2, len-1);
	show(a , len);
    return 0;
}
void merge(int a[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L, *R;
	L = (int*)calloc(n1+1, sizeof(int));
	R = (int*)calloc(n2+1, sizeof(int));
	for (int i = 0; i < n1; i++)
		L[i] = a[i+p];
	for (int i = 0; i < n2; i++)
		R[i] = a[i + q+1 ];
	L[n1] = 1024;
	          show(L, n1 + 1);
	R[n2] = 1024;
	          show(R,n2+1);
	int i = 0, j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
				a[k] = R[j];
				j++;
		}
	}
	free(L);
	free(R);
}
void sort(int a[], int p, int r) {
	if (p > r) {
		printf("erroe!");
		return;
	}
	if (p < r) {
		int q = (p + r) / 2;
		sort(a,p,q);
		sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
void show(int a[], int len) {
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}
