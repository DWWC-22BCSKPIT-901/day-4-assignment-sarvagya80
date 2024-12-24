#include <iostream>
#include <stack>
#include <climits>
#include <string>

class MinStack {
private:
    std::stack<int> mainStack; // Regular stack
    std::stack<int> minStack;  // Auxiliary stack to store minimum values

public:
    MinStack() {
        // Initialize minStack with a very large value to avoid empty stack issues.
        minStack.push(INT_MAX);
    }

    void push(int val) {
        mainStack.push(val);
        minStack.push(std::min(val, minStack.top()));
        std::cout << "Pushed: " << val << std::endl;
    }

    void pop() {
        if (!mainStack.empty()) {
            std::cout << "Popped: " << mainStack.top() << std::endl;
            mainStack.pop();
            minStack.pop();
        } else {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        throw std::runtime_error("Stack is empty");
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        throw std::runtime_error("Stack is empty");
    }
};

int main() {
    MinStack minStack;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Get Minimum\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter value to push: ";
            std::cin >> value;
            minStack.push(value);
            break;
        }
        case 2:
            minStack.pop();
            break;
        case 3:
            try {
                std::cout << "Top element: " << minStack.top() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            try {
                std::cout << "Minimum element: " << minStack.getMin() << std::endl;
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 5:
            running = false;
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
