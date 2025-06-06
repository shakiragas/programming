#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    string name;
    string age;
    string grade;

    string toString() const {
        return name + " " + age + " " + grade;
    }

    void fromStream(istream& input) {
        input >> name >> age >> grade;
    }
};

class StudentDatabase {
private:
    vector<Student> students;
    const string filename = "students.txt";

public:
    void addStudent() {
        Student s;
        cout << "Имя: ";
        cin >> s.name;
        cout << "Возраст: ";
        cin >> s.age;
        cout << "Класс: ";
        cin >> s.grade;
        students.push_back(s);
        cout << "Студент добавлен\n";
    }

    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& s : students) {
                file << s.toString() << "\n";
            }
            cout << "Данные сохранены в файл\n";
        } else {
            cout << "Ошибка при сохранении\n";
        }
    }

    void loadFromFile() {
        ifstream file(filename);
        students.clear();
        if (file.is_open()) {
            Student s;
            while (file >> s.name >> s.age >> s.grade) {
                students.push_back(s);
            }
            cout << "Количество студентов: " << students.size() << "\n";
        } else {
            cout << "Файл не найден\n";
        }
    }

    void updateStudent() {
        if (students.empty()) {
            cout << "Список студентов пуст\n";
            return;
        }

        cout << "Введите номер студента для изменения: ";
        size_t index;
        cin >> index;

        if (index < students.size()) {
            cout << "Новое имя: ";
            cin >> students[index].name;
            cout << "Новый возраст: ";
            cin >> students[index].age;
            cout << "Новый класс: ";
            cin >> students[index].grade;
            cout << "Данные студента обновлены\n";
        } else {
            cout << "Неверный номер студента\n";
        }
    }

    void deleteStudent() {
        if (students.empty()) {
            cout << "Список студентов пуст\n";
            return;
        }

        cout << "Введите номер студента для удаления: ";
        size_t index;
        cin >> index;

        if (index < students.size()) {
            students.erase(students.begin() + index);
            cout << "Студент удален\n";
        } else {
            cout << "Неверный номер студента\n";
        }
    }
};

int main() {
    StudentDatabase db;
    db.loadFromFile();

    while (true) {
        cout << "\nМеню:\n"
             << "1. Добавить студента\n"
             << "2. Обновить\n"
             << "3. Удалить студента\n"
             << "4. Считать из файла\n"
             << "5. Сохранить данные\n"
             << "Выберите: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: db.addStudent(); break;
            case 2: db.updateStudent(); break;
            case 3: db.deleteStudent(); break;
            case 4: db.loadFromFile(); break;
            case 5: db.saveToFile();
                return 0;
            default:
                cout << "Такого выбора нет, выберите из списка.\n";
        }
    }
}
