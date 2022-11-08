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
        try {
            // All exception thrown in a destructor must be handled.
            // Otherwise, the program will be aborted.
            kill();
        } catch (...) {
        }
    }
};

int main() {
    Class cl;
    return 0;
}
