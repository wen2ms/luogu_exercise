#include <cstdlib>
#include <iostream>
#include <string>

std::string str;

void solve(int num) {
    int win_count = 0;
    int lose_count = 0;
    for (char letter : str) {
        if (letter == 'W') {
            ++win_count;
        } else {
            ++lose_count;
        }
        if (std::max(win_count, lose_count) >= num && std::abs(win_count - lose_count) >= 2) {
            std::cout << win_count << ':' << lose_count << '\n';
            win_count = 0;
            lose_count = 0;
        }
    }
    std::cout << win_count << ':' << lose_count << '\n';
}

int main() {
    char letter;
    while (std::cin >> letter) {
        if (letter == 'E') {
            break;
        }
        str += letter;
    }

    solve(11);

    std::cout << '\n';

    solve(21);

    return 0;
}