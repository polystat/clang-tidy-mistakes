// Clang-Tidy fails to detect invalid cast of function pointers.

typedef void (* f1_t)(int *);
typedef void (* f2_t)(int);

void func(int* x) {
    *x = 0;
}

int main() {
    f1_t pf1 = func;
    // Incompatible cast of function pointers.
    f2_t pf2 = reinterpret_cast<f2_t>(pf1);
    // Causes crash: 123 is cast to a pointer.
    pf2(123);
    return 0;
}
