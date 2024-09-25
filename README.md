Supermarket-management-billing-system
This project is a console-based Supermarket Billing System built using C++. The system allows users to perform essential shopping-related tasks, such as adding and modifying products, viewing available products, and generating a receipt for purchased products. The system is designed with both buyers and administrators in mind, providing them with a simple menu-driven interface.

Features
1. Administrator Section:
Login Authentication: The administrator can log in using a predefined email and password to access various administrative functions.
Product Management:
Add Products: Add new products to the supermarket database, including product code, name, price, and discount.
Edit Products: Modify existing product details such as product code, name, price, and discount.
Delete Products: Remove a product from the supermarket's database.
View Products: Display the list of available products with their details.
2. Buyer Section:
Purchase Products: The buyer can browse the product list and select items to purchase by entering the product code and quantity.
Generate Receipt: After selecting products, the system generates a receipt showing the product details, quantity, price, total amount, and discounts.
View Total Amount: The total payable amount with discounts applied is calculated and shown to the buyer.
3. Main Menu:
Administrator Access: Administrators can log in to manage products.
Buyer Access: Buyers can view available products and make purchases.
Exit: Option to exit the program.
Code Overview
The project consists of a single class shopping that encapsulates all the functionality related to both buyers and administrators. Below is an overview of the key functions:

menu(): Displays the main menu with options for buyers, administrators, and exiting the system.
administrator(): Provides access to administrative functions like adding, editing, or deleting products.
buyer(): Allows buyers to make product purchases and generate receipts.
receipt(): Generates and displays a detailed receipt for the buyer's order.
add(), edit(), rem(): Functions for adding, editing, and deleting products in the system.
list(): Displays the list of available products with their details (product code, name, and price).
Usage
Administrator Access:

Enter the administrator email (inform.gaurav449@gmail.com) and password (gaurav123) to log in.
Once logged in, you can add, edit, or delete products from the product database.
Buyer Access:

Select the buyer option from the main menu.
View the list of available products and make a purchase by entering the product code and quantity.
The system will display a receipt with the total amount, including any discounts applied.
Exit:

Select the exit option to close the program.
Files
database.txt: The file where all the product information (code, name, price, discount) is stored.
Installation
Clone the repository:
bash
Copy code
git clone https://github.com/your-username/supermarket-billing-system.git
Compile the program using any C++ compiler, such as g++:
bash
Copy code
g++ supermarket_billing.cpp -o supermarket_billing
Run the executable:
bash
Copy code
./supermarket_billing
Future Improvements
Add more robust authentication and security features.
Improve error handling and validation for user inputs.
Implement a more efficient file management system.
Add graphical user interface (GUI) for easier interaction.
License
This project is open-source and available under the MIT License.
