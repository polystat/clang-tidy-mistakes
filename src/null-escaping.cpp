// Here NULL is set internally in the object to one of its
// attributes. Later, we retrieve it and dereference. However,
// Clang Tidy remains silent in this case,
// which is "false negative."

class A {
public:
  int* x = new int(42);
  int* getX() { return x; }
  void reset() { x = nullptr; }
};
int main() {
  A a = A();
  a.reset();
  return *a.getX(); // segmentation fault!
}