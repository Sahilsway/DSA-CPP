#include <iostream>
#include <random>

/*
  **Inheritance->Properties/data & member functions of base or parent class are
  passed on to the derived or child class. Use case: Code reusability,

  Types: Single level inheritance, Multilevel inheritance, Multiple inheritance,
  Hierarchial inheritance, Hybrid inheritance.

  *Constructor->Special method invoked automatically at the time of object
  creation.
  Use Case: Data initialisation
  Properties: Same name as class, always declared as public method, doesn't need
  have any return type, only called once at the time of object creation, memory
  allocation happends at the time of contructor call.

  *Destructor->Special method invoked automatically at the time of object
  creation.
  Use Case: Data deletion
  Properties: Same name as class except it has a '~' symbol infront of it,
  always declared as public method, doesn't need have any return type, only
  called once at the time of object going out of scope, memory deletion happends
  at the time object going out of scope.

  *Shallow copy->Copy data statically from one object to another.
  *Deep copy->Copy data in runtime dynamically from one object to another.
*/

using namespace std;

class Person { // Parent / Base class
public:
  string name;
  int age;
  float height;

  Person(string name, int age, float height) {
    this->name = name;
    this->age = age;
    this->height = height;
  }
};

/*_*\ Single Level inheritance \*_*/
class Teacher : public Person {
public:
  string dept;
  string sub;

  Teacher(string name, int age, float height, string dept, string sub)
      : Person(name, age, height) {
    this->dept = dept;
    this->sub = sub;
  }
};

/*_*\ Multilevel inheritance \*_*/
class Student : public Teacher { // Child / Derived class
public:
  int rollNo;
  int grade;

  Student(string name, int age, float height, string dept, string sub,
          int rollNo, int grade)
      : Teacher(name, age, height, dept, sub) {
    this->rollNo = rollNo;
    this->grade = grade;
  }
};

class Job { // Parent / Base class
public:
  string role;
  string position;

  Job(string role, string position) {
    this->role = role;
    this->position = position;
  }
};

/*_*\ Multiple inheritance \*_*/
class Employee : public Person, public Job { // Child / Derived class
public:
  string id;

  // Methods / Member functions
  string generateRandomID() {
    string id;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 9);
    for (int i = 0; i < 10; ++i) {
      id += to_string(dist(gen));
    }
    return id;
  }

  Employee(string name, int age, float height, string role, string position)
      : Person(name, age, height), Job(role, position) {
    id = generateRandomID();
  }
};

/*_*\ Multiple inheritance \*_*/
class Engineer : public Person {
public:
  string company;

  Engineer(string name, int age, float height, string company)
      : Person(name, age, height) {
    this->company = company;
  }
};
/*_*\ Multiple inheritance \*_*/
class Doctor : public Person {
public:
  string hospital;

  Doctor(string name, int age, float height, string hospital)
      : Person(name, age, height) {
    this->hospital = hospital;
  }
};

/*_*\ Hybrid inheritance \*_*/
// Mix of different types of other inheritance used above

int main() {
  /*_*\ Single Level Inheritance \*_*/
  Teacher t1("Austin Martin", 43, 6.2, "Physics", "Quantum Physics");
  cout << "--Single Level Iheritance--" << endl;
  cout << "Name: " << t1.name << endl
       << "Age: " << t1.age << endl
       << "Height: " << t1.height << endl
       << "Department: " << t1.dept << endl
       << "Subject: " << t1.sub << endl;

  cout << endl;

  /*_*\ Multilevel Inheritance \*_*/
  Student s1("John Doe", 21, 6.8, "Science", "Physics", 35, 10);
  cout << "--Multilevel Inheritance--" << endl;
  cout << "Name: " << s1.name << endl
       << "Age: " << s1.age << endl
       << "Height: " << s1.height << endl
       << "Department: " << s1.dept << endl
       << "Subject: " << s1.sub << endl
       << "Roll No: " << s1.rollNo << endl
       << "Grade: " << s1.grade << endl;

  cout << endl;

  /*_*\ Multiple Inheritance \*_*/
  Employee e1("John Doe", 21, 6.8, "Data analyst", "Senior");
  cout << "--Multiple Inheritance--" << endl;
  cout << "Name: " << e1.name << endl
       << "Age: " << e1.age << endl
       << "Height: " << e1.height << endl
       << "Role: " << e1.role << endl
       << "Position: " << e1.position << endl;

  cout << endl;

  /*_*\ Hierarchial Inheritance \*_*/
  Engineer en1("John Doe", 27, 6.8, "Google");
  Doctor d1("Dr Smith Martin", 54, 5.8, "Apollo");
  cout << "--Hierarchial Inheritance--" << endl;
  cout << "Name: " << en1.name << endl
       << "Age: " << en1.age << endl
       << "Height: " << en1.height << endl
       << "Company: " << en1.company << endl;

  cout << endl;

  cout << "Name: " << d1.name << endl
       << "Age: " << d1.age << endl
       << "Height: " << d1.height << endl
       << "Hospital: " << d1.hospital << endl;

  cout << endl;
  cout << "--Hybrid inheritance--" << endl;
  cout << "**Mix of different types of other inheritance used above**" << endl;

  return 0;
}
