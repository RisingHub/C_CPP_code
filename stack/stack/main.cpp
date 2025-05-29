#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack{
private:

    T elements[100];//假定堆栈内元素数目不会超过100

    int size;//记录堆栈内元素数目

public:

    Stack();//构造函数，size赋值为0

    bool empty()const;//判断堆栈是否为空，也就是size是否为0

    T peek()const;//返回栈顶元素，也就是数组elements中最后一个元素，size大小不变

    void push(T value);//压栈，向数组中加入一个新元素，size加1

    T pop();//弹出栈顶元素，也就是数组最后一个元素，size减1

    int getSize()const;

};

template <typename T>
Stack<T>::Stack() : size(0) {}

template <typename T>
bool Stack<T>::empty() const {
    return size == 0;
}

template <typename T>
T Stack<T>::peek() const{
    return elements[size - 1];
}

template <typename T>
void Stack<T>::push(T value) {
    elements[size++] = value;
}

template <typename T>
T Stack<T>::pop() {
    return elements[--size];
}

template <typename  T>
int Stack<T>::getSize()const {
    return size;
}

int main()
{
    Stack<int> ist;
    int i;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> i;
        ist.push(i);
    }
    
    Stack<string> sst;
    cin >> n;
    while(n--){
        string s; cin >> s;
        sst.push(s);
    }
    
    while(!ist.empty()){
        int t = ist.pop();
        cout << t << " ";
    }cout << endl;
    while(!sst.empty()){
        string t = sst.pop();
        cout << t << " ";
    }cout << endl;
//    Stack<int> tempist;
//    while(!ist.empty()){
//        int t = ist.pop();
//        tempist.push(t);
//    }
//    while(!tempist.empty()){
//        int t = tempist.pop();
//        cout << t << " ";
//    }
//    cout << endl;
//    
//    
//    Stack<string> tempsst;
//    while(!sst.empty()){
//        string t = sst.pop();
//        tempsst.push(t);
//    }
//    while(!tempsst.empty()){
//        string t = tempsst.pop();
//        cout << t << " ";
//    }
//    
    
    return 0;
}
