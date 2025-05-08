#include <iostream>
using namespace std;

// Constants
const int MAX_STUDENTS = 50;
const int MAX_COURSES = 20;
const int MAX_DEPARTMENTS = 5;
const int MAX_PROFESSORS = 10;

// ------------------- Exception Classes -------------------
class UniversitySystemException {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message(msg) {}
    string what() { return message; }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException(msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException(msg) {}
};

// ------------------- Base Class -------------------
class Person {
protected:
    string name, id;
    int age;
public:
    Person() {}
    Person(string n, int a, string i) {
        if (n.empty()) throw UniversitySystemException("Name cannot be empty.");
        if (a <= 0 || a > 120) throw UniversitySystemException("Invalid age.");
        name = n; age = a; id = i;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << endl;
    }

    virtual float calculatePayment() {
        return 0.0f;
    }

    string getId() { return id; }
};

// ------------------- Student -------------------
class Student : public Person {
protected:
    float cgpa;
    string program;
    string enrolledCourses[MAX_COURSES];
    int courseCount;
public:
    Student() : courseCount(0) {}
    Student(string n, int a, string i, float c, string prog)
        : Person(n, a, i), program(prog), courseCount(0) {
        if (c < 0.0 || c > 10.0) throw UniversitySystemException("CGPA must be between 0.0 and 10.0.");
        cgpa = c;
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Program: " << program << ", CGPA: " << cgpa << endl;
    }

    float calculatePayment() {
        return 12000.0f;
    }

    void enrollInCourse(string courseCode) {
        if (courseCount < MAX_COURSES) {
            enrolledCourses[courseCount++] = courseCode;
        } else {
            throw EnrollmentException("Student has reached course limit.");
        }
    }
};

class UndergraduateStudent : public Student {
    string major, minor;
public:
    UndergraduateStudent(string n, int a, string i, float c, string prog, string maj, string min)
        : Student(n, a, i, c, prog), major(maj), minor(min) {}

    void displayDetails() {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << endl;
    }
};

class GraduateStudent : public Student {
    string researchTopic, thesisTitle;
    string advisorId;
public:
    GraduateStudent(string n, int a, string i, float c, string prog, string res, string thesis, string advisor)
        : Student(n, a, i, c, prog), researchTopic(res), thesisTitle(thesis), advisorId(advisor) {}

    void displayDetails() {
        Student::displayDetails();
        cout << "Research: " << researchTopic << ", Thesis: " << thesisTitle << ", Advisor: " << advisorId << endl;
    }
};

// ------------------- Professor -------------------
class Professor : public Person {
protected:
    string department;
public:
    Professor() {}
    Professor(string n, int a, string i, string dept)
        : Person(n, a, i), department(dept) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Department: " << department << endl;
    }

    float calculatePayment() {
        return 40000.0f;
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, string i, string dept)
        : Professor(n, a, i, dept) {}

    float calculatePayment() { return 35000.0f; }
};

class AssociateProfessor : public Professor {
public:
    AssociateProfessor(string n, int a, string i, string dept)
        : Professor(n, a, i, dept) {}

    float calculatePayment() { return 45000.0f; }
};

class FullProfessor : public Professor {
public:
    FullProfessor(string n, int a, string i, string dept)
        : Professor(n, a, i, dept) {}

    float calculatePayment() { return 60000.0f; }
};

// ------------------- Course -------------------
class Course {
    string code, title;
    int credits;
    string description;
    string instructorId;
public:
    Course() {}
    Course(string c, string t, int cr, string desc, string instructor) {
        if (cr <= 0) throw UniversitySystemException("Credits must be positive.");
        code = c; title = t; credits = cr; description = desc; instructorId = instructor;
    }

    void displayCourse() {
        cout << "Course: " << code << ", Title: " << title << ", Credits: " << credits << endl;
    }

    string getCode() { return code; }
};

// ------------------- GradeBook -------------------
class GradeBook {
    string studentIds[MAX_STUDENTS];
    float grades[MAX_STUDENTS];
    int count;
public:
    GradeBook() : count(0) {}

    void addGrade(string id, float g) {
        if (g < 0.0 || g > 100.0) throw GradeException("Invalid grade entry.");
        studentIds[count] = id;
        grades[count++] = g;
    }

    float calculateAverageGrade() {
        float total = 0;
        for (int i = 0; i < count; i++) total += grades[i];
        return count ? total / count : 0;
    }

    void getFailingStudents() {
        cout << "Failing Students:\n";
        for (int i = 0; i < count; i++) {
            if (grades[i] < 40) cout << studentIds[i] << " with grade " << grades[i] << endl;
        }
    }
};

// ------------------- EnrollmentManager -------------------
class EnrollmentManager {
    string enrollments[MAX_COURSES][MAX_STUDENTS];
    int studentCounts[MAX_COURSES];
public:
    EnrollmentManager() {
        for (int i = 0; i < MAX_COURSES; i++) studentCounts[i] = 0;
    }

    void enrollStudent(string courseCode, string studentId, int index) {
        if (studentCounts[index] >= MAX_STUDENTS)
            throw EnrollmentException("Course full.");
        enrollments[index][studentCounts[index]++] = studentId;
    }

    int getEnrollmentCount(int index) {
        return studentCounts[index];
    }
};

// ------------------- UniversitySystem -------------------
class UniversitySystem {
public:
    void run() {
        try {
            UndergraduateStudent u("Alice", 20, "S101", 8.5, "B.Tech", "CS", "Math");
            FullProfessor p("Dr. Sharma", 55, "P201", "CS");
            Course c("CS101", "OOP", 4, "Intro to OOP", p.getId());

            GradeBook gb;
            gb.addGrade("S101", 89);
            gb.addGrade("S102", 34);

            u.enrollInCourse("CS101");

            cout << "--- Student ---\n";
            u.displayDetails();
            cout << "Payment: Rs. " << u.calculatePayment() << endl;

            cout << "--- Professor ---\n";
            p.displayDetails();
            cout << "Payment: Rs. " << p.calculatePayment() << endl;

            cout << "--- Course ---\n";
            c.displayCourse();

            cout << "--- Grades ---\n";
            gb.getFailingStudents();
            cout << "Average Grade: " << gb.calculateAverageGrade() << endl;

        } catch (UniversitySystemException& e) {
            cout << "Exception: " << e.what() << endl;
        }
    }
};

// ------------------- Main -------------------
int main() {
    UniversitySystem system;
    system.run();
    return 0;
}