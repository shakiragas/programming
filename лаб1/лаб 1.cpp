#include <iostream>
#include <string>
using namespace std;

class MyList {
private:
    struct Node {
        string name;
        int amount;
        double doubleValue;
        Node* next;
    };

    Node* head;

    Node* CreateNode(string newName, int n, double p) {
        Node* newNode = new Node;
        newNode->name = newName;
        newNode->amount = n;
        newNode->doubleValue = p;
        newNode->next = nullptr;
        return newNode;
    }

public:
    MyList() : head(nullptr) {}

    void AddFirst(string newName, int n, double p) {
        Node* newNode = CreateNode(newName, n, p);
        newNode->next = head;
        head = newNode;
    }

    void AddLast(string newName, int n, double p) {
        Node* newNode = CreateNode(newName, n, p);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }

    int AddAfter(string newName, int n, double p, string nameAfter) {
        if (head == nullptr) return 1;
        Node* tmp = head;
        while (tmp != nullptr && tmp->name != nameAfter) {
            tmp = tmp->next;
        }
        if (tmp == nullptr) return 1;
        Node* newNode = CreateNode(newName, n, p);
        newNode->next = tmp->next;
        tmp->next = newNode;
        return 0;
    }

    int AddBefore(string newName, int n, double p, string nameBefore) {
        if (head == nullptr) return 1;
        if (head->name == nameBefore) {
            AddFirst(newName, n, p);
            return 0;
        }
        Node* prev = head;
        Node* tmp = head->next;
        while (tmp != nullptr && tmp->name != nameBefore) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == nullptr) return 1;
        Node* newNode = CreateNode(newName, n, p);
        newNode->next = tmp;
        prev->next = newNode;
        return 0;
    }

    int DelNode(string delName) {
        if (head == nullptr) return 1;
        if (head->name == delName) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            return 0;
        }
        Node* prev = head;
        Node* tmp = head->next;
        while (tmp != nullptr && tmp->name != delName) {
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == nullptr) return 1;
        prev->next = tmp->next;
        delete tmp;
        return 0;
    }

    void PrintList() {
        if (head == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }
        Node* tmp = head;
        while (tmp != nullptr) {
            cout << "Name: " << tmp->name << ", Amount: " << tmp->amount << ", DoubleValue: " << tmp->doubleValue << endl;
            tmp = tmp->next;
        }
    }
};

int main() {
    MyList studentList;
    MyList decanatList;

    studentList.AddFirst("John Doe", 1, 1034.45);
    studentList.AddLast("Jane Smith", 2, 2134.46);
    studentList.AddAfter("Bob Johnson", 3, 1504.0, "John Doe");
    studentList.AddBefore("Alice Williams", 4, 2504.456, "Jane Smith");

    decanatList.AddFirst("Dean Smith", 1, 5023.45);
    decanatList.AddLast("Assistant Dean Johnson", 1, 2350.45);
    decanatList.AddAfter("Secretary Lee", 1, 2164.56, "Dean Smith");
    decanatList.AddBefore("Registrar Wang", 1, 4340.46, "Assistant Dean Johnson");

    cout << "Student List:" << endl;
    studentList.PrintList();

    cout << "\nDecanat List:" << endl;
    decanatList.PrintList();

    return 0;
}
