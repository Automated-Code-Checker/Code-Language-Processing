#include<stdio.h>
#include<stdlib.h>
struct matrix {
	int** arr;
	int r; //rows
	int c; //columns
};
int poolval(int filter, int r, int c,int** arr ) {
	int  i,j,max = -9999;
	for (i = r; i < r + filter; i++) {
		for (j = c; j < c + filter; j++) {
			if (arr[i][j] > max) 
				max = arr[i][j];
		}
	}
	return max;
}
void fun(int n, int** arr) {//n=size
	int i,j;
	for ( i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	struct matrix l;
	struct matrix Mpooled;
	int arrsize,i,j, k, u;
	printf("Enter size of matrix ?");
	scanf("%d", &arrsize);
	printf("Enter Filter ");
	scanf("%d", &u);
	printf("Enter Stride ");
	scanf("%d", &k);
	l.arr = (int**)malloc(arrsize * sizeof(int));
	for ( i = 0; i < arrsize; i++) {
		l.arr[i] = (int*)malloc(arrsize * sizeof(int));
		for (j = 0; j < arrsize; j++) {
			scanf("%d", &l.arr[i][j]);
		}
	}
	Mpooled.arr = (int**)malloc(u * sizeof(int));
	for (i = 0; i < arrsize; i++) {
		Mpooled.arr[i] = (int*)malloc(u * sizeof(int));
	}
	fun(arrsize, l.arr);
	printf("\n");
	int pooledcol= 0,pooledrow=0,temp;
	for (i = 0; i < arrsize - u + 1; i += k) {
		
		for ( j = 0; j < arrsize - u + 1; j += k) {
			 temp =poolval( u, i, j, l.arr);
			 Mpooled.arr[pooledcol][pooledrow] = temp;
			 pooledrow++;
		}
		pooledrow = 0;
		printf("\n");
		pooledcol++;
	}
	fun(u, Mpooled.arr);
}