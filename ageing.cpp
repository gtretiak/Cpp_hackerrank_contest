#include <iostream>
using namespace std;

class Person {
public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();
};

Person::Person(int initialAge) {
    if (initialAge < 0) {
        age = 0;
        cout << "Age is not valid, setting age to 0." << endl;
    }
    else {
        age = initialAge;
    }
}

void Person::amIOld() {
    if (age < 13) {
        cout << "You are a child." << endl;
    }
    else if (age >= 13 && age < 18) {
        cout << "You are a teenager." << endl;
    }
    else if (age >= 19 && age < 35) {
        cout << "You are an adult." << endl;
    }
    else if (age >= 36 && age < 80) {
        cout << "You are old." << endl;
    }
    else if (age >= 81 && age < 122) {
        cout << "You are very old." << endl;
    }
    else {
        cout << "You are dead." << endl;
    }
}

void Person::yearPasses() {
    age++;
}

int main() {
    int t;
    int age;
    
    cout << "Enter the number of tests:";
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Enter the age:"; cin >> age;
        Person p(age);
        p.amIOld();
        for (int j = 0; j < 3; j++) {
            p.yearPasses();
        }
	cout << "Time passed...";
        p.amIOld();
        cout << '\n';
    }
    return 0;
}
