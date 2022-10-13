// Clang-Tidy fails to detect a call of pure virtual method in a constructor
// if it is done via a lambda. Such a call causes a crash.
// Note: direct calls of pure virtual methods are detected.

class Base {
    int cached;
public:
    explicit Base(int (*f)(const Base &)) {
        // If "f" calls a pure virtual method for "this", the program crashes!
        cached = f(*this);
    }

    virtual int createValue() const = 0;
};

class Derived : public Base {
public:
    explicit Derived(int (*f)(const Base &)) : Base(f) {}

    int createValue() const override {
        return 10;
    }
};

int main(int argc, char *argv[]) {
    // This is a lambda that calls a pure virtual method of a base class.
    auto f = [](const Base& base) -> int { return base.createValue(); };
    // This lambda is passed to the constructor, which class it causing crash.
    Derived derived{f};
    return 0;
}
