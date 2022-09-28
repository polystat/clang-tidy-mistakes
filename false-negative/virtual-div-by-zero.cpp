// Clang-Tidy cannot find DIVISION BY ZERO in a virtual method.

#include <iostream>

struct Intf {
    virtual int test(int a) = 0;
};

class X : public Intf {
private:
    int value;
public:
    explicit X(int v) : value(v) {}

    int test(int a) override {
        return 10 / (value - a);
    }
};

int main() {
    X arr[] = {X{0}, X(5), X{10}};
    for (X& x : arr) {
        std::cout << x.test(5) << std::endl;
    }
    return 0;
}
