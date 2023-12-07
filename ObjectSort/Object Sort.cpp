//Jonathan Robinson
//COP2535.0M1
/* C++ program that will read student records from a data file and sort the contents.

    * Declare a class to describe a student record with private fields for
        first name
        last name
        student id
        declared major
        grade point average
        date of birth
    * Use appropriate data types, constructor(s), and accessor methods.
    * Do not hard-code values. The comma-separated value (csv) text data-file students.csv is provided for development and test. Other data files may also be used. These will have the same fields with an arbitrary number of records.
    * After the file is read, and the data stored in memory, write a message to the console indicating how many records were read.
    * Prompt the user to select the sort criterion field
        - Read the single character user selection.

    * Sort the data records using a sort method. Print the sorted data records to the console using a toString() method from the class that you created.
    * After the last records is printed, repeat the user menu selections and loop until the user selects 'Q' to quit the application.
*/
#include <cctype>
#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

class StudentRecord {

private:
    string firstName, lastName, major, dob;
    int studentID;
    float gpa;
    void DisplayRecord();
    int GetDOB(string age);
    int getAge(int yearBorn);
    void getRecord(string record);
    void getData(StudentRecord* array, string fileName, int lines);
    void selectionSortLastName(StudentRecord array[], int size);
    void selectionSortID(StudentRecord array[], int size);
    void selectionSortMajor(StudentRecord array[], int size);
    void selectionSortGPA(StudentRecord array[], int size);
    void selectionSortAge(StudentRecord array[], int size);
    void swap(StudentRecord& a, StudentRecord& b);

public:
    StudentRecord(string first, string last, int iD, string focus, float grade, string age);
    StudentRecord();

    int LinesInFile(string fileName);
    void PromptUser(StudentRecord* array, string fileName);
    void showRecord(StudentRecord* array, int lines);
};

// Constructor
StudentRecord::StudentRecord(string first, string last, int iD, string focus, float grade, string age) {
    firstName = first;
    lastName = last;
    studentID = iD;
    major = focus;
    gpa = grade;
    dob = age;
}

// Default Constructor
StudentRecord::StudentRecord() {
    firstName = "";
    lastName = "";
    studentID = 0;
    major = "";
    gpa = 0;
    dob = "";
}

/****************************************
*	  GetData Function Declaration      *
****************************************/
void StudentRecord::getData(StudentRecord* array, string fileName, int lines) {

    int count = 0;
    string readLine;
    ifstream inputFile;

    inputFile.open(fileName);		//Opens the text file and sets it to inputFile 

    if (!inputFile) {
        cout << "Error opening random text file\n";
    }
    else {
        while (getline(inputFile, readLine)) {
            array[count].getRecord(readLine);
            count++;
        }
    }
    inputFile.close();
}


// Function to count the amount of lines are in a file
int StudentRecord::LinesInFile(string fileName) {

    ifstream inputFile;
    int lines = 0;
    string line;
    inputFile.open(fileName);		//Opens the text file and sets it to inputFile 

    if (!inputFile) {
        cout << "Error opening random text file\n";
    }
    else {
        while (getline(inputFile, line)) {
            lines++;
        }
    }
    inputFile.close();
    return lines;
}

// Displays the information of a students record
void StudentRecord::DisplayRecord() {

    cout << fixed << setprecision(2) << "First name: " << firstName << " Last name: " << lastName << " Student id: " << studentID << " Major: " + major + " GPA: " << gpa << " Date of birth: " << dob << endl;
}

void StudentRecord::showRecord(StudentRecord* array, int lines) {
    for (int i = 0; i < lines; i++) {
        array[i].DisplayRecord();
    }
}

void StudentRecord::getRecord(string record) {
    vector<string> data;
    stringstream ss(record);
    string temp;
    float preGPA;

    while (getline(ss, temp, ',')) {
        data.push_back(temp);
    }

    for (int i = 0; i < data.size(); i++) {
        if (i == 0)
            firstName = data[i];
        else if (i == 1)
            lastName = data[i];
        else if (i == 2)
            studentID = stoi(data[i]);
        else if (i == 3)
            major = data[i];
        else if (i == 4)
            gpa = stof(data[i]);
        else if (i == 5)
            dob = data[i];
    }

}

