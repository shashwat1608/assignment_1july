#include <iostream>
#include <vector>
#include <algorithm>

int minimumProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end(), std::greater<int>());

    int productSum = 0;
    for (int i = 0; i < nums1.size(); ++i) {
        productSum += nums1[i] * nums2[i];
    }

    return productSum;
}

int main() {
    int n;
    std::cout << "Enter the length of the arrays: ";
    std::cin >> n;

    std::vector<int> nums1(n), nums2(n);
    std::cout << "Enter the elements of nums1: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums1[i];
    }

    std::cout << "Enter the elements of nums2: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums2[i];
    }

    int minimumProduct = minimumProductSum(nums1, nums2);
    std::cout << "Minimum product sum: " << minimumProduct << std::endl;

    return 0;
}
