#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Person {
protected:
    string firstName;
    string lastName;
    int id;
public:
    Person(string firstName, string lastName, int identification) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson() {
        cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
    }
};

class Student : public Person {
private:
    vector<int> testScores;
public:
    Student(string firstName, string lastName, int id, vector<int> scores)
        : Person(firstName, lastName, id), testScores(scores) {}
    
    char calculate() {
        int sum = 0;
        for (int score : testScores) {
            sum += score;
        }
        int res = sum / testScores.size();
        
        if (res >= 90 && res <= 100) return 'O';
        else if (res >= 80 && res < 90) return 'E';
        else if (res >= 70 && res < 80) return 'A';
        else if (res >= 55 && res < 70) return 'P';
        else if (res >= 40 && res < 55) return 'D';
        else if (res < 40) return 'T';
        else {
            cerr << "Failure\n";
            exit(EXIT_FAILURE);
        }
    }
};

int main() {
    string firstName;
    string lastName;
    int id;
    int numScores;
    
    cout << "Enter the student's first name: ";
    cin >> firstName;
    cout << "Enter the student's last name: ";
    cin >> lastName;
    cout << "Enter the student's id: ";
    cin >> id;
    cout << "Enter the number of student's scores: ";
    cin >> numScores;
    vector<int> scores;
    cout << "Now enter " << numScores << " integers (0-100) representing the student's scores.\n";
    for (int i = 0; i < numScores; i++) {
        int tmpScore;
	cout << i + 1 << " score: ";
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Average grade: " << s->calculate() << "\n";
    delete(s);
    return 0;
}
