#include <iostream>
#include <vector>

class NumArray {
private:
    std::vector<int> prefixSum; // Stores the prefix sum array

public:
    // Constructor to initialize the NumArray with the given nums array
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0); // Resize to n+1 to handle prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }

    // Function to calculate the range sum
    int sumRange(int left, int right) {
        // Range sum is the difference between prefix sums
        return prefixSum[right + 1] - prefixSum[left];
    }
};

int main() {
    // Input array
    std::vector<int> nums = {1, 2, 3, 4, 5};
    NumArray numArray(nums);

    // Example queries
    std::cout << "Sum of range [1, 3]: " << numArray.sumRange(1, 3) << std::endl; // Output: 9
    std::cout << "Sum of range [0, 4]: " << numArray.sumRange(0, 4) << std::endl; // Output: 15

    return 0;
}
