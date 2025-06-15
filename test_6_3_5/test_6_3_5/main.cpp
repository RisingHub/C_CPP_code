#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int num;
    float score;

public:
    // 构造函数
    Student(string n = "", int nu = 0, float s = 0.0) : name(n), num(nu), score(s) {}

    // Getter 函数
    string getName() const { return name; }
    int getNum() const { return num; }
    float getScore() const { return score; }

    // Setter 函数
    void setName(string n) { name = n; }
    void setNum(int nu) { num = nu; }
    void setScore(float s) { score = s; }

    // 重载输入输出运算符
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.name >> s.num >> s.score;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " " << s.num << " " << s.score;
        return os;
    }

    // 二进制读写函数
    void writeToFile(fstream& file) const {
        size_t len = name.length();
        file.write(reinterpret_cast<const char*>(&len), sizeof(len));
        file.write(name.c_str(), len);
        file.write(reinterpret_cast<const char*>(&num), sizeof(num));
        file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }

    void readFromFile(fstream& file) {
        size_t len;
        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        char* buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        name = buffer;
        delete[] buffer;
        file.read(reinterpret_cast<char*>(&num), sizeof(num));
        file.read(reinterpret_cast<char*>(&score), sizeof(score));
    }
};

int main() {
    // 创建初始数据文件
    {
        fstream initFile("stuinfo.dat", ios::out | ios::binary);
        if (!initFile) {
            cerr << "无法创建初始文件！" << endl;
            return 1;
        }
        Student initStu[] = {
            Student("Tom", 2024001, 89.2),
            Student("Mary", 2024002, 78.3),
            Student("Penny", 2024003, 90.2)
        };
        for (int i = 0; i < 3; ++i) {
            initStu[i].writeToFile(initFile);
        }
        initFile.close();
    }

    fstream fin("stuinfo.dat", ios::in | ios::binary);
    if (!fin) {
        cerr << "无法打开文件！" << endl;
        return 1;
    }

    fin.seekg(0, ios::end);
    int recordCount = fin.tellg() / sizeof(Student);
    Student* p = new Student[recordCount];
    fin.seekg(0, ios::beg);

    for (int i = 0; i < recordCount; ++i) {
        p[i].readFromFile(fin);
    }
    fin.close();

    int a;
    cin >> a;

    switch (a) {
        case 1: {
            for (int i = 0; i < recordCount; ++i) {
                cout << p[i] << endl;
            }
            break;
        }
        case 2: {
            int targetNum;
            float newScore;
            cin >> targetNum >> newScore;
            for (int i = 0; i < recordCount; ++i) {
                if (p[i].getNum() == targetNum) {
                    p[i].setScore(newScore);
                    break;
                }
            }
            break;
        }
        case 3: {
            Student* newP = new Student[recordCount + 1];
            for (int i = 0; i < recordCount; ++i) {
                newP[i] = p[i];
            }
            string name;
            int num;
            float score;
            cin >> name >> num >> score;
            newP[recordCount].setName(name);
            newP[recordCount].setNum(num);
            newP[recordCount].setScore(score);
            delete[] p;
            p = newP;
            recordCount++;
            break;
        }
        case 4: {
            int targetNum;
            cin >> targetNum;
            int newCount = 0;
            Student* newP = new Student[recordCount - 1];
            for (int i = 0; i < recordCount; ++i) {
                if (p[i].getNum() != targetNum) {
                    newP[newCount++] = p[i];
                }
            }
            delete[] p;
            p = newP;
            recordCount = newCount;
            break;
        }
    }

    fstream fout("stuinfo.dat", ios::out | ios::binary);
    if (!fout) {
        cerr << "无法打开文件写入！" << endl;
        delete[] p;
        return 1;
    }

    for (int i = 0; i < recordCount; ++i) {
        p[i].writeToFile(fout);
    }
    fout.close();

    delete[] p;
    return 0;
}    
