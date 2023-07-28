//Task 3
//Student grading system program

#include <iostream>
using namespace std;
#include <string>

const int MAX_STUDENTS = 100;

string calculateLetterGrade(int grade) {
    if (grade >= 93 && grade <= 100) {
        return "A";
    } else if (grade >= 89 && grade <= 92) {
        return "A-";
    } else if (grade >= 87 && grade <= 88) {
        return "B+";
    } else if (grade >= 83 && grade <= 86) {
        return "B";
    } else if (grade >= 79 && grade <= 82) {
        return "B-";
    } else if (grade >= 77 && grade <= 78) {
        return "C+";
    } else if (grade >= 73 && grade <= 76) {
        return "C";
    } else if (grade >= 69 && grade <= 72) {
        return "C-";
    } else if (grade >= 67 && grade <= 68) {
        return "D+";
    } else if (grade >= 63 && grade <= 66) {
        return "D";
    } else if (grade >= 57 && grade <= 62) {
        return "D-";
    } else {
        return "F";
    }
}

void calculateGrades(const int grades[], int numStudents) {
    int sum = 0;
    int highestGrade = grades[0];
    int lowestGrade = grades[0];

    for (int i = 0; i < numStudents; i++) {
        sum += grades[i];

        if (grades[i] > highestGrade) {
            highestGrade = grades[i];
        }

        if (grades[i] < lowestGrade) {
            lowestGrade = grades[i];
        }
    }

    double average = static_cast<double>(sum) / numStudents;

    string avgLetterGrade = calculateLetterGrade(static_cast<int>(average));
    string highestLetterGrade = calculateLetterGrade(highestGrade);
    string lowestLetterGrade = calculateLetterGrade(lowestGrade);

    cout << "Average Grade: " << average << " (" << avgLetterGrade << ")" << std::endl;
    cout << "Highest Grade: " << highestGrade << " (" << highestLetterGrade << ")" << std::endl;
    cout << "Lowest Grade: " << lowestGrade << " (" << lowestLetterGrade << ")" << std::endl;
}

void displayGrades(const std::string names[], const int grades[], int numStudents) {
    cout << "\t\t\t\t***Student Grading system***\n\n";
    cout<<"\tStudent Name"<<"\t\tGrade"<<"\t\t\tLetter Grade\n";
    for (int i = 0; i < numStudents; i++) {
        string letterGrade = calculateLetterGrade(grades[i]);
        cout<< "\t"<< names[i] << "\t\t\t" << grades[i] << "\t\t\t\t" << letterGrade <<"\n";
    }
}

int main() {
    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS];
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    cout << "Enter the names and grades of students:\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> names[i];

        cout << "Student " << i + 1 << " Grade: ";
        cin >> grades[i];
    }

    displayGrades(names, grades, numStudents);
    calculateGrades(grades, numStudents);

    return 0;
}

