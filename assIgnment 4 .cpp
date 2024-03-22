#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Class representing a patient
class Patient {
private:
    string name;
    string id;

public:
    Patient(string _name, string _id) : name(_name), id(_id) {}

    string getName() const {
        return name;
    }

    string getID() const {
        return id;
    }
};

// Class representing a consultation
class Consultation {
private:
    string patientID;
    string doctorName;
    string description;

public:
    Consultation(string _patientID, string _doctorName, string _description)
        : patientID(_patientID), doctorName(_doctorName), description(_description) {}

    string getPatientID() const {
        return patientID;
    }

    string getDoctorName() const {
        return doctorName;
    }

    string getDescription() const {
        return description;
    }
};

// Class representing the Consultation module
class ConsultationModule {
private:
    vector<Consultation> consultations;

public:
    // Function to schedule a consultation
    void scheduleConsultation(string patientID, string doctorName, string description) {
        consultations.push_back(Consultation(patientID, doctorName, description));
    }
};

// Class representing the Physical module
class PhysicalModule {
public:
    // Function to perform physical examination
    void performExamination(string patientID) {
        cout << "Performing physical examination for patient with ID: " << patientID << endl;
        // Implementation to perform examination
    }
};

// Class representing the Dental module
class DentalModule {
public:
    // Function to perform dental check-up
    void performCheckup(string patientID) {
        cout << "Performing dental check-up for patient with ID: " << patientID << endl;
        // Implementation to perform check-up
    }
};

int main() {
    try {
        // Example usage of ConsultationModule
        ConsultationModule consultationModule;
        consultationModule.scheduleConsultation("P001", "Dr. Smith", "Regular check-up");

        // Example usage of PhysicalModule
        PhysicalModule physicalModule;
        physicalModule.performExamination("P001");

        // Example usage of DentalModule
        DentalModule dentalModule;
        dentalModule.performCheckup("P002");
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