// Calculates the age of the student from the year of birth
int StudentRecord::getAge(int yearBorn) {
    time_t now;
    now = time(NULL);
    int currentYear = 70 + now / 31537970;

    int age = currentYear - yearBorn;
    if (age >= 100) {
        age = age - 100;
    }
    return age;
}

// Gets the students age and date of birth
int StudentRecord::GetDOB(string age) {

    string day, month, year;
    int count = 0;

    vector<string> date;
    stringstream ss(age);
    string temp;

    while (getline(ss, temp, '-')) {
        date.push_back(temp);
    }

    for (int i = 0; i < date.size(); i++) {
        if (i == 0)
            day = date[i];
        else if (i == 1)
            month = date[i];
        else if (i == 2)
            year = date[i];
    }
    int totalage = getAge(stoi(year));
    return totalage;
}

void StudentRecord::selectionSortLastName(StudentRecord array[], int size) {
    int minIndex;
    string minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start].lastName;
        for (int index = start + 1; index < size; index++) {
            if (array[index].lastName < minValue) {
                minValue = array[index].lastName;
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    showRecord(array, size);
}

void StudentRecord::selectionSortID(StudentRecord array[], int size) {
    int minIndex;
    int minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start].studentID;
        for (int index = start + 1; index < size; index++) {
            if (array[index].studentID < minValue) {
                minValue = array[index].studentID;
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    showRecord(array, size);
}

void StudentRecord::selectionSortMajor(StudentRecord array[], int size) {
    int minIndex;
    string minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start].major;
        for (int index = start + 1; index < size; index++) {
            if (array[index].major < minValue) {
                minValue = array[index].major;
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    showRecord(array, size);
}

void StudentRecord::selectionSortGPA(StudentRecord array[], int size) {
    int minIndex;
    float minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start].gpa;
        for (int index = start + 1; index < size; index++) {
            if (array[index].gpa < minValue) {
                minValue = array[index].gpa;
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    showRecord(array, size);
}

void StudentRecord::selectionSortAge(StudentRecord array[], int size) {
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = GetDOB(array[start].dob);
        for (int index = start + 1; index < size; index++) {
            if (GetDOB(array[index].dob) < minValue) {
                minValue = GetDOB(array[index].dob);
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
    showRecord(array, size);
}


/****************************************
*	    Swap function Declaration       *
****************************************/

void StudentRecord::swap(StudentRecord& a, StudentRecord& b) {
    StudentRecord temp = a;
    a = b;
    b = temp;
}


void StudentRecord::PromptUser(StudentRecord* array, string fileName) {
    char choice, option;
    int lines = LinesInFile(fileName);
    getData(array, fileName, lines);
    cout << "\n\t" << lines << " records read" << endl;
    cout << "\tSort by: (L)Last name, (S)Student Id, (M)Major, (G)GPA, (A)Age, or (Quit):  ";
    cin >> choice;
    option = toupper(choice);

    while (option != 'Q') {
        if (option != 'L' && option != 'S' && option != 'M' && option != 'G' && option != 'A')
            cout << "\n\t Entry invalid, Please select from the following choices...";
        else if (option == 'L')
            selectionSortLastName(array, lines);
        else if (option == 'S')
            selectionSortID(array, lines);
        else if (option == 'M')
            selectionSortMajor(array, lines);
        else if (option == 'G')
            selectionSortGPA(array, lines);
        else if (option == 'A')
            selectionSortAge(array, lines);

        cout << "\n\tSort by: (L)Last name, (S)Student Id, (M)Major, (G)GPA, (A)Age, or (Quit):  ";
        cin >> choice;
        option = toupper(choice);
    }

    cout << "\n\nThank you, have a nice day." << endl;
}

int main() {

    StudentRecord record;
    StudentRecord student[60];
    string inputFile = "students.csv";
    int numberOfStudents;

    numberOfStudents = record.LinesInFile(inputFile);

    record.PromptUser(student, inputFile);


    return 0;
}