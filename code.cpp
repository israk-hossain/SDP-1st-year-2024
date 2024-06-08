#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

class User {            
protected:
    string name;
    string email;
    string phoneNumber;
    string password;
public:
    virtual bool login() = 0;
    virtual void inputData() = 0;
    virtual ~User() {}
};

class Admin : public User {
public:
    bool login() override {
        string adminEmail = "bubt@gmail.com";
        string adminPassword = "bubt52";

        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t     CAR RENTAL SYSTEM \n\n";
        cout << "\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t\t     ADMIN LOGIN \n";
        cout << "\t\t\t\t\t------------------------------\n\n";
        cout << "\t\t\t\t\tEnter Email: ";
        cin >> email;
        cout << "\t\t\t\t\tEnter Password: ";
        cin >> password;
        cout << endl;

        if (email == adminEmail && password == adminPassword) {
            cout << "\n\n\t\t\t\t\t\t\tAccess Granted...\n\n";
            return true;
        } else {
            cout << "\n\n\t\t\t\t\t\t\tAccess Denied...\n\n";
            return false;
        }
    }

    void inputData() override {
        cout << "Admin functionality...";
    }

    void viewRentDetails() {
        ifstream rentFile("rent.json");
        if (rentFile.is_open()) {
            string line;
            while (getline(rentFile, line)) {
                cout << line << endl;
            }
            rentFile.close();
        } else {
            cout << "Unable to open rent.json file." << endl;
        }
    }
};

class Customer : public User {
public:
    bool login() override {
        return true;
    }

    void inputData() override {
    }
};

class Rent : public Customer {
public:
    int days = 0, rentalfee = 0;
    string carmodel;
    string carnumber;

    void inputData() override {
        cout << "\t\t\t\tPlease Enter your Name: ";
        cin.ignore();
        getline(cin, name); 
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Email: ";
        cin>>email;
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Phone Number: ";
        cin >> phoneNumber;
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Password: ";
        cin >> password;
        cout << endl;

        // Car selection
        selectCar();
        
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide following information: " << endl;
        cout << "Please select a Car No. : ";
        cin >> carnumber;
        cout << "Number of days you wish to rent the car : ";
        cin >> days;
        cout << endl;
    }

    void calculate() {
        // Rent calculation
        sleep(1);
        cout << "Calculating rent. Please wait......" << endl;
        sleep(2);

        if (carmodel == "1")
            rentalfee = days * 5600;
        else if (carmodel == "2")
            rentalfee = days * 5000;
        else if (carmodel == "3")
            rentalfee = days * 7500;
        else if (carmodel == "4")
            rentalfee = days * 6000;
        else if (carmodel == "5")
            rentalfee = days * 5500;
        else if (carmodel == "6")
            rentalfee = days * 6800;
        else if (carmodel == "7")
            rentalfee = days * 5200;
        else if (carmodel == "8")
            rentalfee = days * 4800;
        else if (carmodel == "9")
            rentalfee = days * 5700;
        else if (carmodel == "10")
            rentalfee = days * 5300;
        else if (carmodel == "11")
            rentalfee = days * 6100;
        else if (carmodel == "12")
            rentalfee = days * 5900;
        else if (carmodel == "13")
            rentalfee = days * 5500;
        // Add rental fee calculation for the new cars
    }

    void displayCarDetails() {
        // Display car details
        if (carmodel == "1") {
            cout << "Tesla Model 2011 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5600 taka" << endl;
        } else if (carmodel == "2") {
            cout << "Hyundai Model 2015 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5000 taka" << endl;
        } else if (carmodel == "3") {
            cout << "Ford Model 2017 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 7500 taka" << endl;
        } else if (carmodel == "4") {
            cout << "Tesla Model S Plaid Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 6000 taka" << endl;
        } else if (carmodel == "5") {
            cout << "Porsche Taycan Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5500 taka" << endl;
        } else if (carmodel == "6") {
            cout << "Audi e-tron GT Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 6800 taka" << endl;
        } else if (carmodel == "7") {
            cout << "Ford Mustang Mach-E Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5200 taka" << endl;
        } else if (carmodel == "8") {
            cout << "BMW i4 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 4800 taka" << endl;
        } else if (carmodel == "9") {
            cout << "Mercedes-Benz EQS Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
                        cout << "Price per day: 5700 taka" << endl;
        } else if (carmodel == "10") {
            cout << "Lucid Air Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5300 taka" << endl;
        } else if (carmodel == "11") {
            cout << "Chevrolet Bolt EUV Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 6100 taka" << endl;
        } else if (carmodel == "12") {
            cout << "Rivian R1T Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5900 taka" << endl;
        } else if (carmodel == "13") {
            cout << "Hyundai Ioniq 5 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5500 taka" << endl;
        }
    }

