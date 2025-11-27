#include <algorithm>
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int year;
    int month;
    int day;
    int id;
};

bool sort_students(const Student& left, const Student& right) {
    if (left.year != right.year) {
        return left.year < right.year;
    }
    if (left.month != right.month) {
        return left.month < right.month;
    }
    if (left.day != right.day) {
        return left.day < right.day;
    }
    return left.id > right.id;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_students;
    std::cin >> num_of_students;
    std::vector<Student> students(num_of_students);
    for (int i = 0; i < num_of_students; ++i) {
        std::cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
        students[i].id = i;
    }
    std::sort(students.begin(), students.end(), sort_students);

    for (const Student& student : students) {
        std::cout << student.name << '\n';
    }

    return 0;
}