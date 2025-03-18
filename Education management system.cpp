#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string grade; 
    int attendance;
};

void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudentRecord(vector<Student>& students);
void deleteStudentRecord(vector<Student>& students);
void checkScholarshipEligibility(const vector<Student>& students);
void calculateClassAverage(const vector<Student>& students);
void exportReportCard(const vector<Student>& students);
void highlightTopPerformers(const vector<Student>& students);
void lowAttendanceAlert(const vector<Student>& students);
void saveDataToFile(const vector<Student>& students);
void loadDataFromFile(vector<Student>& students);
void generateClassPerformanceSummary(const vector<Student>& students);

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nEducation Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Check Scholarship Eligibility\n";
        cout << "7. Calculate Class Average\n";
        cout << "8. Export Report Card\n";
        cout << "9. Highlight Top Performers (Honor Roll)\n";
        cout << "10. Low Attendance Alert\n";
        cout << "11. Save Data to File\n";
        cout << "12. Load Data from File\n";
        cout << "13. Generate Class Performance Summary\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayAllStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudentRecord(students); break;
            case 5: deleteStudentRecord(students); break;
            case 6: checkScholarshipEligibility(students); break;
            case 7: calculateClassAverage(students); break;
            case 8: exportReportCard(students); break;
            case 9: highlightTopPerformers(students); break;
            case 10: lowAttendanceAlert(students); break;
            case 11: saveDataToFile(students); break;
            case 12: loadDataFromFile(students); break;
            case 13: generateClassPerformanceSummary(students); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}


void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter Roll Number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter Grade (A, B, C, etc.): ";
    cin >> newStudent.grade;
    cout << "Enter Attendance (%): ";
    cin >> newStudent.attendance;

    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}


void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

    cout << "\nStudent Details:\n";
    cout << setw(15) << "Roll Number" << setw(20) << "Name" << setw(10) << "Grade" << setw(15) << "Attendance (%)\n";
    for (const auto& student : students) {
        cout << setw(15) << student.rollNumber << setw(20) << student.name << setw(10) << student.grade << setw(15) << student.attendance << "\n";
    }
}


void searchStudent(const vector<Student>& students) {
    int choice;
    cout << "Search by:\n1. Roll Number\n2. Name\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int rollNumber;
        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        for (const auto& student : students) {
            if (student.rollNumber == rollNumber) {
                cout << "\nStudent Found:\n";
                cout << setw(15) << "Roll Number" << setw(20) << "Name" << setw(10) << "Grade" << setw(15) << "Attendance (%)\n";
                cout << setw(15) << student.rollNumber << setw(20) << student.name << setw(10) << student.grade << setw(15) << student.attendance << "\n";
                return;
            }
        }
        cout << "Student not found!\n";
    } else if (choice == 2) {
        string name;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        for (const auto& student : students) {
            if (student.name == name) {
                cout << "\nStudent Found:\n";
                cout << setw(15) << "Roll Number" << setw(20) << "Name" << setw(10) << "Grade" << setw(15) << "Attendance (%)\n";
                cout << setw(15) << student.rollNumber << setw(20) << student.name << setw(10) << student.grade << setw(15) << student.attendance << "\n";
                return;
            }
        }
        cout << "Student not found!\n";
    } else {
        cout << "Invalid choice!\n";
    }
}


