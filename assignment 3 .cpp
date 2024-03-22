#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Class representing an inventory item
class InventoryItem {
private:
    string name;
    int quantity;

public:
    InventoryItem(string _name, int _quantity) : name(_name), quantity(_quantity) {}

    // Function to add quantity to the inventory item
    void addQuantity(int amount) {
        if (amount < 0) {
            throw invalid_argument("Quantity to add must be non-negative.");
        }
        quantity += amount;
    }

    // Function to reduce quantity from the inventory item
    void reduceQuantity(int amount) {
        if (amount < 0) {
            throw invalid_argument("Quantity to reduce must be non-negative.");
        }
        if (amount > quantity) {
            throw invalid_argument("Insufficient quantity in inventory.");
        }
        quantity -= amount;
    }

    // Function to get the quantity of the item
    int getQuantity() const {
        return quantity;
    }
};

// Class representing the Inventory module
class InventoryModule {
private:
    vector<InventoryItem> inventory;

public:
    // Function to add an item to inventory
    void addItem(string name, int quantity) {
        inventory.push_back(InventoryItem(name, quantity));
    }

    // Function to add quantity to an existing item
    void addQuantity(string name, int amount) {
        for (auto& item : inventory) {
            if (item.getName() == name) {
                item.addQuantity(amount);
                return;
            }
        }
        throw invalid_argument("Item not found in inventory.");
    }

    // Function to reduce quantity from an existing item
    void reduceQuantity(string name, int amount) {
        for (auto& item : inventory) {
            if (item.getName() == name) {
                item.reduceQuantity(amount);
                return;
            }
        }
        throw invalid_argument("Item not found in inventory.");
    }

    // Function to get quantity of an item
    int getItemQuantity(string name) {
        for (const auto& item : inventory) {
            if (item.getName() == name) {
                return item.getQuantity();
            }
        }
        throw invalid_argument("Item not found in inventory.");
    }
};

// Class representing the Reports module
class ReportsModule {
public:
    // Function to generate a report
    void generateReport() {
        cout << "Generating report..." << endl;
        // Implementation to generate report
    }
};

int main() {
    try {
        // Example usage of InventoryModule
        InventoryModule inventory;
        inventory.addItem("Medicine A", 50);
        inventory.addQuantity("Medicine A", 20);
        inventory.reduceQuantity("Medicine A", 10);
        cout << "Quantity of Medicine A: " << inventory.getItemQuantity("Medicine A") << endl;

        // Example usage of ReportsModule
        ReportsModule reports;
        reports.generateReport();
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
