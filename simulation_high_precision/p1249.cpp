#include <iostream>
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
    while (start < len1 + len2 && result[start] == 0) {
        ++start;
    }
    std::string str;
    for (int i = start; i < len1 + len2; ++i) {
        str += std::to_string(result[i]);
    }
    return str;
}

int main() {
    int num;
    std::cin >> num;
    if (num == 3 || num == 4) {
        std::cout << num << '\n';
        std::cout << num << '\n';
        return 0;
    }
    int sum = 0;
    int start = 2;
    std::string result = "1";
    std::vector<int> sequence;
    while (sum < num) {
        sum += start;
        sequence.push_back(start);
        ++start;
    }
    if (sum > num + 1) {
        sequence[sum - num - 2] = 0;
    } else if (sum == num + 1) {
        sequence[0] = 0;
        ++sequence.back();
    }
    for (int digit : sequence) {
        if (digit != 0) {
            std::cout << digit << ' ';
            result = multiply(result, std::to_string(digit));
        }
    }
    std::cout << '\n';
    std::cout << result << '\n';

    return 0;
}