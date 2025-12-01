#include <iostream>
#include <vector>

void backtrack(std::vector<int>& curr, std::vector<std::vector<int>>& result, int target) {
    int index = curr.size();
    if (index == 10) {
        if (target == 0) {
            result.push_back(curr);
        }
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = 1; i <= 3; ++i) {
        curr.push_back(i);
        backtrack(curr, result, target - i);
        curr.pop_back();
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int target;
    std::cin >> target;
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    backtrack(curr, result, target);
    std::cout << result.size() << '\n';
    for (const std::vector<int>& nums : result) {
        for (int num : nums) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}