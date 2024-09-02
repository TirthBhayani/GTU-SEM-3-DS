#include <stdio.h>
#include<time.h>
void quickSort(int a[], int si, int ei)  
{
	if (si < ei) {
		int p = div(a, si, ei);
		quickSort(a, si, p - 1);
		quickSort(a, p + 1, ei);
	}
}
void swap(int* x, int*y)
{
	int temp= *x;
	*x = *y;
	*y = temp;
}
int div(int a[], int si, int ei)
{
	int pivot = a[ei];
	int i = (si - 1);
	for (int j = si; j <= ei - 1; j++) {
		if (a[j] < pivot) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i + 1], &a[ei]);
	return (i + 1);
}
int main()
{
	 time_t Time;
    time(&Time);
    char *time = ctime(&Time);
    printf("execution Time = %s\n",time);
	int a[] = { 55,7,2,90,43,21};
	int N = 6;
	quickSort(a, 0, N - 1);
	printf("Sorted array: \n");
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	return 0;
}
