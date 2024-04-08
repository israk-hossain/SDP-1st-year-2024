#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

class customer {
public:
    string name;
    string email;
    string phoneNumber;
    string password;
    string carmodel;
    string carnumber;
};

class rent : public customer {
public:
    int days = 0, rentalfee = 0;

    void inputData() {
        login();
        cout << "\t\t\t\tPlease Enter your Name: ";
        cin >> name;
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Email: ";
        cin >> email;
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Phone Number: ";
        cin >> phoneNumber;
        cout << endl;

        cout << "\t\t\t\tPlease Enter your Password: ";
        cin >> password;
        cout << endl;

        do {
            cout << "\t\t\t\tPlease Select a Car" << endl;
            cout << "\t\t\t\tEnter 'A' for Tesla 20011." << endl;
            cout << "\t\t\t\tEnter 'B' for Hyundai 2015." << endl;
            cout << "\t\t\t\tEnter 'C' for Ford 2017." << endl;
            cout << "\t\t\t\tChoose a Car from the above options: ";
            cin >> carmodel;
            cout << endl;

            cout << "--------------------------------------------------------------------------" << endl;
            if (carmodel == "A") {
                system("CLS");
                cout << "You have chosen Tesla model 2011" << endl;
                displayCarDetails();
            } else if (carmodel == "B") {
                system("CLS");
                cout << "You have chosen Hyundai model 2015" << endl;
                displayCarDetails();
            } else if (carmodel == "C") {
                system("CLS");
                cout << "You have chosen Ford model 2017" << endl;
                displayCarDetails();
            } else {
                cout << "Invalid Car Model. Please try again!" << endl;
            }
            sleep(2);
        } while (carmodel != "A" && carmodel != "B" && carmodel != "C");

        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please provide following information: " << endl;
        cout << "Please select a Car No. : ";
        cin >> carnumber;
        cout << "Number of days you wish to rent the car : ";
        cin >> days;
        cout << endl;
    }

    void calculate() {
        sleep(1);
        system("CLS");
        cout << "Calculating rent. Please wait......" << endl;
        sleep(2);

        if (carmodel == "A" || carmodel == "a")
            rentalfee = days * 5600;
        else if (carmodel == "B" || carmodel == "b")
            rentalfee = days * 5000;
        else if (carmodel == "C" || carmodel == "c")
            rentalfee = days * 7500;
    }

    void displayCarDetails() {
        if (carmodel == "A") {
            cout << "Tesla Model 2011 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5600 taka" << endl;
        } else if (carmodel == "B") {
            cout << "Hyundai Model 2015 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 5000 taka" << endl;
        } else if (carmodel == "C") {
            cout << "Ford Model 2017 Details:" << endl;
            cout << "---------------------------------" << endl;
            cout << "Specification: ..." << endl;
            cout << "Price per day: 7500 taka" << endl;
        }
    }

    void showRent() {
        // Generate a random invoice number
        srand(time(0));
        int invoiceNo = rand() % 1000000 + 1;

        cout << "\n\t\t                       Car Rental - Customer Invoice                  " << endl;
        cout << "\t\t    ///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t    | Invoice No. :------------------|" << setw(10) << "#" <<invoiceNo << " |" << endl;
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
        cout << "\t\t     ________________________________________________________" << endl;
        cout << "\t\t     # This is a computer generated invoice and it does not" << endl;
        cout << "\t\t     require an authorised signature #" << endl;
        cout << " " << endl;
        cout << "\t\t    ///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t    You are advised to pay up the amount before the due date." << endl;
        cout << "\t\t    Otherwise, a penalty fee will be applied" << endl;
        cout << "\t\t    ///////////////////////////////////////////////////////////" << endl;

        sleep(2);
        system("CLS");

        cout << "Thank you for choosing our Car Rental Service!" << endl;
    }

private:
    void login() {
        string pass = "";
        cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n\n";
        cout << "\t\t\t\t\t------------------------------";
        cout << "\n\t\t\t\t\t\t     LOGIN \n";
        cout << "\t\t\t\t\t------------------------------\n\n";
        cout << "\t\t\t\t\tEnter Password: ";
        cin >> pass;
        cout << endl;

        if (pass != "bubt") {
            cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
            sleep(1);
            system("CLS");
            login();
        }
    }
};

class welcome {
public:
    void displayWelcomeMessage() {
        cout << "\nWelcome to the Car Rental System!" << endl;
        sleep(1);
        cout << "\nStarting the program, please wait....." << endl;
        sleep(1);
        cout << "\nLoading up files....." << endl;
        sleep(1);
        system("CLS");
    }
};

int main() {
    welcome welcomeMessage;
    welcomeMessage.displayWelcomeMessage();

    rent obj2;
    obj2.inputData();
    obj2.calculate();
    obj2.showRent();

    return 0;
}
