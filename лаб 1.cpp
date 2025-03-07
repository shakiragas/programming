#include <iostream>
#include <string>
using namespace std;

struct Element {
    string name;
    int intValue;
    double doubleValue;
    Element* next;
};

class List {
public:
    Element* head = nullptr;

    List(){}

    void add(const string& name, int intValue, double doubleValue) {
        Element* newElement = new Element{name, intValue, doubleValue};
        if (!head) {
            head = newElement;
        } else {
            Element* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newElement;
        }
    }

    void display() const {
        Element* temp = head;
        while (temp) {
            cout << "Name: " << temp->name
                 << ", Int Value: " << temp->intValue
                 << ", Double Value: " << temp->doubleValue << endl;
            temp = temp->next;
        }
    }

    ~List() {
        while (head) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    List myList;
    string command;

    while (true) {
        cout << "Введите команду (add, display, exit): ";
        cin >> command;

        if (command == "add") {
            string name;
            int intValue;
            double doubleValue;
            cout << "Введите имя, целое и дробное значение: ";
            cin >> name >> intValue >> doubleValue;
            myList.add(name, intValue, doubleValue);
        } else if (command == "display") {
            myList.display();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Неизвестная команда. Выберите одну из предложенных." << endl;
        }
    }

    return 0;
}
