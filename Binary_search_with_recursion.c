//Bi
#include <stdio.h>
int binary_search(int arr[], int low, int high, int target) {
 if (low > high) {
 return -1;
 }

 int mid = (low + high) / 2;

 if (arr[mid] == target) {
 return mid;
 }

 if (arr[mid] > target) {
 return binary_search(arr, low, mid - 1, target);
 }

 return binary_search(arr, mid + 1, high, target);
}
int main() {
 int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
 int size = sizeof(arr) / sizeof(arr[0]);
 int target = 7;

 int result = binary_search(arr, 0, size - 1, target);

 if (result != -1) {
 printf("Element %d found at index %d\n", target, result);
 } else {
 printf("Element %d not found\n", target);
 }

 return 0;
}

