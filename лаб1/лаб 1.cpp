#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int amount;
    double doubleValue;
    Node* next;
};

Node* CreateNode(string newName, int n, double p) {
    Node* newNode = new Node;
    newNode->name = newName;
    newNode->amount = n;
    newNode->doubleValue = p;
    newNode->next = NULL;
    return newNode;
}

void AddFirst(Node*& head, string newName, int n, double p) {
    Node* newNode = CreateNode(newName, n, p);
    newNode->next = head;
    head = newNode;
}

void AddLast(Node*& head, string newName, int n, double p) {
    Node* newNode = CreateNode(newName, n, p);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int AddAfter(Node* head, string newName, int n, double p, string nameAfter) {
    if (head == NULL) return 1;
    Node* tmp = head;
    while (tmp != NULL && tmp->name != nameAfter) {
        tmp = tmp->next;
    }
    if (tmp == NULL) return 1;
    Node* newNode = CreateNode(newName, n, p);
    newNode->next = tmp->next;
    tmp->next = newNode;
    return 0;
}

int AddBefore(Node*& head, string newName, int n, double p, string nameBefore) {
    if (head == NULL) return 1;
    if (head->name == nameBefore) {
        AddFirst(head, newName, n, p);
        return 0;
    }
    Node* prev = head;
    Node* tmp = head->next;
    while (tmp != NULL && tmp->name != nameBefore) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return 1;
    Node* newNode = CreateNode(newName, n, p);
    newNode->next = tmp;
    prev->next = newNode;
    return 0;
}

int DelNode(Node*& head, string delName) {
    if (head == NULL) return 1;
    if (head->name == delName) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return 0;
    }
    Node* prev = head;
    Node* tmp = head->next;
    while (tmp != NULL && tmp->name != delName) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return 1;
    prev->next = tmp->next;
    delete tmp;
    return 0;
}

void PrintList(Node* head) {
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    Node* tmp = head;
    while (tmp != NULL) {
        cout << "Product: " << tmp->name << ", Amount: " << tmp->amount << ", Price: " << tmp->doubleValue << endl;
        tmp = tmp->next;
    }
}

int main() {
    Node* head = NULL;
    int choice, n;
    double p;
    string name, nameAfter, nameBefore;

    while (true) {
        cout << "1. Add to beginning" << endl;
        cout << "2. Add to end" << endl;
        cout << "3. Add after" << endl;
        cout << "4. Add before" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name, amount, doubleValue: ";
            cin >> name >> n >> p;
            AddFirst(head, name, n, p);
            break;
        case 2:
            cout << "Enter name, amount, doubleValue: ";
            cin >> name >> n >> p;
            AddLast(head, name, n, p);
            break;
        case 3:
            cout << "Enter new name, amount, doubleValue, and name to add after: ";
            cin >> name >> n >> p >> nameAfter;
            AddAfter(head, name, n, p, nameAfter);
            break;
        case 4:
            cout << "Enter new name, amount, doubleValue, and name to add before: ";
            cin >> name >> n >> p >> nameBefore;
            AddBefore(head, name, n, p, nameBefore);
            break;
        case 5:
            cout << "Enter name to delete: ";
            cin >> name;
            DelNode(head, name);
            break;
        case 6:
            PrintList(head);
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}
