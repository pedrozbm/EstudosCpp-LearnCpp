#include <thread>
#include <iostream>

int main() {
    std::thread t([] {
        std::cout << "Thread rodando no Cygwin\n";
    });

    t.join();
}
