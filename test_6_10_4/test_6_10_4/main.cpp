#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define NUM 100 // 学生数量上限

class Student {
private:
    char name[20]; // 注意为了写入二进制文件，使用C风格字符串
    int num;
    float score;

public:
    Student() {
        strcpy(name, "");
        num = 0;
        score = 0.0;
    }

    Student(const string& n, int no, float s) {
        setName(n);
        num = no;
        score = s;
    }

    void setName(const string& n) {
        strncpy(name, n.c_str(), sizeof(name));
        name[sizeof(name) - 1] = '\0'; // 确保字符串结束
    }

    void setNum(int no) { num = no; }
    void setScore(float s) { score = s; }

    string getName() const { return string(name); }
    int getNum() const { return num; }
    float getScore() const { return score; }

    void input() {
        string n;
        int no;
        float s;
        cin >> n >> no >> s;
        setName(n);
        setNum(no);
        setScore(s);
    }

    void display() const {
        cout << name << " " << num << " " << score << endl;
    }
};

// 全局学生计数
int count = 0;

int main() {
    Student* p = new Student[NUM];

    // 读取文件内容
    fstream fin("stuinfo.dat", ios::in | ios::binary);
    if (fin) {
        int i = 0;
        while (fin.read((char*)(p + i), sizeof(Student))) {
            i++;
        }
        count = i;
        fin.close();
    }

    int a;
    while (true) {
        cin >> a;
        switch (a) {
        case 0:
            // 显示所有学生信息
            for (int i = 0; i < count; ++i) {
                p[i].display();
            }
            break;

        case 1:
            // 显示所有学生信息
            for (int i = 0; i < count; ++i) {
                p[i].display();
            }
            break;

        case 2: {
            // 修改成绩
            int no;
            float newScore;
            cin >> no >> newScore;
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (p[i].getNum() == no) {
                    p[i].setScore(newScore);
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "" << endl;
            break;
        }

        case 3:
            // 增加学生
            if (count < NUM) {
                p[count].input();
                count++;
            } else {
                cout << "Student list is full!" << endl;
            }
            break;

        case 4: {
            // 删除学生
            int no;
            cin >> no;
            bool found = false;
            for (int i = 0; i < count; ++i) {
                if (p[i].getNum() == no) {
                    // 用后面的记录前移覆盖当前
                    for (int j = i; j < count - 1; ++j) {
                        p[j] = p[j + 1];
                    }
                    count--;
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "" << endl;
            break;
        }

        default:
            cout << "" << endl;
        }

        if (a == 0)
            break;
    }

    // 写入二进制文件
    fstream fout("stuinfo.dat", ios::out | ios::binary);
    for (int i = 0; i < count; ++i) {
        fout.write((char*)(p + i), sizeof(Student));
    }
    fout.close();

    // 释放内存
    delete[] p;

    return 0;
}




