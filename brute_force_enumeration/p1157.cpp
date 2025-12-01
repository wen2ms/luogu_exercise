#include <iomanip>
#include <iostream>
#include <vector>

void backtrack(int num, std::vector<int>& curr, const int n, const int k) {
    if (curr.size() == k) {
        for (int digit : curr) {
            std::cout << std::setw(3) << digit;
        }
        std::cout << '\n';
        return;
    }
    for (int i = num; i <= n; ++i) {
        curr.push_back(i);
        backtrack(i + 1, curr, n, k);
        curr.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> curr;
    backtrack(1, curr, n, k);

    return 0;
}