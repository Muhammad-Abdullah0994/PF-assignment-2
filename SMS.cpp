//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void addStudent();
//void viewStudents();
//void searchStudent();
//void updateStudent();
//void deleteStudent();
//
//int main() {
//    int choice;
//    do 
//    {
//        cout << "\n--- Student Record Management ---\n";
//        cout << "1. Add Student\n";
//        cout << "2. View All Students\n";
//        cout << "3. Search Student\n";
//        cout << "4. Update Student\n";
//        cout << "5. Delete Student\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        switch (choice) 
//        {
//        case 1:
//            addStudent();
//            break;
//        case 2:
//            viewStudents();
//            break;
//        case 3:
//            searchStudent();
//            break;
//        case 4:
//            updateStudent();
//            break;
//        case 5:
//            deleteStudent();
//            break;
//        case 6:
//            cout << "Exiting...\n";
//            break;
//        default:
//            cout << "Invalid choice.\n";
//            break;
//        }
//    } while (choice != 6);
//    return 0;
//}
//
//void addStudent() 
//{
//    string name, rollNumber, department;
//    float gpa;
//    cout << "Enter Name: ";
//    cin.ignore();
//    getline(cin, name);
//    cout << "Enter Roll Number: ";
//    getline(cin, rollNumber);
//    cout << "Enter Department: ";
//    getline(cin, department);
//    cout << "Enter GPA: ";
//    cin >> gpa;
//    cin.ignore();
//    ofstream outFile("students.txt", ios::app);
//    if (outFile.is_open()) 
//    {
//        outFile << name << "," << rollNumber << "," << department << "," << gpa << endl;
//        outFile.close();
//        cout << "Student record added successfully.\n";
//    }
//    else 
//    {
//        cout << "Unable to open file.\n";
//    }
//}
//
//void viewStudents() 
//{
//    ifstream inFile("students.txt");
//    string line;
//    cout << "\n--- All Student Records ---\n";
//    while (getline(inFile, line)) 
//    {
//        size_t pos1 = line.find(',');
//        size_t pos2 = line.find(',', pos1 + 1);
//        size_t pos3 = line.find(',', pos2 + 1);
//        string name = line.substr(0, pos1);
//        string rollNumber = line.substr(pos1 + 1, pos2 - pos1 - 1);
//        string department = line.substr(pos2 + 1, pos3 - pos2 - 1);
//        string gpa = line.substr(pos3 + 1);
//        cout << "Name: " << name << endl;
//        cout << "Roll Number: " << rollNumber << endl;
//        cout << "Department: " << department << endl;
//        cout << "GPA: " << gpa << endl;
//        cout << "-----------------------------\n";
//    }
//    inFile.close();
//}
//
//void searchStudent()
//{
//    string roll;
//    cout << "Enter Roll Number to search: ";
//    cin.ignore();
//    getline(cin, roll);
//    ifstream inFile("students.txt");
//    string line;
//    bool found = false;
//    while (getline(inFile, line))
//    {
//        size_t pos = line.find(',');
//        string rollNumber = line.substr(pos + 1, line.find(',', pos + 1) - pos - 1);
//        if (rollNumber == roll) {
//            size_t pos1 = line.find(',');
//            size_t pos2 = line.find(',', pos1 + 1);
//            size_t pos3 = line.find(',', pos2 + 1);
//            string name = line.substr(0, pos1);
//            string department = line.substr(pos2 + 1, pos3 - pos2 - 1);
//            string gpa = line.substr(pos3 + 1);
//            cout << "Name: " << name << endl;
//            cout << "Roll Number: " << rollNumber << endl;
//            cout << "Department: " << department << endl;
//            cout << "GPA: " << gpa << endl;
//            found = true;
//            break;
//        }
//    }
//    inFile.close();
//    if (!found) 
//    {
//        cout << "Student not found.\n";
//    }
//}
//
//void updateStudent() 
//{
//    string roll;
//    cout << "Enter Roll Number to update: ";
//    cin.ignore();
//    getline(cin, roll);
//    ifstream inFile("students.txt");
//    ofstream tempFile("temp.txt");
//    string line;
//    bool updated = false;
//    while (getline(inFile, line))
//    {
//        size_t pos = line.find(',');
//        string rollNumber = line.substr(pos + 1, line.find(',', pos + 1) - pos - 1);
//        if (rollNumber == roll) 
//        {
//            string name, department;
//            float gpa;
//            cout << "Enter New Name: ";
//            getline(cin, name);
//            cout << "Enter New Department: ";
//            getline(cin, department);
//            cout << "Enter New GPA: ";
//            cin >> gpa;
//            cin.ignore(); 
//            tempFile << name << "," << roll << "," << department << "," << gpa << endl;
//            updated = true;
//        }
//        else 
//        {
//            tempFile << line << endl;
//        }
//    }
//    inFile.close();
//    tempFile.close();
//    remove("students.txt");
//    rename("temp.txt", "students.txt");
//    if (updated) 
//    {
//        cout << "Record updated successfully.\n";
//    }
//    else 
//    {
//        cout << "Roll number not found.\n";
//    }
//}
//
//void deleteStudent() 
//{
//    string roll;
//    cout << "Enter Roll Number to delete: ";
//    cin.ignore();
//    getline(cin, roll);
//    ifstream inFile("students.txt");
//    ofstream tempFile("temp.txt");
//    string line;
//    bool deleted = false;
//    while (getline(inFile, line))
//    {
//        size_t pos = line.find(',');
//        string rollNumber = line.substr(pos + 1, line.find(',', pos + 1) - pos - 1);
//        if (rollNumber == roll) 
//        {
//            deleted = true;
//            continue; 
//        }
//        tempFile << line << endl;
//    }
//    inFile.close();
//    tempFile.close();
//    remove("students.txt");
//    rename("temp.txt", "students.txt");
//    if (deleted) {
//        cout << "Record deleted successfully.\n";
//    }
//    else {
//        cout << "Roll number not found.\n";
//    }
//    
//}