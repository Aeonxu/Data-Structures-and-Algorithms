//Dela Cruz, Lalaine Jannah V.
#include <iostream>

using namespace std;

int main() {
    float celsius;
    float fahrenheit;

    double input1;
    char input2;


// Int temperature first
    cout << "Enter Temparature: ";
    cin>> input1;
    
    
// Char temperature second
    cout << "Enter 'c' or 'C' to convert Fahrenheit to Celcius. Enter 'f' or 'F' to convert Celcius to Fahrenheit: ";
    cin >> input2;
    
// For Celcius
    if (input2 == 'c')
    {
      cout << endl;
      cout << "Your Fahrenheit temperature converted to Celsius is: " << (input1 - 32) * (5.0/9.0) << endl;
    }

    else if (input2 == 'C')
    {
      cout << endl;
      cout << "Your Fahrenheit temperature converted to Celsius is: " << (input1 - 32) * (5.0/9.0) << endl;
    }

// For Fahrenheit
    if (input2 == 'f')
  {
    fahrenheit = (celsius * 9.0) / 5.0 + 32;
    cout << endl;
    cout << "Your Celsius temperature converted to Fahrenheit is: " << (input1 * 9.0/5.0) + (32) << endl;
  }

  else if (input2 == 'F')
  {
    cout << endl;
    cout << "Your Celsius temperature converted to Fahrenheit is: " << (input1 * 1.8) + (32) << endl;
  }

    return 0;
}