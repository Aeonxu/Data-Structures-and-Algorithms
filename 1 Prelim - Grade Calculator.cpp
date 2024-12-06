#include <iostream>
using namespace std;
    
    
    
int main(){
    
    int e1;
    int e2;
    int e3;
    
    cout<<"Enter the score for Exam 1: ";
    cin>> e1;
    
    cout<<"Enter the score for Exam 2: ";
    cin>> e2;
    
    cout<<"Enter the score for Exam 3: ";
    cin>> e3;
    
    int marks = (e1 + e2 + e3) / 3;
    cout << "Average Score: " << marks << endl;
    
    if (marks >= 70){
        cout<<"Result: Passed";
    }
    else if (marks <= 69){
        cout<<"Result: Failed";
    }
    
    return 0;
}