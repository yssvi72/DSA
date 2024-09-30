class CustomStack {
public:
    int maxSize;  // Maximum allowed size for the stack
    vector<int> stack;  // Vector to represent the stack

    // Constructor to initialize the stack with the given maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    // Push operation: Adds element x to the stack if it is not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    // Pop operation: Removes and returns the top element, or -1 if the stack is empty
    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int topElement = stack.back();
        stack.pop_back();  // Remove the last element
        return topElement;
    }

    // Increment operation: Increments the bottom k elements by val
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());  // Increment only up to the number of elements in the stack
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;
        }
    }
};
