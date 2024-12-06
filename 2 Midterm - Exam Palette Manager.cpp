#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Palette {
    string name;
    vector<string> colors;
};

void createPalette(vector<Palette>& palettes) {
    Palette newPalette;
    cout << "Enter palette name: ";
    getline(cin, newPalette.name);

    cout << "Enter the colors for the palette (separated by spaces): ";
    string input;
    getline(cin, input);
    istringstream iss(input);
    string color;
    while (iss >> color) {
        newPalette.colors.push_back(color); 
    } //all good here

    palettes.push_back(newPalette);
    cout << "Palette created successfully.\n";
}

void listPalettes(const vector<Palette>& palettes) {
    cout << "Palettes:\n";
    for (size_t i = 0; i < palettes.size(); ++i) {
        cout << (i + 1) << ". Name: " << palettes[i].name << endl; //dis add index
        cout << "   Colors: ";
        for (size_t j = 0; j < palettes[i].colors.size(); ++j) {
            cout << palettes[i].colors[j];
            if (j < palettes[i].colors.size() - 1) {
                cout << ", "; // THIS IS THE COMMA, WE NEED COMMA
            }
        }
        cout << endl;
    }
}

void updatePalette(vector<Palette>& palettes, int index) {
    if (index >= 0 && index < palettes.size()) {
        Palette& palette = palettes[index];

        cout << "Enter new colors (separated by spaces): ";
        string input;
        getline(cin, input);

        if (!input.empty()) {               //fixed DO NOT TOUCH
            istringstream iss(input);
            string color;
            palette.colors.clear();
            while (iss >> color) {
                palette.colors.push_back(color);
            }
        }       //PS: user have to put colors all over again, sad.

        cout << "Palette updated successfully.\n";
    } else {
        cerr << "Invalid palette index.\n";
    }
}

void deletePalette(vector<Palette>& palettes, int index) {
    if (index >= 0 && index < palettes.size()) {
        palettes.erase(palettes.begin() + index);  //fixed
        cout << "Palette deleted successfully.\n"; 
    } else {
        cerr << "Invalid palette index.\n";
    }
}

int main() {
    vector<Palette> palettes;
    
    cout << "This is a Palette Manager. You can store, list, edit, or delete a palette.\n By: Lala :D\n"; //Lalaine Jannah Valle Dela Cruz BSIT-BLK2 19 yrs old june 6 2005

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Create a new palette\n";
        cout << "2. List all palettes\n";
        cout << "3. Update a palette\n";
        cout << "4. Delete a palette\n";
        cout << "5. Exit\n \n";
        cout << "Option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // clear newline

        switch (choice) { 
            case 1:
                createPalette(palettes);
                break;
            case 2:
                listPalettes(palettes);
                break;
            case 3: {
                int index;
                cout << "Enter palette index: ";
                cin >> index;
                cin.ignore(); // clear newline again
                updatePalette(palettes, index - 1);
                break;
            }
            case 4: {
                int index;
                cout << "Enter palette index: ";
                cin >> index;
                cin.ignore(); // clear newline again again
                deletePalette(palettes, index - 1);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cerr << "Invalid choice. Please try again.\n";
        }
    }
}
