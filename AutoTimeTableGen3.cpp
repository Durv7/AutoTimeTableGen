#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to store course details
struct Course {
  string name; // Name of the course
  int credits=0; // Number of credit hours for this course
  string faculty;
};

// Structure to store faculty details
struct Faculty {
  string name;
  vector<string> availability; // Stores available days/times (e.g., "Mon-Wed 9:00-11:00")
  vector<string> preferences; // Stores preferred teaching hours (e.g., "Tue-Thu afternoons")
};

// Structure to store classroom details
struct Classroom {
  int capacity;
  string name;
  vector<string> equipment; // Stores available equipment (e.g., "Projector", "Whiteboard")
};

// Function to get user input for a course
Course getCourseDetails() {
  Course course;
  cout << "Enter course name: ";
  getline(cin, course.name);
  cout << "Enter course credits: ";
  cin >> course.credits;
  cin.ignore(); // Clear input buffer after integer
  cout << "Enter faculty name: ";
  getline(cin, course.faculty);
  return course;
}

// Function to get user input for faculty
Faculty getFacultyDetails() {
  Faculty faculty;
  cout << "Enter faculty name: ";
  getline(cin, faculty.name);
  cout << "Enter faculty availability (days and times, separated by spaces, e.g., Mon-Wed 9:00-11:00): ";
  string availability;
  getline(cin, availability);
  faculty.availability.push_back(availability);
  cout << "Enter any additional availability (separate entries if needed): ";
  while (getline(cin, availability) && !availability.empty()) {
    faculty.availability.push_back(availability);
  }
  cout << "Enter preferred teaching hours (optional, format same as availability): ";
  string preference;
  getline(cin, preference);
  if (!preference.empty()) {
    faculty.preferences.push_back(preference);
  }
  while (getline(cin, preference) && !preference.empty()) {
    faculty.preferences.push_back(preference);
  }
  return faculty;
}

// Function to get user input for a classroom
Classroom getClassroomDetails() {
  Classroom classroom;
  cout << "Enter classroom name: ";
  getline(cin, classroom.name);
  cout << "Enter classroom capacity: ";
  cin >> classroom.capacity;
  cin.ignore(); // Clear input buffer after integer
  cout << "Enter any special equipment (separate entries if needed): ";
  string equipment;
  while (getline(cin, equipment) && !equipment.empty()) {
    classroom.equipment.push_back(equipment);
  }
  return classroom;
}

int main() {
  vector<Course> courses;
  vector<Faculty> faculty;
  vector<Classroom> classrooms;

  // Get course details
  int numCourses;
  cout << "Enter number of courses: ";
  cin >> numCourses;
  cin.ignore(); // Clear input buffer after integer
  for (int i = 0; i < numCourses; ++i) {
    courses.push_back(getCourseDetails());
  }

  // Get faculty details
  int numFaculty;
  cout << "Enter number of faculty members: ";
  cin >> numFaculty;
  cin.ignore(); // Clear input buffer after integer
  for (int i = 0; i < numFaculty; ++i) {
    faculty.push_back(getFacultyDetails());
  }

  // Get classroom details
  int numClassrooms;
  cout << "Enter number of classrooms: ";
  cin >> numClassrooms;
  cin.ignore(); // Clear input buffer after integer
  for (int i = 0; i < numClassrooms; ++i) {
    classrooms.push_back(getClassroomDetails());
  }

  // Data successfully collected, use it for further processing
  cout << "Data collection complete!" << endl;

  return 0;
}
