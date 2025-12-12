#include <iostream>
#include <vector>

std::vector<int> primes;

void linear_seive(int num) {
    std::vector<bool> is_prime(num + 1, true);
    for (int i = 2; i <= num; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int prime : primes) {
            if (i * prime > num) {
                break;
            }
            is_prime[i * prime] = false;
            if (i % prime == 0) {
                break;
            }
        }
    }
}

bool is_palindrome(int num) {
    std::string str = std::to_string(num);
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int low;
    int high;
    std::cin >> low >> high;
    linear_seive(high);
    for (int prime : primes) {
        if (prime < low) {
            continue;
        }
        if (is_palindrome(prime)) {
            std::cout << prime << '\n';
        }
    }

    return 0;
}