// Clang-Tidy fails to detect assignment to a constant variable,
// which causes a memory error (write to a write-protected page).
// Assignment is enabled with "const_cast<>".

const int x = 10;

int main() {
    // This assignment causes a memory error (write to a read-only page).
    const_cast<int&>(x) = 2;
    return 0;
}
