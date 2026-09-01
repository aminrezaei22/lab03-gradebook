#include "stats.h"
#include <iostream>

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    if ( studentIndex < 0 || studentIndex >= STUDENT_COUNT ) {
        std::cout << "Invalid index provided\n";
        return -1.0;
    }
    double total{};

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        total += scores[studentIndex][i];
    }

    return total / ASSIGNMENT_COUNT;
}

double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores) {
    auto total{0.0};

    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        for ( auto j{0}; j < ASSIGNMENT_COUNT; j++ ) {
            total += scores[i][j];
        }
    }

    return total / (STUDENT_COUNT * ASSIGNMENT_COUNT);
}

double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex) {
    double total{};

    for (auto i{0}; i < STUDENT_COUNT; i++) {
        total += scores[i][assignmentIndex];
    }

    return total / STUDENT_COUNT;
}
