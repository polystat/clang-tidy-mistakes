// Clang-Tidy fails to detect assignment to a constant variable,
// which causes a memory error (write to a write-protected page).
// Assignment is enabled with "const_cast<>".

// If a global variable is declared as "const",
// it is likely to be placed into a write-protected memory segment.
// As a result, an attempt to assign it will cause a page fault.
int x = 10;

int main() {
    // Const alias is fine. Though such cast also not recommended.
    const int& xx = x;

    // This assignment is OK (as referenced memory is not constant).
    const_cast<int&>(xx) = 2;
    return 0;
}
