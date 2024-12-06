
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main() {
    
    std::vector <string> currentInv = {"apples","bananas","oranges","pears"};
    std::vector <string> shipment = {"kiwis","bananas","grapes"};
    std::vector <string> soldOutItems = {"apples","oranges"};
    std::vector <string> updatedInv;
    
    //merge current inv and shipment //
    updatedInv.insert(updatedInv.end(), currentInv.begin(), currentInv.end());
    updatedInv.insert(updatedInv.end(), shipment.begin(), shipment.end());
    
    
    //remove sold out items //
    for (const string& item : soldOutItems) {
        updatedInv.erase(remove(updatedInv.begin(), updatedInv.end(), item), updatedInv.end());
        }
        
    //remove dups
    set<string> uniqueItems(updatedInv.begin(), updatedInv.end());
    updatedInv.assign(uniqueItems.begin(), uniqueItems.end());
        
    
    //print the updated inventory//
    cout << "Current inventory: ";
    for (const string& item : currentInv) {
        cout << item << ", ";
    }
    cout << endl;
    
    cout << "Shipment: ";
    for (const string& item : shipment) {
        cout << item << ", ";
    }
    cout << endl;
    
    cout << "Sold-out Items: ";
    for (const string& item : soldOutItems) {
        cout << item << ", ";
    }
    cout << endl;
    
    cout << "Updated inventory: ";
    for (const string& item : updatedInv) {
        cout << item << ", ";
    }
    cout << endl;
    
    return 0;
    
    
    
    
    
    
    
    
    
}
    