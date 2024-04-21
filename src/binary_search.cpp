#include <vector>

int binarySearch(const std::vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target == data[mid]) {
            return mid;
        } else if (target > data[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
