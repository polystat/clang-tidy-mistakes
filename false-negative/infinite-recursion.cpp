// Clang-Tidy cannot detect infinite recursion even for trivial cases.

#include <iostream>

// This function contains infinite recursion.
int recursion(int x) {
    return recursion(x + 1);
}
int main() {
    std::cout << recursion(10) << std::endl;
    return 0;
}
