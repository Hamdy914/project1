#include <iostream>
#include <string>
#include<vector>
#include<fstream>


using namespace std;

class Person {
public:
    string name;
    int age;
    int id;


    Person(string name, int age, int id) {
        this->name = name;
        this->age = age;
        this->id = id;
    }
    Person(){
    }


    virtual void role()=0;

};

class Manager : public Person {
private:
    int salary;

    Manager(string name, int age, int id) : Person(name, age, id) {
        salary = 0;
    }

    ~Manager() {}

public:
    static Manager& getInstance() {
        static Manager instance("John Doe", 30, 12345);
        return instance;
    }

    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;

    void role() {
        cout << "Manager" << endl;
    }

    void setSalary(int s) {
        salary = s;
    }

    int getSalary() {
        return salary;
    }
};

class Student : public Person {
private:
    float GPA;

public:
    Student(string name, int age, int id, float GPA) : Person(name, age, id) {
        this->GPA = GPA;
    }

    void role() {
        cout << "Student" << endl;
    }

    float getGPA() {
        return GPA;
    }
};
class Instructor : public Person {

public:
    int salary;
    int hours;

      Instructor(){
}
Instructor(int s ,int h){

salary=s;
hours=h;
}

    void role() {
        cout << "Instructor" << endl;
    }

    int getSalary() {
        return salary;
    }

    int getHours() {
        return hours;
    }
};
class Employee : public Person {
public:
    int salary;



     Employee(int s){
     salary=s;
     }
     Employee(){
     }
    void role() {
        cout << "Employee" << endl;
    }


};
class Course {
    public:
       string title;
    int course_id;


       Course(string t){

    title=t;
    }
    Course(){
    }

    void details() {
        cout << "Course Title: " << title << endl;
        cout << "Course ID: " << course_id << endl;
    }

};

class Department {
public:

    string title;
    vector<Course> courses;

    Department(string t){

    title=t;
    }
    Department(){
    }


    void details() {
        cout << "Department Title: " << title << endl;
        cout << "Courses:" << endl;
        for (const auto& course : courses) {

        }
    }

    void addCourse(const Course& course) {
        courses.push_back(course);
        saveDataToFile();
    }

private:
    void saveDataToFile() {
        ofstream file("Department.txt");
        if (file.is_open()) {
            file << "Department Title: " << title << endl;
            file << "Added Course:" << endl;
            for (const auto& course : courses) {

            }
            file.close();
        }
    }
};



class Faculty {
public:
    string title;
    vector<Student> students;
    vector<Instructor> instructors;
    vector<Employee> employees;
    vector<Department> departments;


    Faculty(string title) : title(title) {}

    void details() {
        cout << "Faculty Title: " << title << endl;
    }

    void addStudent(Student student) {
        students.push_back(student);

        ofstream file("Student.txt");
        if (file.is_open()) {
            file << "Student Added: " << endl;
            file<< "sjdjhahd"<<endl;

            file.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }

    void addInstructor(Instructor instructor) {
        instructors.push_back(instructor);

        ofstream file("Instructor.txt", ios::app);
        if (file.is_open()) {
            file << "Instructor Added: " << endl;
            file.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }

    void addEmployee(Employee employee) {
        employees.push_back(employee);

        ofstream file("Employee.txt");
        if (file.is_open()) {
            file << "Employee Added: " << endl;
            file.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }

    void addDepartment(Department department) {
        departments.push_back(department);

        ofstream file("faculty_data.txt", ios::app);
        if (file.is_open()) {
            file << "Department Added: " << endl;
            file.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }
};




class University {

public:
    string title;
    vector<Faculty> faculties;

    University(string t)  {

    title =t;

    }
    University(){
    }

    void details() {
        cout << "University Title: " << title << endl;

    }
    private:


    void addFaculty(Faculty faculty) {
        faculties.push_back(faculty);


        ofstream file("faculty.txt");
        if (file.is_open()) {
            file << "Faculty Added: " << endl;

            file.close();
        } else {
            cout << "Error opening the file!" << endl;
        }
    }
};



int main()
{
      Manager& manager = Manager::getInstance();

    manager.setSalary(5000);
    cout << "Salary: " << manager.getSalary() << endl;


    manager.role();

    Student student("John Doe", 18, 12345, 3.8);

    student.getGPA();

    cout << "GPA: " << student.getGPA() << endl;

    student.role();

   Instructor s1;

     s1.getSalary();
     s1.getHours();

    cout << "Salary: " << s1.getSalary() << endl;
    cout << "Hours: " << s1.getHours() << endl;

    s1.role();
Employee e;

    e.role();
 University u("My University");

 Course c;
 Department d;
    d.addCourse(c);

    d.details();

    return 0;


}
