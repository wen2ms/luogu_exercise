#include <cstdint>
#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int64_t>>> counts(21, std::vector<std::vector<int64_t>>(21, std::vector<int64_t>(21)));

int64_t recurse(int64_t a, int64_t b, int64_t c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return recurse(20, 20, 20);
    }
    if (a < b && b < c) {
        if (counts[a][b][c - 1] == 0) {
            counts[a][b][c - 1] = recurse(a, b, c - 1);
        }
        if (counts[a][b - 1][c - 1] == 0) {
            counts[a][b - 1][c - 1] = recurse(a, b - 1, c - 1);
        }
        if (counts[a][b - 1][c] == 0) {
            counts[a][b - 1][c] = recurse(a, b - 1, c);
        }
        counts[a][b][c] = counts[a][b][c - 1] + counts[a][b - 1][c - 1] - counts[a][b - 1][c];
    } else {
        if (counts[a - 1][b][c] == 0) {
            counts[a - 1][b][c] = recurse(a - 1, b, c);
        }
        if (counts[a - 1][b - 1][c] == 0) {
            counts[a - 1][b - 1][c] = recurse(a - 1, b - 1, c);
        }
        if (counts[a - 1][b][c - 1] == 0) {
            counts[a - 1][b][c - 1] = recurse(a - 1, b, c - 1);
        }
        if (counts[a - 1][b - 1][c - 1] == 0) {
            counts[a - 1][b - 1][c - 1] = recurse(a - 1, b - 1, c - 1);
        }
        counts[a][b][c] = counts[a - 1][b][c] + counts[a - 1][b - 1][c] + counts[a - 1][b][c - 1] - counts[a - 1][b - 1][c - 1];
    }
    return counts[a][b][c];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t a;
    int64_t b;
    int64_t c;
    while (std::cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            return 0;
        }
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << recurse(a, b, c) << '\n';
    }

    return 0;
}