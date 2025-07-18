//Bi
#include <stdio.h>
int binary_search(int arr[], int size, int target) {
 int low = 0;
 int high = size - 1;

 while (low <= high) {
 int mid = (low + high) / 2;


 if (arr[mid] == target) {
 return mid;
 }


 else if (arr[mid] > target) {
 high = mid - 1;
 }


 else {
 low = mid + 1;
 }
 }

 return -1;
}
int main() {
 int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
 int size = sizeof(arr) / sizeof(arr[0]);
 int target = 7;

 int result = binary_search(arr, size, target);

 if (result != -1) {
 printf("Element %d found at index %d\n", target, result);
 } else {
 printf("Element %d not found\n", target);
 }

 return 0;
}

