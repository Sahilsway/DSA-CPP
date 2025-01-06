#include <iostream>

/*
  **Abstraction->Hiding all the sensitive or unnecessary details and showing
  only the important parts.

  Hint: Access modifers & abstract class.

  *Abstract class: Used as a Shape class for other derived classes. Cannot be
  instantiated meaning cannot create object of this type of class but meant to
  be inherited. Generally used to define interface for derived classes.

  Types: Public, private, protected.

  *Static: Used to create variable or object that can be initialized with a
  value only once that exist thouout the life time of the program.

  *Friend class:
  *Friend function:

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

class Shape { // Abstract class
public:
  virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
  int private_variable;

protected:
  int protected_variable;

public:
  void draw() override { cout << "Drawing Circle" << endl; }

  Circle() {
    private_variable = 10;
    protected_variable = 99;
  }

  friend void friendFunction(Circle &obj); // Friend function declaration
};

void friendFunction(Circle &obj) { // Friend function definition
  cout << "Private Variable: " << obj.private_variable << endl;
  cout << "Protected Variable: " << obj.protected_variable << endl;
}

int main() {
  Circle object1;
  object1.draw();
  friendFunction(object1);

  return 0;
}
