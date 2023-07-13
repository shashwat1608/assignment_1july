#include <iostream>
#include <vector>

bool isValidMountainArray(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 3) {
        return false;
    }

    int i = 0;

    // Walk up the mountain
    while (i < n - 1 && arr[i] < arr[i + 1]) {
        i++;
    }

    // Peak can't be the first or last element
    if (i == 0 || i == n - 1) {
        return false;
    }

    // Walk down the mountain
    while (i < n - 1 && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == n - 1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1};

    if (isValidMountainArray(arr)) {
        std::cout << "The array is a valid mountain array." << std::endl;
    } else {
        std::cout << "The array is not a valid mountain array." << std::endl;
    }

    return 0;
}
