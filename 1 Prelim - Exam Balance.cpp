#include <iostream>
using namespace std;

int accBal, withDraw, remainBal;

int main() {
    cout << "Enter your current account balance: ";
    cin >> accBal;
    cout << "Enter the amount you wish to withraw: ";
    cin >> withDraw;
    
    remainBal = (accBal - withDraw);
    
    while (accBal > withDraw) {
        if (withDraw > accBal) {
            cout << "Insufficient Funds. ";
            cout << "Enter the amount you wish to withdraw: ";
            cin >> withDraw;
        }
        
    if (accBal > withDraw) {
        if (withDraw % 100 == 0) {
            remainBal = (accBal - withDraw);
        }
        
        else{
            cout << "Warning: Must be in hundreds. Enter a valid amount: " << endl;
            cin >> withDraw;
        }
    }    
    
    cout << "Your Balance is: " << remainBal;
    return 0;
}}