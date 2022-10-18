// Clang-Tidy fails to detect infinite loop with goto.

int main() {
    start:
    goto end;

    // Never reached!
    return 0;

    end:
    goto start;
}
