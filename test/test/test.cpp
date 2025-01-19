#include <iostream>
#include <chrono>
#include <string>  // اضافه کردن این هدر برای استفاده از std::getline

int main() {
    using namespace std::chrono;

    std::cout << "aaaaaaaaaaaaaa" << std::endl;

    auto startTime = steady_clock::now();
    std::string input;

    while (true) {
        if (std::cin.rdbuf()->in_avail() > 0) { // بررسی وجود ورودی
            std::cin.ignore(); // پاک کردن ورودی بافر
            std::getline(std::cin, input); // گرفتن ورودی کامل
            std::cout << "bbbbbbbbbbbbb: " << input << std::endl;
            break;
        }

        auto elapsed = duration_cast<seconds>(steady_clock::now() - startTime).count();
        if (elapsed >= 5) {
            std::cout << "ccccccc!" << std::endl;
            startTime = steady_clock::now();
        }
    }

    return 0;
}
