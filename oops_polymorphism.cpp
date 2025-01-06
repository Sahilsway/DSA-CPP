#include <iostream>

/*
  **Polymorphism->Ability of objects to take on different forms or behave in
  different ways depending on the context in which they are used.

  Hint: Function overloading.

  Types: Compile time polymorphism, Run time polymorphism.

  *Compile time polymorphism: Constructor overloading, function overloading,
  variable overloading.
  *Run time polymorphism: Function overriding, vertual
  function.

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

class PrintInfo {
public:
  string name;
  int age;

  // Compile Time Polymorphism with contructor overloading
  PrintInfo() {}
  PrintInfo(string name, int age) {
    this->name = name;
    this->age = age;
  }

  // Compile Time Polymorphism with fucntion overloading
  void printData(string name, int age) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
  void printData(PrintInfo &obj) {
    cout << "Name: " << obj.name << endl;
    cout << "Age: " << obj.age << endl;
  }
};

int main() {
  PrintInfo data1;
  PrintInfo data2("McLeren DC", 13);

  data1.printData("Suhash Desai", 43);
  data1.printData(data2);

  return 0;
}
