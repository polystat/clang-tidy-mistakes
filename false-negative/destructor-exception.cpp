// Clang-Tidy fails to detect an illegal exception in a destructor
// if the exception is thrown in a separate function.

#include <iostream>

// This method throws an exception.
// If we inline it, Clang-Tidy will report an error.
void kill() {
    throw std::runtime_error("Fail!");
}

class Class {
public:
    Class() = default;
    ~Class() {
        // Crash is here.
        // Throwing an exception in a destructor is illegal and causes abort().
        kill();
    }
};

int main() {
    try {
        Class cl;
    } catch (...) {
        // This line is never executed!
        std::cout << "Exception is handled!";
    }
    return 0;
}
