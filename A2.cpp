#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string smallestNumber(const std::string& pattern) {
    int n = pattern.size();
    std::string result;
    std::vector<int> stack;

    // Traverse the pattern and construct the result
    for (int i = 0; i <= n; ++i) {
        // Push the current number (1-based index) onto the stack
        stack.push_back(i + 1);

        // If it's the last character or the pattern is 'I', resolve the stack
        if (i == n || pattern[i] == 'I') {
            while (!stack.empty()) {
                result += std::to_string(stack.back());
                stack.pop_back();
            }
        }
    }

    return result;
}

int main() {
    std::string pattern;
    std::cout << "Enter the pattern (I/D): ";
    std::cin >> pattern;

    std::string result = smallestNumber(pattern);
    std::cout << "Lexicographically smallest number: " << result << std::endl;

    return 0;
}
