#include <iostream>
#include <string>
#include <cmath>  
#include <iomanip>

using namespace std;

class Event {
private:
    string eventName;      
    string first&last Name; 
    int numberOfGuests
    int eventDuration;  

    const double CostPerHour = 18.50;  
    const double CostPerMinute = 0.40; 
    const double CostOfDinner = 20.70; 

public:
    void setEventDetails() {
        cout << "******************** Event Management System ********************\n";

        cout << "Enter the name of the event: ";
        getline(cin, eventName);

        cout << "Enter the customer's first and last name: ";
        cin >> first&last Name;

        cout << "Enter the number of guests: ";
        cin >> numberOfGuests;

        cout << "Enter the number of minutes in the event: ";
        cin >> eventDuration;

        if (numberOfGuests <= 0 || eventDuration <= 0) {
            cout << "Invalid input for guests or duration. Please restart the program." << endl;
            exit(1);
        }
    }

    void calculateAndDisplayCost() {
        int numberOfServers = ceil(static_cast<double>(numberOfGuests) / 20);

        double costForOneServer = (eventDuration / 60) * CostPerHour +
                                  (eventDuration % 60) * CostPerMinute;

        double totalServerCost = numberOfServers * costForOneServer;

        double totalFoodCost = numberOfGuests * CostOfDinner;

        double totalCost = totalServerCost + totalFoodCost;

        double depositAmount = totalCost * 0.25;

        cout << "\n=== Event Estimate for: " << firstName << " " << lastName << " ===" << endl;
        cout << "Event Name: " << eventName << endl;
        cout << "Number of Guests: " << numberOfGuests << endl;
        cout << "Event Duration: " << eventDuration << " minutes" << endl;
        cout << "Number of Servers: " << numberOfServers << endl;
        cout << "Cost for Servers: $" << fixed << setprecision(2) << totalServerCost << endl;
        cout << "Cost for Food: $" << fixed << setprecision(2) << totalFoodCost << endl;
        cout << "Average Cost Per Person: $" << fixed << setprecision(2) 
             << (totalFoodCost / numberOfGuests) << endl;
        cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << endl;
        cout << "Please deposit a 25% deposit to reserve the event." << endl;
        cout << "Deposit Needed: $" << fixed << setprecision(2) << depositAmount << endl;
    }
};

int main() {
    Event event;

    event.setEventDetails();
    event.calculateAndDisplayCost();

    cout << "\nThank you for using the Event Management System!" << endl;
    return 0;
}
