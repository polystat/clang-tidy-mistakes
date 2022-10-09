// Clang-Tidy fails to detect writing beyond the scope of an array.

// Returns incorrectly calculated in some cases array index.
int find_index(const int* arr, const int count, const int val) {
    int index;
    for (index = 0; index < count; ++index) {
        if (arr[index] == val) {
            break;
        }
    }
    // Returns an index beyond array borders.
    return index;
}

// This needs to be in a separate function (to get the symptoms of stack corruption).
void test() {
    int arr[] = {1, 2, 5, 6};
    // Buffer overrun is here: arr[N] is assigned corrupting the stack.
    // Array index depends on function return value.
    arr[find_index(arr, 4, 3)] = 10;
}

int main() {
    test();
    return 0;
}
