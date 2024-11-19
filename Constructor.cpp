#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char *name;
    int rollNumber;
    char *studentClass;
    char division;
    char *dob;  
    char bloodGroup[5];
    char *contactAddress;
    char *telephoneNumber;
    char *drivingLicenseNumber;

public:

    Student() {
        name = nullptr;
        studentClass = nullptr;
        dob = nullptr;
        contactAddress = nullptr;
        telephoneNumber = nullptr;
        drivingLicenseNumber = nullptr;
        rollNumber = 0;
        division = '\0';
        strcpy(bloodGroup, "N/A");
        cout << "Default constructor called!" << endl;
    }

    Student(const char *n, int r, const char *c, char div, const char *d, const char *bg, 
            const char *addr, const char *tel, const char *license) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        
        studentClass = new char[strlen(c) + 1];
        strcpy(studentClass, c);
        
        dob = new char[strlen(d) + 1];
        strcpy(dob, d);
        
        contactAddress = new char[strlen(addr) + 1];
        strcpy(contactAddress, addr);
        
        telephoneNumber = new char[strlen(tel) + 1];
        strcpy(telephoneNumber, tel);
        
        drivingLicenseNumber = new char[strlen(license) + 1];
        strcpy(drivingLicenseNumber, license);
        
        rollNumber = r;
        division = div;
        strcpy(bloodGroup, bg);

        cout << "Parameterized constructor called!" << endl;
    }

    Student(const Student &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);

        studentClass = new char[strlen(s.studentClass) + 1];
        strcpy(studentClass, s.studentClass);

        dob = new char[strlen(s.dob) + 1];
        strcpy(dob, s.dob);

        contactAddress = new char[strlen(s.contactAddress) + 1];
        strcpy(contactAddress, s.contactAddress);

        telephoneNumber = new char[strlen(s.telephoneNumber) + 1];
        strcpy(telephoneNumber, s.telephoneNumber);

        drivingLicenseNumber = new char[strlen(s.drivingLicenseNumber) + 1];
        strcpy(drivingLicenseNumber, s.drivingLicenseNumber);

        rollNumber = s.rollNumber;
        division = s.division;
        strcpy(bloodGroup, s.bloodGroup);

        cout << "Copy constructor called!" << endl;
    }

    ~Student() {
        delete[] name;
        delete[] studentClass;
        delete[] dob;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicenseNumber;
        cout << "Destructor called for student: " << name << endl;
    }

    static void showClassInfo() {
        cout << "This class manages student information." << endl;
    }

    friend class Admin;

    inline void displayStudentDetails() {
        cout << "Student Details: " << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNumber << endl;
    }
    
    void inputDetails(const char *n, int r, const char *c, char div, const char *d, const char *bg, 
                      const char *addr, const char *tel, const char *license) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        studentClass = new char[strlen(c) + 1];
        strcpy(studentClass, c);

        dob = new char[strlen(d) + 1];
        strcpy(dob, d);

        contactAddress = new char[strlen(addr) + 1];
        strcpy(contactAddress, addr);

        telephoneNumber = new char[strlen(tel) + 1];
        strcpy(telephoneNumber, tel);

        drivingLicenseNumber = new char[strlen(license) + 1];
        strcpy(drivingLicenseNumber, license);

        rollNumber = r;
        division = div;
        strcpy(bloodGroup, bg);
    }

    void deleteDetails() {
        delete[] name;
        delete[] studentClass;
        delete[] dob;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicenseNumber;
    }
};

class Admin {
public:
    void modifyStudentDetails(Student &s, const char *newAddress, const char *newTelephone) {
        s.contactAddress = new char[strlen(newAddress) + 1];
        strcpy(s.contactAddress, newAddress);
        
        s.telephoneNumber = new char[strlen(newTelephone) + 1];
        strcpy(s.telephoneNumber, newTelephone);
    }
};
int main() {
    
    Student::showClassInfo();
	  
    Student s1("Ratnesh Patil", 101, "MCA", 'A', "05-05-2004", "AB-", "At Pen ", "7096119***", "MH12345");
    s1.displayStudentDetails();

    Student s2;
    s2.displayStudentDetails();

    
    Student s3 = s1;
    s3.displayStudentDetails();

    
    Admin admin;
    admin.modifyStudentDetails(s1, "Pen Washi", "1122334455");
    s1.displayStudentDetails();

    
    s1.deleteDetails();
    s3.deleteDetails();

    return 0;
}