    void showRent() {
        // Generate a random invoice number
        srand(time(0));
        int invoiceNo = rand() % 1000000 + 1;

        // Display rent details
        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t    ///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t    | Invoice No. :------------------|" << setw(10) << "#" << invoiceNo << " |" << endl;
        cout << "\t\t    | Customer Name:-----------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t    | Customer Email:----------------|" << setw(10) << email << " |" << endl;
        cout << "\t\t    | Customer Phone Number :--------|" << setw(10) << phoneNumber << " |" << endl;
        cout << "\t\t    | Car Model :--------------------|" << setw(10) << carmodel << " |" << endl;
        cout << "\t\t    | Car No. :----------------------|" << setw(10) << carnumber << " |" << endl;
        cout << "\t\t    | Number of days :---------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t    | Your Rental Amount is :--------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t    | Caution Money :----------------|" << setw(10) << "0" << " |" << endl;
        cout << "\t\t    | Advanced :---------------------|" << setw(10) << "0" << " |" << endl;
        cout << "\t\t     ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t    | Total Rental Amount is :-------|" << setw(10) << rentalfee << " |" << endl;
        cout << "\t\t ________________________________________________________" << endl;
        cout << "\t\t # This is a computer generated invoice and it does not" << endl;
        cout << "\t\t require an authorised signature #" << endl;
        cout << " " << endl;
        cout << "\t\t ///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t You are advised to pay up the amount before the due date." << endl;
        cout << "\t\t Otherwise, a penalty fee will be applied" << endl;
        cout << "\t\t ///////////////////////////////////////////////////////////" << endl;
        sleep(2);
        cout << "Thank you for choosing our Car Rental Service!" << endl;

        // Save rent information to a file
        ofstream rentFile("rent.json", ios::app);
        rentFile << "{\n"
                 << "\t\"InvoiceNo\": " << invoiceNo << ",\n"
                 << "\t\"CustomerName\": \"" << name << "\",\n"
                 << "\t\"CustomerEmail\": \"" << email << "\",\n"
                 << "\t\"CustomerPhoneNumber\": \"" << phoneNumber << "\",\n"
                 << "\t\"CarModel\": \"" << carmodel << "\",\n"
                 << "\t\"CarNumber\": \"" << carnumber << "\",\n"
                 << "\t\"DaysRented\": " << days << ",\n"
                 << "\t\"RentalFee\": " << rentalfee << "\n"
                 << "}\n\n";
        rentFile.close();
    }

    void selectCar() {
        do {
            cout << "\t\t\t\tPlease Select a Car" << endl;
            cout << "\t\t\t\tEnter '1' for Tesla Model 2011." << endl;
            cout << "\t\t\t\tEnter '2' for Hyundai Model 2015." << endl;
            cout << "\t\t\t\tEnter '3' for Ford Model 2017." << endl;
            cout << "\t\t\t\tEnter '4' for Tesla Model S Plaid." << endl;
            cout << "\t\t\t\tEnter '5' for Porsche Taycan." << endl;
            cout << "\t\t\t\tEnter '6' for Audi e-tron GT." << endl;
            cout << "\t\t\t\tEnter '7' for Ford Mustang Mach-E." << endl;
            cout << "\t\t\t\tEnter '8' for BMW i4." << endl;
            cout << "\t\t\t\tEnter '9' for Mercedes-Benz EQS." << endl;
            cout << "\t\t\t\tEnter '10' for Lucid Air." << endl;
            cout << "\t\t\t\tEnter '11' for Chevrolet Bolt EUV." << endl;
            cout << "\t\t\t\tEnter '12' for Rivian R1T." << endl;
            cout << "\t\t\t\tEnter '13' for Hyundai Ioniq 5." << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            if (carmodel == "1") {
                cout << "You have chosen Tesla Model 2011" << endl;
                displayCarDetails();
            } else if (carmodel == "2") {
                cout << "You have chosen Hyundai Model 2015" << endl;
                displayCarDetails();
            } else if (carmodel == "3") {
                cout << "You have chosen Ford Model 2017" << endl;
                displayCarDetails();
            } else if (carmodel == "4") {
                cout << "You have chosen Tesla Model S Plaid" << endl;
                displayCarDetails();
            } else if (carmodel == "5") {
                cout << "You have chosen Porsche Taycan" << endl;
                displayCarDetails();
            } else if (carmodel == "6") {
                cout << "You have chosen  Audi e-tron GT" << endl;
                displayCarDetails();
            } else if (carmodel == "7") {
                cout << "You have chosen Ford Mustang Mach-E" << endl;
                displayCarDetails();
            } else if (carmodel == "8") {
                cout << "You have chosen BMW i4" << endl;
                displayCarDetails();
            } else if (carmodel == "9") {
                cout << "You have chosen Mercedes-Benz EQS" << endl;
                displayCarDetails();
            } else if (carmodel == "10") {
                cout << "You have chosen Lucid Air" << endl;
                displayCarDetails();
            } else if (carmodel == "11") {
                cout << "You have chosen Chevrolet Bolt EUV" << endl;
                displayCarDetails();
            } else if (carmodel == "12") {
                cout << "You have chosen Rivian R1T" << endl;
                displayCarDetails();
            } else if (carmodel == "13") {
                cout << "You have chosen Hyundai Ioniq 5" << endl;
                displayCarDetails();
            } else {
                cout << "Invalid Car Model. Please try again!" << endl;
            }
            sleep(2);
        } while (carmodel != "1" && carmodel != "2" && carmodel != "3" && carmodel != "4" && carmodel != "5" &&
                 carmodel != "6" && carmodel != "7" && carmodel != "8" && carmodel != "9" && carmodel != "10" &&
                 carmodel != "11" && carmodel != "12" && carmodel != "13");
    }
};
class welcome {
public:
    void displayWelcomeMessage() {
        system("clear");
        cout << "\nWelcome to the Car Rental System!" << endl;
        sleep(2);
        cout << "\nStarting the program, please wait....." << endl;
        sleep(1);
        cout << "\nLoading up files....." << endl;
        sleep(1);
    }
};

int main() {
    welcome welcomeMessage;
    welcomeMessage.displayWelcomeMessage();
    system("clear");
    // Choose whether admin or customer
    cout << "Are you an admin or a customer?" << endl;
    cout << "Enter '1' for admin,'2' for customer: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Admin admin;
        if (admin.login()) {
            admin.inputData();
            admin.viewRentDetails();
        }
    } else if (choice == 2) {
        Rent rent;
        if (rent.login()) {
            rent.inputData();
            rent.calculate();
            rent.showRent();
        }
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
