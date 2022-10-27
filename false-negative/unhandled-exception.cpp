// Clang-Tidy cannot detect unhandled exceptions:
// ones that are thrown and never caught (no corresponding catch block).

#include <stdexcept>

int main() {
    throw std::logic_error("Unhandled exception (no catch block)!");
}
