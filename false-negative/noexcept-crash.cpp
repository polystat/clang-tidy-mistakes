// Clang-Tidy fails to detect an exception in a "nothrow" method
// if the exception is thrown in a separate function.

#include <iostream>

// This method throws an exception.
void kill() {
    throw std::runtime_error("Fail!");
}

// This function is "noexcept", but it calls a function
// that throws an exception causing abort()
void test() noexcept {
    // If we throw exception directly, Clang-Tidy will report an error.
    kill();
}

int main() {
    try {
        test();
    } catch (...) {
        // This line is never executed is exception is thrown in "noexcept"!
        std::cout << "Exception is handled!";
    }
    return 0;
}
