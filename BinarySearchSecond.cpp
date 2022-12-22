#include <iostream>

void BinarySearch(int* arr,int n, int start = 0, int end = 9) {
    for(int i = 0;i <= end;i++) {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << std::endl;
    int mid = (start + end)/2;
    if(start < end) {
        if(*(arr + mid) == n) {
            std::cout << n << " is present in given array.\n";
            std::cout << '(' << mid << ')' << std::endl;
            // return mid;
        }
        else if(n < *(arr + mid)) {
            // std::cout << n << " < " << *(arr + mid) << std::endl;
            int arr_new[mid];
            for(int i = 0;i < mid;i++) {
                arr_new[i] = *(arr + i);
            }
            std::cout << '(' << mid << ')' << std::endl;
            // return mid - BinarySearch(arr_new,n,start,mid - 1);
        }
        else {
            // std::cout << n << " > " << *(arr + mid) << std::endl;
            int arr_new[end - mid];
            for(int i = mid + 1,j = 0;j < end - mid;j++) {
                arr_new[j] = *(arr + i);
                i++;
            }
            std::cout << '(' << mid << ')' << std::endl;
            // return mid + BinarySearch(arr_new,n,start,end - mid - 1);
        }
    }
    else {
        if(*(arr + mid) == n) {
            std::cout << n << " is present in given array.\n";
            std::cout << '(' << mid << ')' << std::endl;
            // return mid;
        }
        else {
            std::cout << n << " is not present in given array.\n";
            // return -1;
        }
    }
    
}

int main()
{
    int arr[10] = {12,23,34,45,56,67,78,89,90,101};
    BinarySearch(arr,12);
    return 0;
}
