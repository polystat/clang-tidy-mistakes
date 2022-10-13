// Clang-Tidy cannot find DIVISION BY ZERO in a virtual method.
struct Y {
    // Note: virtual method is required. Otherwise, Clang-Tidy finds the error.
    virtual int test(int a) = 0;
};

class X : public Y {
private:
    int value;
public:
    explicit X(int v) : value(v) {}
    int test(int a) override {
        // Division by zero is in the line below.
        // If we rewrite the expression as "10 / a" and pass 0 to the method,
        // Clang-Tidy will report the error.
        return 10 / (value - a);
    }
};
int main() {
    X x{5};
    return x.test(5);
}
