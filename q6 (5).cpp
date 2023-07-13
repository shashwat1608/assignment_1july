#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findOriginalArray(std::vector<int>& changed) {
    std::vector<int> original;
    
    // Check if the number of elements in 'changed' is odd
    if (changed.size() % 2 != 0) {
        return original; // Return an empty array if the size is odd
    }
    
    // Sort the 'changed' array in ascending order
    std::sort(changed.begin(), changed.end());
    
    // Traverse the 'changed' array
    for (int i = 0; i < changed.size(); i++) {
        // Check if the current element is already used
        if (changed[i] == -1) {
            continue;
        }
        
        // Find the index of the doubled value
        int doubledIndex = std::lower_bound(changed.begin(), changed.end(), 2 * changed[i]) - changed.begin();
        
        // Check if the doubled value is found and not already used
        if (doubledIndex < changed.size() && changed[doubledIndex] == 2 * changed[i]) {
            original.push_back(changed[i]); // Add the original element to the 'original' array
            changed[doubledIndex] = -1; // Mark the doubled element as used
        } else {
            return std::vector<int>(); // Return an empty array if the doubled value is not found
        }
    }
    
    return original;
}

int main() {
    // Test the function with an example input
    std::vector<int> changed = {1, 2, 2, 4, 5, 6, 8, 10};
    std::vector<int> original = findOriginalArray(changed);
    
    // Print the result
    if (original.empty()) {
        std::cout << "No solution found." << std::endl;
    } else {
        std::cout << "Original array: ";
        for (int num : original) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
