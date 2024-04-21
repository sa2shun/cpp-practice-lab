#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

int binarySearch(const std::vector<int>& data, int target){
    int left = 0;
    int right = data.size() - 1;
    int mid = left+right)/2;
    while(left <= right){
        mid = (left+right)/2;
        if(target == data[mid]){
            return mid;
        } else if (target >= data[mid]){
            left = mid;
        } else if (target <= data[mid]){
            right = mid;
        } else {
            return -1;
        }
    
    }
