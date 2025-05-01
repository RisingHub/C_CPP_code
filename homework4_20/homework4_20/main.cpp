#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}
    ~Date() {}

    void show(ostream& out) const {
        out << year << "-" << month << "-" << day;
    }

    void input(istream& in) {
        in >> year >> month >> day;
    }
};

class Person {
protected:
    string name;
    int age;
    Date birth;

public:
    Person() : name(""), age(0), birth() {}
    Person(string n, int a, int y, int m, int d) : name(n), age(a), birth(y, m, d) {}
    Person(const Person& p) : name(p.name), age(p.age), birth(p.birth) {}
    virtual ~Person() {}

    void show(ostream& out) const {
        out << "name:" << name << endl
            << "age:" << age << endl
            << "birth:";
        birth.show(out);
        out << endl;
    }

    void input(istream& in) {
        in >> name >> age;
        birth.input(in);
    }
};

class Student : public Person {
protected:
    int id;

public:
    Student() : Person(), id(0) {}
    Student(string n, int a, int i, int y, int m, int d) : Person(n, a, y, m, d), id(i) {}
    Student(const Student& s) : Person(s), id(s.id) {}
    ~Student() {}

    void show(ostream& out) const {
        Person::show(out);
        out << "id:" << id << endl;
    }

    void input(istream& in) {
        Person::input(in);
        in >> id;
    }
};

ostream& operator<<(ostream& out, const Person& p) {
    p.show(out);
    return out;
}



istream& operator>>(istream& in, Person& p) {
    p.input(in);
    return in;
}

istream& operator>>(istream& in, Student& s) {
    s.input(in);
    return in;
}

ostream& operator<<(ostream& out, const Student& p) {
    p.show(out);
    return out;
}

int main() {
    Person p;
    Student s;
    cin >> p >> s;
    cout << p << s;
    return 0;
}
