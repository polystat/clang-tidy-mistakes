// Clang-Tidy cannot detect unhandled exceptions:
// ones that are thrown and never caught (no corresponding catch block).

#include <stdexcept>

void test() {
    throw 1;
}

int main() {
    try {
        test();
        throw std::logic_error("Unhandled exception (no catch block)!");
    } catch (...) {
        // It is recommended to handle all exceptions related to business logic.
        return -1;
    }
    return 0;
}
