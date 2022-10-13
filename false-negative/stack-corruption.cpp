// Clang-Tidy fails to detect stack corruption causes
// by invalid pointer cast.

int main() {
    // This is an 8-byte variable on the stack.
    char c = 'A';
    char* pc = &c;
    // This is an implicit cast to a void pointer.
    // Cast to "void *" prevents Clang-Tidy from detecting this error.
    void* p = pc;
    // This explicit cast gives a wrong pointer type.
    int *pi = reinterpret_cast<int *>(p);
    // This assigment corrupts the stack. Error is here!
    *pi = 0;
    return 0;
}
