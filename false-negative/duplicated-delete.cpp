// Clang-Tidy fails to detect deleting duplicated pointers
// stored in a container class.

#include <array>

int main() {
    // Two pointers.
    int* p1 = new int{5};
    int* p2 = new int{10};
    // Array contains duplicated pointers.
    // For old-style C array "int* []" Clang-Tidy detects issues.
    std::array<int *, 4> ptrs = {p1, p2, p1, p2};
    for (int i = 0; i < 4; ++i) {
        // Bug: Attempt to free released memory
        delete ptrs[i];
    }
    return 0;
}
