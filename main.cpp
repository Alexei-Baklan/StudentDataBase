#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string name;
    string lastName;
    int age;
};

int main(){
    Student student1 = {"Mikle", "Shmit", 20};
    Student student2 = {"Oleg", "Gordon", 15};

    string school;
    cout << "Enter the name of the file from which you want to read the text" << endl;
    cin >> school;
    ifstream input_file(school);

    std::ofstream output_file("DataBaseStudent.txt");
    if (output_file.is_open())
    {
        output_file << "Name:" << student1.name << " Last-Name:" << student1.lastName << " Age:" << student1.age << endl;
        output_file << "Name:" << student2.name << " Last-Name:" << student2.lastName << " Age:" << student2.age << endl;
        output_file.close();
    }

    string line;
    if (input_file.is_open())
    {
        while (getline(input_file, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "file if not fined" << endl;
    }

    return 0;
}