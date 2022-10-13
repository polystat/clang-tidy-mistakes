#include <iostream>
#include <thread>

class Obj {
    int* p;
public:
    explicit Obj(int v) : p(new int{v}) {}
    ~Obj() { delete p; }
    void print() { std::cout << *p << std::endl; }
};

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) {
        // "o" is a stack object passed by reference to a detached thread.
        // It is likely to have been destroyed by the moment the thread calls its method.
        Obj o{i};
        // The "&" capture means that the stack object "o" will be accessed by reference.
        auto f = [&]() { o.print(); };
        std::thread th(f);
        th.detach();
    }
    return 0;
}
