#include <iostream>
using namespace std;

template <class TYPE>
void bubble (TYPE A[], int len)
{
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(A[j] > A[j+1]){
                TYPE t = A[j];
                A[j] = A[j+1];
                A[j+1] = t;
            }
        }
    }
    for(int i = 0; i < len; i++) cout << A[i] << " ";
    cout << endl;
}
int main()
{
    int len_int;

    int len_char;

    int len_double;

    int i;

    int A[100];

    char B[100];

    double C[100];

    //输入int数据的个数及值

    cin>>len_int;

    for(i=0;i<len_int;i++)

    {

    cin>>A[i];

    }

    //输入char数据的个数及值

    cin>>len_char;

    for(i=0;i<len_char;i++)

    {

    cin>>B[i];

    }

    //输入double数据的个数及值

    cin>>len_double;

    for(i=0;i<len_double;i++)

    {

    cin>>C[i];

    }

    // 此处调用 bubble 函数得到A、B、C三个数组中从小到大排序后的结果

    // .....
    bubble(A, len_int);
    bubble(B, len_char);
    bubble(C, len_double);
    
    return 0;
}
