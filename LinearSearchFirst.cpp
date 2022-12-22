#include<iostream>

void linearSearch(int* arr,int n) {
    bool found = false;
    for(int i = 0;i < 5;i++) {
        if(*(arr+i) == n) {
            std::cout << n << " is present at position " << i+1 << ".\n";
            found = true;
            break;
        }
    }
    if(!found) {
        std::cout << n << " is not an element of given array.\n";
    }
}

int main() {
    int arr[5] = {2,4,1,3,5};
    linearSearch(arr,5);
    return 0;
} 
