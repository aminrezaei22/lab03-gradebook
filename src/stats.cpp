#include "stats.h"
#include <limits>

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    double sum{0.0};
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        sum += scores[studentIndex][i];
    }
    return sum / ASSIGNMENT_COUNT;
}

double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex) {
    double sum{0.0};
    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        sum += scores[i][assignmentIndex];
    }
    return sum / STUDENT_COUNT;
}

void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest) {
    lowest = std::numeric_limits<double>::max();
    highest = std::numeric_limits<double>::min();

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        if ( scores[studentIndex][i] < lowest ) {
            lowest = scores[studentIndex][i];
        }
        if (scores[studentIndex][i] > highest ) {
            highest = scores[studentIndex][i];
        }
    }
}

char letterGrade(double average) {
    if ( average >= 90 ) {
        return 'A';
    } else if ( average >= 80 ) {
        return 'B';
    } else if ( average >= 70 ) {
        return 'C';
    } else if ( average >= 60 ) {
        return 'D';
    } else {
        return 'F';
    }
}

double gradePoints(char letter) {
    switch(letter) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        default: return 0.0;
      }
}

int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target) {
    int count{};

    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        if ( letterGrade(studentAverage(scores, i)) == target ) {
            count++;
        }
    }

    return count;
}

double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores) {
    double sum{0.0};
    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        sum += studentAverage(scores, i);
    }
    return sum / STUDENT_COUNT;
}

bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] >= 100.0 ) {
            return true;
        }
    }
    return false;
}

bool isAtRisk(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    if ( studentAverage(scores, studentIndex) < 70.0 ) {
        return true;
    }

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] < 50.0 ) {
            return true;
        }
    }

    return false;
}
