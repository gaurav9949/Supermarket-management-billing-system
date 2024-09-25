#include <iostream>
#include <fstream>
using namespace std;

// Class declaration for shopping
class shopping
{
private:
    string pname;
    int pcode;
    float dis;
    float price;

public:
    void menu();
    void buyer();
    void administrator();
    void receipt();
    void rem();
    void edit();
    void add();
    void list();
};

// Function definition for the menu
void shopping::menu()
{
m:
    int choice;
    // For login access
    string email;
    string password;
    cout << "\t\t\t__________________________________\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t     Super Market Main Menu       \n";
    cout << "\t\t\t__________________________________\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t|  1) Administrator   |\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t|  2) Buyer           |\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t|  3) Exit            |\n";
    cout << "\t\t\t                                  \n";
    cout << "\t\t\t Please! Select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t    Gaurav Supermart Welcomes you 🙏🏼\n";
        cout << "\t\t\t      Login required:\n";
        cout << "\t\t\t\t    Enter Email\n";
        cin >> email;
        cout << "\t\t\t\t Enter Password\n";
        cin >> password;
        if (email == "inform.gaurav449@gmail.com" && password == "gaurav123")
        {
            administrator();
        }
        else
        {
            cout << "Invalid email or password" << endl;
        }
        break;

    case 2:
        buyer();
        break;

    case 3:
        exit(0);

    default:
        cout << "Please enter a valid option!" << endl;
    }

    goto m; // Jump back to the menu
}

void shopping ::administrator()
{
m:
    int choice;
    cout << "\n\n\t\t\ ADMINSTATOR MENU ";
    cout << "\n\t\t\ | 1) ADD PRODUCT  |";
    cout << "\n\t\t\ |                 |";
    cout << "\n\t\t\ | 2) MODIFY PRODUCT|";
    cout << "\n\t\t\ |                   |";
    cout << "\n\t\t\ | 3) DELETE  PRODUCT|";
    cout << "\n\t\t\ |                   |";
    cout << "\n\t\t\ | 4)BACK TO MAIN MENU|";
    cout << "\n";
    cout << "\n\n\t\t\ PLease select! ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Enter the valid option " << endl;
    }
    goto m;
}
void shopping ::buyer()
{

    int choice;
    cout << "\n\n\t\t Buyer";
    cout << "______________\n";
    cout << "\n\n\t\t 1)Buy product";
    cout << "                 \n";
    cout << "\n\n\t\t 2) Go back";
    cout << "\t\t\t\t Enter your choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Please enter a valid option";
    }
   
}
void shopping ::add()
{

m:
    fstream data;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t  Add new product";
    cout << "\n\n\t Product code of the product ";
    cin >> pcode;
    cout << "\n\n\t Name of the product";
    cin >> pname;
    cout << "\n\n\t Price of the product";
    cin >> price;
    cout << "\n\n\t Discount on the product";
    cin >> dis;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << "  " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
        goto m;
    else
    {
        data.open("database.txt", ios::app | ios ::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";

        data.close();
    }
    cout << "\n\n\t\t Record inserted !";
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Modify the record:";
    cout << "\n\t\t\t Product code";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesnt exist !";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code!";
                cin >> c;
                cout << "\n\n\t Name of the product";
                cin >> n;
                cout << "\n\t\t Price ";
                cin >> p;
                cout << "\n\t\ Discount";
                cin >> d;
                data1 << "" << c << "" << n << "" << p << "" << d << "\n";
                token++;
            }
            else
            {
                data1 << "" << pcode << "" << pname << "" << price << "" << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}
void shopping ::rem()

{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "file doesnt exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted suceesfully";
                token++;
            }
            else
            {
                data1 << "" << pcode << "" << pname << " " << price << "" << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n|______________________________|";
    cout << "ProNo\t\t Name\t\t Price\n";
    cout << "\n\n|______________________________|";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}
void shopping::receipt() {
    fstream data;
    int arrc[100];  // Array to store product codes
    int arrq[100];  // Array to store quantities
    char choice;    // Variable to store user choice for purchasing more items
    int c = 0;      // Counter for items
    float amount = 0, discount = 0, total = 0;

    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("database.txt", ios::in);  // Corrected file name
    if (!data) {
        cout << "\n\n Empty database";
    } else {
        data.close();
        list();  // Display available products
        cout << "\n__________________________________________\n";
        cout << "PLEASE PLACE YOUR ORDER\n";
        cout << "__________________________________________\n";

        do {
            cout << "\n\n Enter the product code: ";
            cin >> arrc[c];
            cout << "Enter the product quantity: ";
            cin >> arrq[c];

            bool duplicate = false;
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code. Please try again.\n";
                    duplicate = true;  // Flag duplicate code
                    break;
                }
            }

            if (!duplicate) {
                c++;  // Only increment if no duplicate was found
            }

            cout << "\n\n Do you want to buy another product? (y/n): ";
            cin >> choice;
        } while (choice == 'y');  // Continue while user wants to buy more products

        cout << "\n\n\t\t _______________________Receipt_____________\n";
        cout << "\nProduct No\tProduct Name\tQuantity\tPrice\tAmount\tAmount with Discount\n";

        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];            // Calculate total amount
                    discount = amount - (amount * dis / 100);  // Apply discount
                    total += discount;

                    // Display product details
                    cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t"
                         << price << "\t" << amount << "\t\t" << discount << "\n";
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }

        cout << "\n\n____________________________________";
        cout << "\n Total Amount: " << total << "\n";
    }
}


int main(){
    shopping s;
    s.menu();
}