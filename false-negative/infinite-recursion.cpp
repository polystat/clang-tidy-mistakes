// Clang-Tidy cannot detect infinite recursion even for trivial cases.
// This function contains infinite recursion.
int f(int x) {
  return f(x + 1);
}
int main() {
  return f(10);
}
