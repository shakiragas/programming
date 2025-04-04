#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
    Animal(string name) : name(name) {}
    virtual void sound() {
    }
    
    virtual void sound(string message) {
        cout << "Sound: " << message << endl;
    }

    void info() {
        cout << "Name: " << name << endl;
        sound();
    }

protected:
    string name;
};

class Dog : public Animal {
public:
    Dog(string name, string breed) : Animal(name), breed(breed) {}

    void sound() override {
        cout << "Woof!" << endl;
    }

    void sleep() {
        cout << name << " is sleeping" << endl;
    }

private:
    string breed;
};

class Cat : public Animal {
public:
    Cat(string name, string color) : Animal(name), color(color) {}

    void sound() override {
        cout << "Meow!" << endl;
    }

    void eat() {
        cout << name << " is eating" << endl;
    }

private:
    string color;
};

int main() {
    Dog myDog("Bobik", "Golden Retriever");
    Cat myCat("Lapok", "Gray");
    Animal Animal("Cow");

    cout << "Dog:" << endl;
    myDog.info();
    myDog.sleep();
    cout << endl;

    cout << "Cat:" << endl;
    myCat.info();
    myCat.eat();
    cout << endl;

    cout << "Cow:" << endl;
    Animal.info();
    Animal.sound("Mu!");
    cout << endl;

    return 0;
}
