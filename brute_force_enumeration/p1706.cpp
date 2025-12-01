#include <iomanip>
#include <iostream>
#include <vector>

void backtrack(std::vector<int>& curr, std::vector<bool>& used, const int n) {
    if (curr.size() == n) {
        for (int digit : curr) {
            std::cout << std::setw(5) << digit;
        }
        std::cout << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        curr.push_back(i);
        backtrack(curr, used, n);
        used[i] = false;
        curr.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> curr;
    std::vector<bool> used(n);
    backtrack(curr, used, n);

    return 0;
}