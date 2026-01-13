#include <cstdint>
#include <iostream>

void traverse(int64_t x, int64_t y, int64_t row, int64_t col, int64_t sides_count) {
    if (sides_count == 1) {
        return;
    }
    if (x <= row + sides_count / 2 - 1 && y <= col + sides_count / 2 - 1) {
        std::cout << row + sides_count / 2 << ' ' << col + sides_count / 2 << ' ' << 1 << '\n';
        traverse(x, y, row, col, sides_count / 2);
        traverse(row + sides_count / 2 - 1, col + sides_count / 2, row, col + sides_count / 2, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2 - 1, row + sides_count / 2, col, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2, row + sides_count / 2, col + sides_count / 2, sides_count / 2);
    } else if (x <= row + sides_count / 2 - 1 && y > col + sides_count / 2 - 1) {
        std::cout << row + sides_count / 2 << ' ' << col + sides_count / 2 - 1 << ' ' << 2 << '\n';
        traverse(row + sides_count / 2 - 1, col + sides_count / 2 - 1, row, col, sides_count / 2);
        traverse(x, y, row, col + sides_count / 2, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2 - 1, row + sides_count / 2, col, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2, row + sides_count / 2, col + sides_count / 2, sides_count / 2);
    } else if (x > row + sides_count / 2 - 1 && y <= col + sides_count / 2 - 1) {
        std::cout << row + sides_count / 2 - 1 << ' ' << col + sides_count / 2 << ' ' << 3 << '\n';
        traverse(row + sides_count / 2 - 1, col + sides_count / 2 - 1, row, col, sides_count / 2);
        traverse(row + sides_count / 2 - 1, col + sides_count / 2, row, col + sides_count / 2, sides_count / 2);
        traverse(x, y, row + sides_count / 2, col, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2, row + sides_count / 2, col + sides_count / 2, sides_count / 2);
    } else {
        std::cout << row + sides_count / 2 - 1 << ' ' << col + sides_count / 2 - 1 << ' ' << 4 << '\n';
        traverse(row + sides_count / 2 - 1, col + sides_count / 2 - 1, row, col, sides_count / 2);
        traverse(row + sides_count / 2 - 1, col + sides_count / 2, row, col + sides_count / 2, sides_count / 2);
        traverse(row + sides_count / 2, col + sides_count / 2 - 1, row + sides_count / 2, col, sides_count / 2);
        traverse(x, y, row + sides_count / 2, col + sides_count / 2, sides_count / 2);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t sides_count;
    int64_t x;
    int64_t y;

    std::cin >> sides_count >> x >> y;
    sides_count = (1 << sides_count);
    traverse(x, y, 1, 1, sides_count);

    return 0;
}