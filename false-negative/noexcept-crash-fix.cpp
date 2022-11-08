// Clang-Tidy fails to detect an exception in a "nothrow" method
// if the exception is thrown in a separate function.

// This method throws an exception.
void kill() {
    throw 10;
}

// This function calls a function that throws an exception.
// Such functions must not be "nothrow". Otherwise, abort() will be called.
void test() {
    // If we throw exception directly, Clang-Tidy will report an error.
    kill();
}

int main() {
    try {
        test();
    } catch (...) {
        // This line is never executed is exception is thrown in "noexcept"!
    }
    return 0;
}
