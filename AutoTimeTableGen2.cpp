#include<iostream>
#include<string>
#include <algorithm>
#include <vector>

using namespace std;

struct Session {
    string subject;
    string location;
    string instructor;
};

vector<Session> generateTimetable(string days[5], string time[6], string sub[7], string instructor[7], int sessions[7], string Classrooms[2], string Labs[2], vector<string> labsub) {
    vector<Session> timetable(5 * 6);

    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (j < sessions[k]) {
                Session session;
                session.subject = sub[k];
                session.location = (sessions[k] <= 3)? Classrooms[0] : Labs[0]; // Constraint: only 3 subjects can be taught in a classroom
                session.instructor = instructor[k];
                timetable[i * 6 + j] = session;
            }
        }
        ++k;
    }

    // Constraint: no subject can be taught in the same location for two consecutive time slots
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (timetable[i * 6 + j].location == timetable[i * 6 + j + 1].location && timetable[i * 6 + j].subject == timetable[i * 6 + j + 1].subject) {
                // Swap the locations of the two sessions
                swap(timetable[i * 6 + j].location, timetable[i * 6 + j + 1].location);
            }
        }
    }

    // Constraint: certain subjects require 2 consecutive time slots in a lab
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (find(labsub.begin(), labsub.end(), timetable[i * 6 + j].subject)!= labsub.end()) {
                // If the subject is in the labsub vector, check if it has 2 consecutive time slots in a lab
                if (timetable[i * 6 + j].location == Labs[0] && timetable[i * 6 + j + 1].location == Labs[0] && timetable[i * 6 + j].subject == timetable[i * 6 + j + 1].subject) {
                    // If the subject has 2 consecutive time slots in a lab, continue to the next iteration
                    continue;
                } else {
                    // If the subject does not have 2 consecutive time slots in a lab, find the next available time slot in a lab
                    for (int k = j + 2; k < 6; ++k) {
                        if (timetable[i * 6 + k].location == Labs[0]) {
                            // If a time slot in a lab is found, swap the locations of the two sessions
                            swap(timetable[i * 6 + j].location, timetable[i * 6 + k].location);
                            break;
                        }
                    }
                }
            }
        }
    }

    return timetable;
}

int main() {

    string days[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    string time[6] = {"09:30", "10:30", "11:45", "12:45", "02:45", "03:45"};
    string sub[7] = {"AT", "CA", "COA", "CG", "SE", "OOP", "AUDIT"};
    string instructor[7] = {"Instructor A", "Instructor B", "Instructor C", "Instructor D", "Instructor E", "Instructor F", "Instructor G"};
    int sessions[7] = {4, 4, 3, 3, 3, 3, 2}; // AUDIT is optional and can be taken only once.
    string Classrooms[2] = {"Room A", "Room B"};
    string Labs[2] = {"Lab A", "Lab B"};

    vector<string> labsub = {"CG", "SE"}; // Subjects that require 2 consecutive time slots in a lab

    vector<Session> timetable = generateTimetable(days, time, sub, instructor, sessions, Classrooms, Labs, labsub);

    cout << "Day\t";
    for (int d = 0; d < 5; d++) {
        cout << days[d] << "\t";
    }

    cout << endl << "-------------------------------\n";
    for (int t = 0; t < 6; t++) {
        for (int d = 0; d < 5; d++) {
            cout << "\t" << timetable[d * 6 + t].subject << " in " << timetable[d * 6 + t].location << " with " << timetable[d * 6 + t].instructor;
        }
        cout << endl;
    }
    return 0;
}