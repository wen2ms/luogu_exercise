#include <cmath>
#include <iostream>
#include <string>
#include <vector>

std::string multiply(std::string& num1, std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    std::vector<int> result(len1 + len2);
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            if (i + j + 1 < len1 + len2 - 500) {
                continue;
            }
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    int start = 0;
    while (start < len1 + len2 - 1 && result[start] == 0) {
        ++start;
    }
    std::string str;
    for (int i = start; i < len1 + len2; ++i) {
        str += std::to_string(result[i]);
    }
    return str;
}

std::string fast_pow(int base, int exp) {
    std::string result = "1";
    std::string base_str = std::to_string(base);
    while (exp > 0) {
        if ((exp & 1) == 1) {
            result = multiply(result, base_str);
        }
        base_str = multiply(base_str, base_str);
        exp >>= 1;
    }
    return result;
}

int main() {
    int exp;
    std::cin >> exp;
    int length = exp * std::log10(2) + 1;
    std::cout << length << '\n';
    std::string result = fast_pow(2, exp);
    --result.back();
    length = result.length();

    if (length >= 500) {
        result = result.substr(length - 500);
    } else {
        result = std::string(500 - length, '0') + result;
    }
    for (int i = 0; i < 500; ++i) {
        std::cout << result[i];
        if ((i + 1) % 50 == 0) {
            std::cout << '\n';
        }
    }
    return 0;
}