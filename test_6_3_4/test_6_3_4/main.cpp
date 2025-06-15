#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
private:
    string name;
    int num;
    float score;

public:
    // 默认构造函数
    Student() : name(""), num(0), score(0) {}

    // 带参数的构造函数
    Student(const string& n, int id, float s) : name(n), num(id) {
        if (s >= 0 && s <= 100) {
            score = s;
        } else {
            score = 0;
        }
    }

    // 获取成绩
    float getScore() const {
        return score;
    }

    // 重载输入运算符
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.name >> s.num >> s.score;
        if (s.score < 0 || s.score > 100) {
            s.score = 0;
        }
        return is;
    }

    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " " << s.num << " " << s.score;
        return os;
    }
};

int main() {
    ifstream fin("stuin.txt");
    if (!fin.is_open()) {
        cerr << "无法打开输入文件" << endl;
        return 1;
    }

    vector<Student> students;
    Student s;

    // 读取所有学生信息
    while (fin >> s) {
        students.push_back(s);
    }

    fin.close();

    // 查找成绩最高的学生
    if (students.empty()) {
        cerr << "没有找到学生信息" << endl;
        return 1;
    }

    auto highest = max_element(students.begin(), students.end(),
                              [](const Student& a, const Student& b) {
                                  return a.getScore() < b.getScore();
                              });

    // 输出到文件
    ofstream fout("stuout.txt");
    if (!fout.is_open()) {
        cerr << "无法打开输出文件" << endl;
        return 1;
    }

    fout << *highest << endl;
    fout.close();

    return 0;
}    