void updateStudentRecord(vector<Student>& students) {
    int rollNumber;
    cout << "Enter Roll Number of the student to update: ";
    cin >> rollNumber;

    for (auto& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, student.name);
            cout << "Enter new Grade (A, B, C, etc.): ";
            cin >> student.grade;
            cout << "Enter new Attendance (%): ";
            cin >> student.attendance;
            cout << "Student record updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}


void deleteStudentRecord(vector<Student>& students) {
    int rollNumber;
    cout << "Enter Roll Number of the student to delete: ";
    cin >> rollNumber;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNumber == rollNumber) {
            students.erase(it);
            cout << "Student record deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}


void checkScholarshipEligibility(const vector<Student>& students) {
    for (const auto& student : students) {
        if ((student.grade == "A" || student.grade == "A+") && student.attendance >= 80) {
            cout << student.name << " (Roll Number: " << student.rollNumber << ") is eligible for a scholarship.\n";
        }
    }
}


void calculateClassAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }

   
    double total = 0;
    int count = 0;
    for (const auto& student : students) {
        if (student.grade == "A+") total += 95;
        else if (student.grade == "A") total += 90;
        else if (student.grade == "B+") total += 85;
        else if (student.grade == "B") total += 80;
        else if (student.grade == "C+") total += 75;
        else if (student.grade == "C") total += 70;
        else if (student.grade == "D") total += 65;
        else if (student.grade == "F") total += 50;
        count++;
    }

    double average = total / count;
    cout << "Class Average Grade: " << average << "\n";
}

void exportReportCard(const vector<Student>& students) {
    int rollNumber;
    cout << "Enter Roll Number of the student to export report card: ";
    cin >> rollNumber;

    for (const auto& student : students) {
        if (student.rollNumber == rollNumber) {
            ofstream outFile("ReportCard_" + to_string(student.rollNumber) + ".txt");
            if (!outFile) {
                cout << "Error creating report card file!\n";
                return;
            }
            outFile << "Report Card for " << student.name << " (Roll Number: " << student.rollNumber << ")\n";
            outFile << "Grade: " << student.grade << "\n";
            outFile << "Attendance: " << student.attendance << "%\n";
            outFile.close();
            cout << "Report card exported successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}


void highlightTopPerformers(const vector<Student>& students) {
    cout << "\nTop Performers (Honor Roll):\n";
    for (const auto& student : students) {
        if (student.grade == "A" || student.grade == "A+") {
            cout << student.name << " (Roll Number: " << student.rollNumber << ") - Grade: " << student.grade << "\n";
        }
    }
}


void lowAttendanceAlert(const vector<Student>& students) {
    cout << "\nStudents with Low Attendance (<50%):\n";
    for (const auto& student : students) {
        if (student.attendance < 50) {
            cout << student.name << " (Roll Number: " << student.rollNumber << ") - Attendance: " << student.attendance << "%\n";
        }
    }
}


void saveDataToFile(const vector<Student>& students) {
    ofstream outFile("student_data.txt");
    if (!outFile) {
        cout << "Error creating file!\n";
        return;
    }

    for (const auto& student : students) {
        outFile << student.rollNumber << " " << student.name << " " << student.grade << " " << student.attendance << "\n";
    }
    outFile.close();
    cout << "Data saved to file successfully!\n";
}


void loadDataFromFile(vector<Student>& students) {
    ifstream inFile("student_data.txt");
    if (!inFile) {
        cout << "No data file found!\n";
        return;
    }

    students.clear();
    Student tempStudent;
    while (inFile >> tempStudent.rollNumber >> tempStudent.name >> tempStudent.grade >> tempStudent.attendance) {
        students.push_back(tempStudent);
    }
    inFile.close();
    cout << "Data loaded from file successfully!\n";
}


void generateClassPerformanceSummary(const vector<Student>& students) {
    ofstream outFile("ClassPerformanceSummary.txt");
    if (!outFile) {
        cout << "Error creating summary file!\n";
        return;
    }

    outFile << "Class Performance Summary\n";
    outFile << setw(15) << "Roll Number" << setw(20) << "Name" << setw(10) << "Grade" << setw(15) << "Attendance (%)\n";
    for (const auto& student : students) {
        outFile << setw(15) << student.rollNumber << setw(20) << student.name << setw(10) << student.grade << setw(15) << student.attendance << "\n";
    }
    outFile.close();
    cout << "Class performance summary generated successfully!\n";
}