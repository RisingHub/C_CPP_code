#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Student{

private:

    char * name;  //名字

    int age;           //年龄

    int score;        //成绩

    static int TotalScore;  //总成绩

    static int TotalNum;   //总人数

public:

    Student()                //键盘输入学生姓名、年龄、成绩
    {
        char tmp[110] = {0};
        cin >> tmp;
        name = new char[strlen(tmp) + 1];
        strcpy(name, tmp);
        cin >> age >> score;
        TotalScore += score;
        TotalNum++;
    }
    void print1()             //输出学生姓名、年龄、成绩
    {
        cout << name << " " << age << " " << score << endl;
    }
    static void print2()   //输出学生总人数、平均成绩
    {
        
        cout << TotalNum << " " << fixed << setprecision(2) << (double)TotalScore/TotalNum << endl;
    }
};
int Student::TotalScore = 0;
int Student::TotalNum = 0;
int main()
{
    int n; cin >> n;
    Student* stu = new Student[n];
    for(int i = 0; i < n; i++)
    {
        stu[i].print1();
    }
    Student::print2();
    return 0;
}

