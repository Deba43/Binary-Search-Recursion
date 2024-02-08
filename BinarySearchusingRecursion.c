#include <stdio.h>

#define MAX_SIZE 100 

int binarySearch(int nums[], int item, int left, int right);

int main() {
    int lb, ub; 
    int a[MAX_SIZE]; 
    int item; 
    int j; 

    printf("Enter the lower and upper bounds of the array: ");
    scanf("%d%d", &lb, &ub);

    if (lb >= ub || ub > MAX_SIZE) {
        printf("Invalid bounds. Lower bound should be less than upper bound and both should be within 0 to %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for (j = lb; j < ub; j++) {
        scanf("%d", &a[j]);
    }

    printf("\nEnter the item to search for: ");
    scanf("%d", &item);

    int result = binarySearch(a, item, lb, ub - 1); 

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}

int binarySearch(int nums[], int item, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == item) {
            return mid;
        } else if (nums[mid] < item) {
            return binarySearch(nums, item, mid + 1, right);
        } else {
            return binarySearch(nums, item, left, mid - 1);
        }
    }
    return -1;
}
