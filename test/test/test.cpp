#include <iostream>
#include <chrono>
#include <string>  
using namespace std;

int main() {
    using namespace std::chrono;

    std::cout << "10 secons to enter" << std::endl;

    auto startTime = steady_clock::now();
    std::string input;

    while (true) {
        if (std::cin.rdbuf()->in_avail() > 0) { // 
            std::cin.ignore(); // 
            std::getline(std::cin, input); // 
            std::cout << "input enterd: " << input << std::endl;
            break;
        }
        //std::cout << "ghj";
        auto elapsed = duration_cast<seconds>(steady_clock::now() - startTime).count();
        if (elapsed >= 1) {
            std::cout << "not enterd!" << std::endl;
            startTime = steady_clock::now();
        }
    }

    return 0;
}
