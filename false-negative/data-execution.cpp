// Clang-Tidy fails to detect data execution causing a crash.

struct Function {
    unsigned int data;

    Function() : data(0xDEADBEEF) {}

    void operator()() {
        // Data are cast to a function.
        auto func = reinterpret_cast<void (*)()>(this);
        // Data execution causes crash.
        func();
    }
};

int main() {
    Function func;
    func();
    return 0;
}
