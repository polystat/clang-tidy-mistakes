// Clang-Tidy fails to detect a function that infinitely runs itself in a new thread

#include <iostream>
#include <thread>

void test() {
    std::cout << "Oh!" << std::endl;
    // The function infinitely runs itself in a new thread.
    std::thread th(test);
    th.join();
}

int main(int argc, char *argv[]) {
    test();
    return 0;
}
