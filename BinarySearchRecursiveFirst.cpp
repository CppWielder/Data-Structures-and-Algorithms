#include<iostream>

void binarySearch(int* arr, int n, int start = 0, int end = 9) {
    int mid = (start + end)/2;
    if(start < end) {
        if(n == *(arr + mid)) {
            std::cout << n << " is present.\n";
            // return mid + 1;
        }
        else if(n < *(arr + mid)) {
            // std::cout << n << " < " << *(arr + mid) << std::endl;
            int _start = 0;
            int _end = mid - 1;
            int new_arr[_end - _start + 1];
            for(int i = _start;i <= _end;i++) {
                new_arr[i] = *(arr + i);
            }
            return binarySearch(new_arr,n,_start,_end);
        }
        else {
            // std::cout << n << " > " << *(arr + mid) << std::endl;
            int start_ = 0;
            int end_ = mid;
            int new_arr[end_ - start_ + 1];
            for(int i = start_,j = mid + 1;j <= end;i++) {
                new_arr[i] = *(arr + j);
                j++;
            }
            return binarySearch(new_arr,n,start_,end_);
        }
    }
    else {
        if(n == *(arr + mid)) {
            std::cout << n << " is present.\n";
        }
        else {
            std::cout << n << " is not present in given array.\n";
        }
    }
}
/*3*/
// 1 2 4 5 6 7 8 10 11 12 start = 0 end = 9 mid = 4 Ld
// 1 2 4 5 start = 0 end = 3 mid = 1 Gd
// 4 5 start_ = 0 end_ = 1 mid_ = 0 start = 2 end = 3 Ld
// 4 start = 0 end = 0 Gd

/*9*/
// 1 2 4 5 6 7 8 10 11 12 start = 0 end = 9 mid = 4 Gd
// 7 8 10 11 12 start_ = 0 end_ = 4 mid_ = 2 start = 5 end = 9 Ld
// 7 8 start = 0 end = 1 mid = 0 Gd
// 7 start = 0 end = 0 Ld

/*11*/
// 1 2 4 5 6 7 8 10 11 12 start = 0 end = 9 mid = 4 Gd
// 7 8 10 11 12 start_ = 0 end_ = 4 mid_ = 2 start = 5 end = 9 Gd
// 11 12 start_ = 0 end_ = 1

/*3*/
// 1 2 4 5 6 7 8 10 11 12 start = 0 end = 9 mid = 4 Ld
// 1 2 4 5 _start = 0 _end = 3 start = 0 end = 3 mid = 1 Ld
// _start = 0 _end = 2 

int main() {
    int arr[10] = {12,23,34,45,56,67,78,89,90,101};
    binarySearch(arr,78);
    return 0;
}
