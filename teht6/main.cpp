#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    string n;
    int a;

    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
            case 0:
                // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
                cout << "Enter student name: " << endl;
                cin >> n;
                cout << "Enter student age: " << endl;
                cin >> a;
                // Lisää uusi student StudentList vektoriin
                {
                    Student newStudent(n, a);
                    studentList.push_back(newStudent);
                }
            break;

            case 1:
                // Tulosta StudentList vektorin kaikkien opiskelijoiden nimet.
                if (studentList.empty()){
                cout << "No students in list" << endl;
                } else {
                    for (auto& student : studentList){
                        student.printStudentinfo();
                    }
                }
            break;

            case 2:
                // Järjestä StudentList vektorin Student oliot nimen mukaan
                // algoritmikirjaston sort funktion avulla
                sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                    return a.getName() < b.getName();
                });
                // ja tulosta printStudentInfo() funktion avulla järjestetyt opiskelijat
                for (auto& student : studentList) {
                    student.printStudentinfo();
                }
            break;

            case 3:
                // Järjestä StudentList vektorin Student oliot iän mukaan
                // algoritmikirjaston sort funktion avulla
                sort(studentList.begin(), studentList.end(), [](Student& a, Student& b){
                    return a.getAge() < b.getAge();
                });
                // tulosta printStudentInfo() funktion avulla järjestetyt opiskelijat
                for (auto& student : studentList) {
                    student.printStudentinfo();
                }
            break;

            case 4:
                // Kysy käyttäjältä opiskelijan nimi
                cout << "Enter student name: " << endl;
                cin >> n;
                // Etsi studentListan opiskelijoista algoritmikirjaston
                // find_if funktion avulla löytyykö käyttäjän antamaa nimeä listalta.
                {
                    auto it = find_if(studentList.begin(), studentList.end(), [&](Student& student) {
                        return student.getName() == n;
                    });
                    //Jos löytyy, niin tulosta opiskelijan tiedot.
                    if (it != studentList.end()){
                        it->printStudentinfo();
                    } else {
                        cout << "Student not found" << endl;
                    }
                }
            break;

            default:
                cout<< "Wrong selection, stopping..."<<endl;
            break;
        }

}while(selection < 5);

return 0;
}
