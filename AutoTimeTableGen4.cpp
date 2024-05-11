#include <iostream>
#include <vector>
#include <ctime>

// Define the maximum number of classes per day and subjects
const int MAX_CLASSES_PER_DAY = 5;
const int MAX_SUBJECTS = 7;

// Define a structure for a class
struct Class {
    std::string subject;
    std::string teacher;
    std::string time;
};

// Define a structure for a day
struct Day {
    Class classes[MAX_CLASSES_PER_DAY];
};

// Define a structure for the timetable
struct Timetable {
    Day days[5];
};

// Function to generate a random time for a class


// Function to generate a timetable
Timetable generateTimetable() {
    Timetable timetable;
    std::string subjects[MAX_SUBJECTS] = {"AT", "CA", "COA", "CG", "SE", "OOP", "AUDIT"};
    std::string teachers[MAX_SUBJECTS] = {"RAM", "UDP", "MSK", "DCJ", "CBP","SBP","MSS"};

    // Generate classes for each day
    for (int day = 0; day < 5; day++) {
        for (int classNum = 0; classNum < MAX_CLASSES_PER_DAY; classNum++) {
            Class &c = timetable.days[day].classes[classNum];
            c.subject = subjects[rand() % MAX_SUBJECTS];
            c.teacher = teachers[rand() % MAX_SUBJECTS];
            
        }
    }

    return timetable;
}

// Function to print a timetable
void printTimetable(const Timetable &timetable) {
    std::cout << "Timetable\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Day   | Class 1     | Class 2     | Class 3     | Class 4     | Class 5\n";
    std::cout << "------------------------------------------------------------\n";

    for (int day = 0; day < 5; day++) {
        std::cout << "Day " << day + 1 << "   | ";
        for (int classNum = 0; classNum < MAX_CLASSES_PER_DAY; classNum++) {
            const Class &c = timetable.days[day].classes[classNum];
            std::cout << c.subject << " (" << c.teacher << ") - " << " | ";
        }
        std::cout << "\n";
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    

    // Generate a timetable
    Timetable timetable = generateTimetable();

    // Print the timetable
    printTimetable(timetable);

    return 0;
}