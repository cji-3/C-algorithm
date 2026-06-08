#include <stdio.h>
#include <stdlib.h>
#include "../src/sort.c"

// 印出陣列的輔助函式
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("排序前: \n");
    printArray(data, n);
    
    C_Sort(data, 0, n - 1);
    
    printf("排序後: \n");
    printArray(data, n);

    //暫停直到ENTER被按下
	printf("Press ENTER to continue...");
	while(!getchar());
    return 0;
}