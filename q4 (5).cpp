#include <iostream>
#include <vector>
#include <unordered_map>

int findMaxLength(std::vector<int>& nums) {
    int maxLength = 0;
    int count = 0;
    std::unordered_map<int, int> countMap;
    countMap[0] = -1;  // Initialize the map with an initial count of 0

    for (int i = 0; i < nums.size(); ++i) {
        count += nums[i] == 0 ? -1 : 1;

        if (countMap.find(count) != countMap.end()) {
            // If the current count already exists in the map, calculate the length of the subarray
            int length = i - countMap[count];
            maxLength = std::max(maxLength, length);
        } else {
            // Otherwise, store the current count along with its corresponding index
            countMap[count] = i;
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    std::vector<int> nums = {0, 1, 0, 1, 0, 0, 1};

    int maxLength = findMaxLength(nums);

    std::cout << "Maximum length of a contiguous subarray with an equal number of 0 and 1: " << maxLength << std::endl;

    return 0;
}
