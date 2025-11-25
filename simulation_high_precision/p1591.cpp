#include <iostream>
#include <string>
#include <vector>

std::string multiply(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    std::vector<int> result(len1 + len2);
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
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

std::string factorial(int num) {
    std::string result = "1";
    for (int i = 1; i <= num; ++i) {
        result = multiply(result, std::to_string(i));
    }
    return result;
}

int main() {
    int total_cases;
    std::cin >> total_cases;
    while (total_cases > 0) {
        --total_cases;
        int num;
        int digit;
        std::cin >> num >> digit;
        std::string str = factorial(num);
        int count = 0;
        for (const char letter : str) {
            if (letter - '0' == digit) {
                ++count;
            }
        }
        std::cout << count << '\n';
    }

    return 0;
}