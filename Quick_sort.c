//Quick sort imple
#include <stdio.h>

int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = low - 1;
 for (int j = low; j < high; j++) {
 if (arr[j] < pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 int temp = arr[i + 1];
 arr[i + 1] = arr[high];
 arr[high] = temp;
 return i + 1;
}
void quickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quickSort(arr, low, pi - 1);
 quickSort(arr, pi + 1, high);
 }
}
void printArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
int main() {
 int arr[] = {38, 27, 43, 3, 9, 82, 10};
 int arrSize = sizeof(arr) / sizeof(arr[0]);
 printf("Unsorted array: \n");
 printArray(arr, arrSize);
 quickSort(arr, 0, arrSize - 1);
 printf("\nSorted array: \n");
 printArray(arr, arrSize);
 return 0;
}
