// Here, NULL is assigned to a global variable. Later, when this variable
// is passed as an argument to a function, dereferencing leads
// to abnormal program termination. However, Clang Tidy doesn't
// see this.

class A {
public:
    int x = 5;
};
// To guarantee that null dereferencing does not happen,
// it is recommended to pass argument by reference instead by pointer.
int foo(A& a) {
    return a.x;
}
A *a = nullptr;
int main() {
    // Check pointer before dereferencing to avoid errors.
    if (a != nullptr) {
        foo(*a);
    }
}
