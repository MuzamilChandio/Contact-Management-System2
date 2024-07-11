#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Contact class definition
class Contact {
private:
    string name;
    string phoneNumber;

public:
    // Constructor
    Contact(string n, string p) : name(n), phoneNumber(p) {}

    // Getters
    string getName() const {
        return name;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }

    // Display function
    void displayContact() const {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
    }
};

// Function prototypes
void addContact(vector<Contact>& contacts);
void viewContacts(const vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);
void showMenu();

int main() {
    vector<Contact> contacts;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                deleteContact(contacts);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

void addContact(vector<Contact>& contacts) {
    string name, phoneNumber;
    cout << "Enter name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);

    Contact newContact(name, phoneNumber);
    contacts.push_back(newContact);
    cout << "Contact added successfully!" << endl;
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available." << endl;
    } else {
        cout << "Contact List:" << endl;
        for (const auto& contact : contacts) {
            contact.displayContact();
        }
    }
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts available to delete." << endl;
        return;
    }

    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore(); // Clear input buffer
    getline(cin, name);

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->getName() == name) {
            contacts.erase(it);
            cout << "Contact deleted successfully!" << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

void showMenu() {
    cout << "\nContact Management System" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. View Contacts" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    
}
