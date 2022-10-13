// Clang-Tidy fails to detect an illegal exception in a destructor
// if the exception is thrown in a separate function.

// This method throws an exception.
// If we inline it, Clang-Tidy will report an error.
void kill() {
    throw 10;
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
    }
    return 0;
}
