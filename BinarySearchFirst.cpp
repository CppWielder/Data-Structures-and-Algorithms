#include<iostream>

void binarySearch(int* arr,int n) {
    int start = 0;
    int end = 9;
    int mid;
    while(start <= end) {
        mid = (start + end)/2;
        if(*(arr+mid) == n) {
            std::cout << n << " is found at position " << mid + 1 << ".\n";
            return;
        }
        else if(*(arr+mid) < n) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    std::cout << n << " is not present in given array.\n";
}

// 1 3 4 5 6

int main() {
    int arr[10] = {12,23,34,45,56,67,78,89,90,101};
    int n;
    std::cout << "Enter number to be seached : ";
    std::cin >> n;
    binarySearch(arr,n);
    return 0;
}
