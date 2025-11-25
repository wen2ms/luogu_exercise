#include <algorithm>
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

std::string add(const std::string& num1, const std::string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int index1 = len1 - 1;
    int index2 = len2 - 1;
    std::string result;
    int carry = 0;
    while (index1 >= 0 || index2 >= 0 || carry > 0) {
        int digit1 = (index1 >= 0 ? num1[index1] - '0' : 0);
        int digit2 = (index2 >= 0 ? num2[index2] - '0' : 0);
        int sum = digit1 + digit2 + carry;
        result += std::to_string(sum % 10);
        carry = sum / 10;
        --index1;
        --index2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string factorial(int num) {
    std::string result = "1";
    for (int i = 2; i <= num; ++i) {
        result = multiply(result, std::to_string(i));
    }
    return result;
}

int main() {
    int num;
    std::cin >> num;
    std::string result = "0";
    for (int i = 1; i <= num; ++i) {
        std::string curr = factorial(i);
        result = add(result, curr);
    }
    std::cout << result << '\n';

    return 0;
}