#include <iostream>
#include <random>

/*
  **Encapsulation->Wrapping data & member functions in a single unit called
  class. Use case: Data hiding,

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

class Teacher {
private:
  double salary;

public:
  // Properties / Attributes
  string id;
  string name;
  string dept;
  string *subPtr;

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

  // Setter function
  void setSalary(double newSalary) { salary = newSalary; }

  // Getter function
  double getSalary() const { return salary; }

  // Constructors
  Teacher() { // Default / non-parameterized constructor
    id = generateRandomID();
    subPtr = new string; // Allocate memory for subPtr
  }

  Teacher(string name, string dept, string sub) { // Parameterized constructor
    id = generateRandomID();
    this->name = name;
    this->dept = dept;
    subPtr = new string;
    *subPtr = sub;
  }

  Teacher(const Teacher &obj) { // Copy constructor
    id = generateRandomID();
    this->name = obj.name;
    this->dept = obj.dept;
    subPtr = new string;
    *subPtr = *(obj.subPtr);
    this->salary = obj.salary;
  }

  Teacher &operator=(const Teacher &obj) { // Copy assignment operator
    if (this == &obj) {
      return *this; // Handle self-assignment
    }
    delete subPtr;       // Free existing memory
    subPtr = new string; // Allocate new memory
    *subPtr = *(obj.subPtr);
    this->name = obj.name;
    this->dept = obj.dept;
    this->salary = obj.salary;
    return *this;
  }

  ~Teacher() {     // Destructor
    delete subPtr; // Free dynamically allocated memory
  }
};

int main() {
  Teacher t1;
  t1.name = "Suresh Kumar";
  t1.dept = "Information Technology";
  *(t1.subPtr) = "Mathematics";
  t1.setSalary(25000);

  Teacher t2("Mukesh Benarji", "Political Science", "Current Affairs");
  t2.setSalary(20000);

  Teacher t3(t1);

  cout << t1.id << endl
       << t1.name << endl
       << t1.dept << endl
       << *(t1.subPtr) << endl
       << t1.getSalary() << endl;

  cout << endl;

  cout << t2.id << endl
       << t2.name << endl
       << t2.dept << endl
       << *(t2.subPtr) << endl
       << t2.getSalary() << endl;

  cout << endl;

  cout << t3.id << endl
       << t3.name << endl
       << t3.dept << endl
       << *(t3.subPtr) << endl
       << t3.getSalary() << endl;

  return 0;
}
