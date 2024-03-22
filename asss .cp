#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declaration of classes
class Administrator;
class Nurse;
class DentalDoctor;

// Class representing a user
class User {
protected:
    string username;
    string password;

public:
    User(string _username, string _password) : username(_username), password(_password) {}

    // Virtual function to perform login
    virtual bool login(string _username, string _password) {
        return (username == _username && password == _password);
    }
};

// Class representing the Administrator user
class Administrator : public User {
public:
    Administrator(string _username, string _password) : User(_username, _password) {}

    // Function to add new users
    void addUser(string username, string password) {
        cout << "User added: " << username << endl;
    }

    // Function to manage reports
    void manageReports() {
        cout << "Reports managed by Administrator." << endl;
    }

    // Function to access all modules
    void accessAllModules() {
        cout << "Administrator accessed all modules." << endl;
    }
};

// Class representing the Nurse user
class Nurse : public User {
public:
    Nurse(string _username, string _password) : User(_username, _password) {}

    // Function to access the physical module
    void accessPhysicalModule() {
        cout << "Nurse accessed Physical module." << endl;
    }

    // Function to read appointments assigned by the nurse
    void readAppointments() {
        cout << "Nurse read appointments." << endl;
    }

    // Function to generate report
    void generateReport() {
        cout << "Nurse generated report." << endl;
    }
};

// Class representing the Dental Doctor user
class DentalDoctor : public User {
public:
    DentalDoctor(string _username, string _password) : User(_username, _password) {}

    // Function to access the dental module
    void accessDentalModule() {
        cout << "Dental Doctor accessed Dental module." << endl;
    }

    // Function to read appointments assigned by the nurse
    void readAppointments() {
        cout << "Dental Doctor read appointments." << endl;
    }

    // Function to generate report
    void generateReport() {
        cout << "Dental Doctor generated report." << endl;
    }
};

// Class representing the Hospital Management System
class HospitalManagementSystem {
private:
    Administrator admin;
    vector<Nurse> nurses;
    vector<DentalDoctor> dentalDoctors;

public:
    HospitalManagementSystem(string adminUsername, string adminPassword) : admin(adminUsername, adminPassword) {}

    // Function to add a nurse
    void addNurse(string username, string password) {
        nurses.push_back(Nurse(username, password));
    }

    // Function to add a dental doctor
    void addDentalDoctor(string username, string password) {
        dentalDoctors.push_back(DentalDoctor(username, password));
    }

    // Function to authenticate user
    User* authenticate(string username, string password) {
        if (admin.login(username, password)) {
            return &admin;
        }
        for (auto& nurse : nurses) {
            if (nurse.login(username, password)) {
                return &nurse;
            }
        }
        for (auto& doctor : dentalDoctors) {
            if (doctor.login(username, password)) {
                return &doctor;
            }
        }
        return nullptr;
    }
};

int main() {
    // Instantiate HospitalManagementSystem
    HospitalManagementSystem hospital("admin", "adminpassword");

    // Add users
    hospital.addNurse("nurse1", "nursepassword");
    hospital.addDentalDoctor("doctor1", "doctorpassword");

    // Authenticate users
    User* user = hospital.authenticate("nurse1", "nursepassword");
    if (user != nullptr) {
        Nurse* nurse = dynamic_cast<Nurse*>(user);
        if (nurse != nullptr) {
            nurse->accessPhysicalModule();
            nurse->readAppointments();
            nurse->generateReport();
        }
    }

    return 0;
}
