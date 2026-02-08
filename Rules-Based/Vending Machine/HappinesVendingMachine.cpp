#include <iostream>
#include <string>
#include <iomanip> // For setprecision
using namespace std;

const int MAX = 3;

class VendingMachine {

private:
    // Define an Item structure to hold name, price, code, and quantity
    struct Item {
        string name;
        int code;
        double price;
        int quantity;
    };

    Item items[MAX][MAX];  // 2D array for items 3*3


public:
    VendingMachine();  // Constructor to initialize items
    void displayItems();  // Display all items
    void selectItem(int code);  // Select and purchase an item by code
    void push(int row, int col, int quantity);  // Set stock for an item
    void pop(int row, int col);  // Decrease stock for an item 
};


// Constructor: Initialize the vending machine items with stock of 0
VendingMachine::VendingMachine() {

    items[0][0] = { " Chocolate Milk ", 101, 2.00, 0 };  //set 0 default quantity = 0
    items[0][1] = { "Strawberry Milk ", 102, 2.00, 0 };
    items[0][2] = { "     Juice      ", 103, 1.50, 0 };
    items[1][0] = { "     Chips      ", 201, 1.20, 0 };
    items[1][1] = { "     Candy      ", 202, 0.80, 0 };
    items[1][2] = { "     Water      ", 203, 1.00, 0 };
    items[2][0] = { "    Cookies     ", 301, 1.50, 0 };
    items[2][1] = { "Galaxy Chocolate", 302, 2.00, 0 };
    items[2][2] = { "     Crackers   ", 303, 1.20, 0 };
}


// Display all items in the vending machine
void VendingMachine::displayItems() {

    cout << "\nHAPPINESS VENDING MACHINE\n\n";

    for (int i = 0; i < MAX; i++) { //row
        for (int j = 0; j < MAX; j++) { //column

            cout << "(" + items[i][j].name + ")   "
                << items[i][j].code
                << "   ($" << fixed << setprecision(2) << items[i][j].price << ")  ";
        }
        cout << endl;
    }
}


// Select an item by its code
void VendingMachine::selectItem(int code) {

    for (int i = 0; i < MAX; i++) { //row
        for (int j = 0; j < MAX; j++) { //column

            if (items[i][j].code == code) { // check if selected code is code in machine 

                if (items[i][j].quantity > 0) { // Check if the item is in stock

                    cout << "You selected: " << items[i][j].name << " ($" << items[i][j].price << ")\n";

                    pop(i, j);  // Call pop to decrement the quantity in stock

                    cout << "Thank you for your purchase!\n";
                }

                else
                    cout << "Sorry, " << items[i][j].name << " is out of stock!\n";

                return;  // Exit after processing
            }
        }
    }

    cout << "Invalid code! Please try again.\n";
}


// Push: Set stock for a specific item
void VendingMachine::push(int row, int col, int quantity) {
    if (quantity > 10) {
        quantity = 10; // Cap the quantity at 10
    }
    items[row][col].quantity = quantity; // Set item stock
}


// Pop: Decrease the stock of an item 
void VendingMachine::pop(int row, int col) {

    if (items[row][col].quantity > 0) { // Check if stock is available
        items[row][col].quantity--;  // Decrease stock
    }
}


// Main function
int main() {

    VendingMachine vm; // Create vending machine object
    int choice;

    // Set stock for specific items using push

    vm.push(0, 0, 2);  // Set 2 Chocolate Milk
    vm.push(0, 1, 2);  // Set 2 Strawberry Milk
    vm.push(0, 2, 1);  // Set 1 Juice 
    vm.push(1, 0, 3);  // Set 3 Chips
    vm.push(1, 1, 2);  // Set 2 Candy
    vm.push(1, 2, 1);  // Set 1 Water
    vm.push(2, 0, 2);  // Set 2 Cookies
    vm.push(2, 1, 1);  // Set 1 Galaxy Chocolate
    vm.push(2, 2, 0);  // Crackers remain out of stock as initialized


    while (true) {

        vm.displayItems();  // call displayItems to display items

        cout << "\nEnter the item code to purchase (or 0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Thank you for using the vending machine. Goodbye!\n";
            break;
        }

        vm.selectItem(choice);  // Process the selection
    }

    return 0;
}
