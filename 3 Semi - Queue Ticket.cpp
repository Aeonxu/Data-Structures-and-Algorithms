#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <sstream>
#include <iomanip>

using namespace std;

// this is a person in the queue
class Person {
public:
    string name;
    string ticket_number;

    Person(const string& name, const string& ticket_number)
        : name(name), ticket_number(ticket_number) {}
};

// manage the queue of people
class Queue {
private:
    queue<Person> people_queue;
    int ticket_counter;
    mutex mtx;

public:
    Queue() : ticket_counter(1) {}

    // adds a person to the end of the queue
    void enqueue(const string& name) {
        lock_guard<mutex> lock(mtx);
        string ticket_number = to_string(ticket_counter++);
        stringstream ss;
        ss << setw(3) << setfill('0') << ticket_number;
        people_queue.push(Person(name, ss.str()));
        cout << name << " added to the queue with Ticket #" << ss.str() << endl;
        cout << "Queue size: " << people_queue.size() << endl;
    }

    // auto remove the person at the front of the queue per minute
    void auto_dequeue() {
        thread t([this] {
            while (true) {
                this_thread::sleep_for(chrono::seconds(60));
                lock_guard<mutex> lock(mtx);
                if (!people_queue.empty()) {
                    Person person = people_queue.front();
                    people_queue.pop();
                    cout << "\nDequeue: " << person.name << " received a ticket (#" << person.ticket_number << ")" << endl;
                    cout << "Queue size: " << people_queue.size() << endl;
                    if (!people_queue.empty()) {
                        Person next_person = people_queue.front();
                        cout << "Next in line: " << next_person.name << " (Ticket #" << next_person.ticket_number << ")" << endl;
                    }
                }
            }
        });
        t.detach();
    }

    // check if queue is empty
    bool isEmpty() {
        lock_guard<mutex> lock(mtx);
        return people_queue.empty();
    }

    // gives the no. of people in the queue
    int size() {
        lock_guard<mutex> lock(mtx);
        return people_queue.size();
    }

    // shows the next person in line
    void peek() {
        lock_guard<mutex> lock(mtx);
        if (!people_queue.empty()) {
            Person person = people_queue.front();
            cout << "Next in line: " << person.name << " (Ticket #" << person.ticket_number << ")" << endl;
        } else {
            cout << "The queue is empty." << endl;
        }
    }

    // locate position of a person in the queue
    void position(const string& search_term) {
        lock_guard<mutex> lock(mtx);
        int position = 1;
        bool found = false;
        queue<Person> temp_queue = people_queue;

        while (!temp_queue.empty()) {
            Person person = temp_queue.front();
            temp_queue.pop();

            if (person.name == search_term || person.ticket_number == search_term) {
                cout << search_term << " is currently at position " << position << " in the queue." << endl;
                found = true;
                break;
            }
            position++;
        }

        if (!found) {
            cout << search_term << " is not in the queue." << endl;
        }
    }
};

// main func for the ticketing system
void menu() {
    Queue queue;
    queue.auto_dequeue(); // this starts the auto dequeue / timer 

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;

    while (true) {
        cout << "\n1. Enqueue a person" << endl;
        cout << "2. Check your position in the queue" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        cin.ignore();

        if (option == 1) {
            cout << "Enter the name: ";
            string name;
            getline(cin, name);
            queue.enqueue(name);
        } else if (option == 2) {
            cout << "Enter your name or ticket number: ";
            string name_or_ticket;
            getline(cin, name_or_ticket);
            queue.position(name_or_ticket);
        } else if (option == 3) {
            cout << "Exiting... Good bye!" << endl;
            break;
        } else {
            cout << "Invalid option. Try again" << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}