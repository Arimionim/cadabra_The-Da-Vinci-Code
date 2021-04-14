#include <thread>
#include <vector>
#include "guesser.h"

int main() {
    std::vector<std::thread> threads;
    for (int i = 1; i < 10000; i++) {
        threads.emplace_back(guesser::test, i);
    }

    for (auto &t : threads) {
        t.join();
    }
    return 0;
}
