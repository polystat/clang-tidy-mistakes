// Here, the object is a decorator. However, by mistake,
// it decorates itself. This is a bug, but Clang Tidy
// doesn't see it.

class A {
public:
  A* a;
  A(A* a): a(a) {}
  int x() { return a->x() + 1; }
};
int main() {
  A* a = new A(0);
  a->a = a; // stack overflow!
  a->x();
}