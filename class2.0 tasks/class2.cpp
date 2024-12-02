#include <iostream>
using namespace std;

// Task 1: Class Person, Student, and Teacher
class Person {
protected:
    int age;

public:
    void Greet() {
        cout << "Hello!" << endl;
    }

    void SetAge(int age) {
        this->age = age;
    }
};

class Student : public Person {
public:
    void Study() {
        cout << "I'm studying hard!" << endl;
    }

    void ShowAge() {
        cout << "My age is: " << age << " years old" << endl;
    }
};

class Teacher : public Person {
public:
    void Explain() {
        cout << "I'm explaining something." << endl;
    }
};

// Task 2: PhotoBook class
class PhotoBook {
protected:
    int numPages;

public:
    // Default constructor
    PhotoBook() : numPages(16) {} // Default to 16 pages

    // Constructor with specified number of pages
    PhotoBook(int pages) : numPages(pages) {}

    // Method to get the number of pages
    int GetNumberPages() {
        return numPages;
    }
};

class BigPhotoBook : public PhotoBook {
public:
    // Constructor for big photo book
    BigPhotoBook() : PhotoBook(64) {}
};

// PhotoBookTest class for testing
class PhotoBookTest {
public:
    void Test() {
        // Test default constructor
        PhotoBook defaultBook;
        cout << "Default photo book has " << defaultBook.GetNumberPages() << " pages." << endl;

        // Test parameterized constructor
        PhotoBook customBook(24);
        cout << "Custom photo book has " << customBook.GetNumberPages() << " pages." << endl;

        // Test BigPhotoBook constructor
        BigPhotoBook bigBook;
        cout << "Big photo book has " << bigBook.GetNumberPages() << " pages." << endl;
    }
};

// Circuit Resistance Calculator
int CircuitPower(int voltage, int current) {
    return voltage * current;
}

int main() {
    // Test Person, Student, and Teacher
    Student student;
    student.SetAge(20);
    student.Greet();
    student.ShowAge();
    student.Study();

    Teacher teacher;
    teacher.SetAge(40);
    teacher.Greet();
    teacher.Explain();

    // Test PhotoBook classes
    PhotoBookTest photoBookTest;
    photoBookTest.Test();

    // Test CircuitPower
    int voltage = 220;
    int current = 5;
    cout << "The circuit power is: " << CircuitPower(voltage, current) << " watts." << endl;

    return 0;
}