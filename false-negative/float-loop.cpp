// Clang-Tidy fails to detect that float variable must not
// be a variable for the "while" loop.

int main() {
    float i = 0.0f;
    // Endless loop.
    // Bug: do not use float in loops and do not check it for equality.
    while (i != 1.0f) {
        i = i + 0.01f;
    }
    return 0;
}
