# Vending Machine (C++) - Data Structures Project

This project is a simple vending machine simulation written in C++ as part of a Data Structures course.

The vending machine contains a 3x3 grid of items, each with a name, code, price, and stock quantity. The program allows the user to:  
- View all available items with their codes, prices, and stock.  
- Select an item by entering its code.  
- Purchase an item if it is in stock (stock decreases after purchase).  
- Receive a message if the item is out of stock or if the entered code is invalid.  

Stock for each item can be set in the program using the `push` function. The machine decreases the stock using the `pop` function after a purchase.
