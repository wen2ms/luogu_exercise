#include <cctype>
#include <iostream>
#include <string>

int main() {
    int para1;
    int para2;
    int para3;
    std::string str;
    std::cin >> para1 >> para2 >> para3 >> str;
    int len = str.length();
    int result;

    std::cout << str[0];
    for (int i = 1; i < len - 1; ++i) {
        char start = str[i - 1];
        char end = str[i + 1];
        if (str[i] == '-' && start < end &&
            (std::isalpha(start) != 0 && std::isalpha(end) != 0 || std::isdigit(start) != 0 && std::isdigit(end) != 0)) {
            if (para3 == 1) {
                for (int j = start + 1; j < end; ++j) {
                    char letter = j;
                    if (para1 == 2) {
                        if (std::isalpha(letter) != 0) {
                            letter = std::toupper(letter);
                        }
                    } else if (para1 == 3) {
                        letter = '*';
                    }
                    for (int k = 0; k < para2; ++k) {
                        std::cout << letter;
                    }
                }
            } else {
                for (int j = end - 1; j > start; --j) {
                    char letter = j;
                    if (para1 == 2) {
                        if (std::isalpha(letter) != 0) {
                            letter = std::toupper(letter);
                        }
                    } else if (para1 == 3) {
                        letter = '*';
                    }
                    for (int k = 0; k < para2; ++k) {
                        std::cout << letter;
                    }
                }
            }
        } else {
            std::cout << str[i];
        }
    }
    std::cout << str[len - 1];
    std::cout << '\n';

    return 0;
}