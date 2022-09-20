// Here, NULL is assigned to a global variable. Later, when this variable
// is passed as an argument to a function, dereferencing leads
// to abnormal program termination. However, Clang Tidy doesn't
// see this.

class A {
public:
  int x = 5;
};
int foo(A *a) {
  return a->x; // segmentation fault!
}
A *a = nullptr;
int main() {
  foo(a);
}