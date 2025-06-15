#include <iostream>
#include <iomanip>
using namespace std;
class Student{
private:
    int num;
    float score;
    static int TotalNumber;
    static float TotalScore;
    static int MaxNum;
    static float MaxScore;
public:
    Student(int _num = 0, float _score = 0)
    :num(_num)
    {
        if(_score >= 0 && _score <= 100){
            score = _score;
        }else{
            score = 0;
        }
        TotalNumber++;
        TotalScore += score;
        if(score > MaxScore){
            MaxScore = score;
            MaxNum = num;
        }
    }
    static void show(){
        cout << TotalScore / TotalNumber << endl;
        cout << MaxNum << " "  << MaxScore << endl;
    }
    
};
int Student::TotalNumber = 0;
float Student::TotalScore = 0;
int Student::MaxNum = 0;
float Student::MaxScore = 0;
int main()
{
    int n; cin >> n;
    while(n--){
        int num;
        float score;
        cin >> num >> score;
        Student stu(num, score);
    }
    Student::show();
    
    return 0;
}
