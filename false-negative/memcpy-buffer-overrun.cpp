// Clang-Tidy fails to detect writing beyond the scope of an array with memcpy.

#include <cstring>

const int src_arr[] = { 5, 6, 7, 8};

// Need this function to hide memcpy. Otherwise, error is detected.
void write(void * dest, const void * src, const size_t size) {
    memcpy(dest, src, size);
}

int main() {
    int x = 1;
    int dest_arr[] = {1, 2, 3, 4};
    while (x) {
        x = 0;
        // This "write" corrupts the x variable causing endless loop.
        write(dest_arr + 3, src_arr, sizeof(src_arr));
    }
    return 0;
}
