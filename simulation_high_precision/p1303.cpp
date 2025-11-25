#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string num1;
    std::string num2;
    std::cin >> num1 >> num2;
    int len1 = num1.length();
    int len2 = num2.length();
    std::vector<int> result(len1 + len2);
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int multiply = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + multiply;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    int start = 0;
    while (start < len1 + len2 - 1 && result[start] == 0) {
        ++start;
    }
    for (int i = start; i < len1 + len2; ++i) {
        std::cout << result[i];
    }
    std::cout << '\n';

    return 0;
}