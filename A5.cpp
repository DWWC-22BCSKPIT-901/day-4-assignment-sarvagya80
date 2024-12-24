#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int daysToDie(std::vector<int>& plants) {
    int n = plants.size();
    std::stack<std::pair<int, int>> s; // Pair: (pesticide, days to die)
    int maxDays = 0;

    for (int i = 0; i < n; ++i) {
        int days = 0;

        // Pop stack while the current plant is stronger (has more pesticide)
        while (!s.empty() && plants[i] > s.top().first) {
            days = std::max(days, s.top().second);
            s.pop();
        }

        // If the stack is not empty, the current plant dies
        if (!s.empty()) {
            days++;
        } else {
            days = 0;
        }

        // Push the current plant with its survival days into the stack
        s.push({plants[i], days});

        // Update the maximum days
        maxDays = std::max(maxDays, days);
    }

    return maxDays;
}

int main() {
    // Example input
    std::vector<int> plants = {6, 5, 8, 4, 7, 10, 9};
    int result = daysToDie(plants);

    std::cout << "Number of days until no plant dies: " << result << std::endl;
    return 0;
}
