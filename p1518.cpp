#include <iostream>
#include <unordered_set>
#include <vector>

void move(std::vector<int>& pos, const std::vector<std::vector<char>>& grid) {
    int& row = pos[0];
    int& col = pos[1];
    int& direction = pos[2];
    if (direction == 0) {
        if (row == 0 || grid[row - 1][col] == '*') {
            direction = 1;
        } else {
            --row;
        }
    } else if (direction == 1) {
        if (col == 9 || grid[row][col + 1] == '*') {
            direction = 2;
        } else {
            ++col;
        }
    } else if (direction == 2) {
        if (row == 9 || grid[row + 1][col] == '*') {
            direction = 3;
        } else {
            ++row;
        }
    } else if (direction == 3) {
        if (col == 0 || grid[row][col - 1] == '*') {
            direction = 0;
        } else {
            --col;
        }
    }
}

int main() {
    std::vector<std::vector<char>> grid(10, std::vector<char>(10));
    std::vector<int> farmer(3);
    std::vector<int> cow(3);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cin >> grid[i][j];
            if (grid[i][j] == 'F') {
                farmer = {i, j, 0};
            } else if (grid[i][j] == 'C') {
                cow = {i, j, 0};
            }
        }
    }
    std::unordered_set<int> hash;
    int time = 0;
    while (farmer[0] != cow[0] || farmer[1] != cow[1]) {
        int state = farmer[0] + farmer[1] * 10 + cow[0] * 100 + cow[1] * 1000 + farmer[2] * 10000 + cow[2] * 40000;
        if (hash.contains(state)) {
            std::cout << 0 << '\n';
            return 0;
        }
        hash.insert(state);
        move(farmer, grid);
        move(cow, grid);
        ++time;
    }
    std::cout << time << '\n';

    return 0;
}