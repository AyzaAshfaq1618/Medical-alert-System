#include <iostream>
#include <vector>
#include <string>

class MedicalAlert {
private:
    std::vector<std::string> alerts;

public:
    void sendAlert(const std::string& alertType, const std::string& location) {
        std::string alertMessage = "Medical Alert: " + alertType + " at " + location;
        alerts.push_back(alertMessage);
        std::cout << alertMessage << std::endl;
        // call the new function to email notification 
        sendEmailNotification(alertMessage);
    }

    void viewAlerts() const {
        std::cout << "\nSent Alerts:\n";
        if (alerts.empty()) {
            std::cout << "No alerts sent yet.\n";
            return;
        }
        for (const auto& alert : alerts) {
            std::cout << alert << std::endl;
        }
}
private:
    void sendEmailNotification(const std::string& message) {
        // This is a placeholder for email sending logic
        std::cout << "Sending email notification: " << message << std::endl;
    }
};

int main() {
    MedicalAlert system;
    int choice;

    do {
        std::cout << "\nMedical Alert System\n";
        std::cout << "1. Send Medical Alert\n";
        std::cout << "2. View Sent Alerts\n";
        std::cout << "3. Exit\n";
        
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string alertType, location;
            std::cout << "Enter alert type (e.g., Cardiac Arrest, Stroke): ";
            std::cin.ignore(); // Clear newline from input buffer
            std::getline(std::cin, alertType);
            std::cout << "Enter location: ";
            std::getline(std::cin, location);
            system.sendAlert(alertType, location);
        } else if (choice == 2) {
            system.viewAlerts();
        } else if (choice != 3) {
            std::cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}


