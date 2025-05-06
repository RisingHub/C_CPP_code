#include <iostream>
#include <cstring>

using namespace std;
class myString{

private:
    char *buffer;
    void copy(const char* cstr)
    {
        buffer = new char[strlen(cstr)+1];
        strcpy(buffer, cstr);
    }
    
    void copy(const myString& s)
    {
        buffer = new char[s.getLength()+1];
        strcpy(buffer, s.buffer);
    }
public:

    myString()
    {
        buffer = new char[1];
        buffer[0] = '\0';
    }
    myString(const char &c)
    {
        buffer = new char[2];
        buffer[0] = c;
        buffer[1] = '\0';
    }
    myString(const char *cStr)
    {
        if(cStr == nullptr)
        {
            buffer = new char[1];
            buffer[0] = '\0';
        }
        else
        {
            copy(cStr);
        }
    }
    myString(const myString &s)
    {
        copy(s);
    }
    ~myString()
    {
        //delete[] buffer;
    }
    myString& operator=(const myString &s)
    {
        if(this != &s)
        {
            delete[] buffer;
            copy(s);
        }
        return *this;
    }
    myString& operator=(const char &c)
    {
        delete[] buffer;
        buffer = new char[2];
        buffer[0] = c;
        buffer[1] = '\0';
        return *this;
    }
    myString& operator=(const char *cstr)
    {
        if(cstr == nullptr)
        {
            delete[] buffer;
            buffer = new char[1];
            buffer[0] = '\0';
            return *this;
        }
        delete[] buffer;
        copy(cstr);
        return *this;
    }
    int getLength()const
    {
        return (int)strlen(buffer);
    }
    char& operator[](const int &index) const
    {
        return buffer[index];
    }
    void append(const char &c)
    {
        int len = getLength();
        char* temp = new char[len+2];
        strcpy(temp, buffer);
        temp[len] = c;
        temp[len+1] = '\0';
        delete[] buffer;
        buffer = temp;
        //delete[] temp;
    }
    void append(const myString &s)
    {
        int len1 = getLength();
        int len2 = s.getLength();
        char* temp = new char[len1 + len2 + 1];
        strcpy(temp, buffer);
        strcat(temp, s.buffer);
        delete[] buffer;
        buffer = temp;
        //delete[] temp;
    }
    void append(const char *cstr)
    {
        int len1 = getLength();
        int len2 = (int)strlen(cstr);
        char* temp = new char[len1 + len2 + 1];
        strcpy(temp, buffer);
        strcat(temp, cstr);
        delete[] buffer;
        delete[] cstr;
        buffer = temp;
        //delete[] temp;
    }
    int findCharIndex(const char &c ,const int &startIndex) const//查找
    {
        for(int i = startIndex; i < getLength(); i++)
        {
            if(buffer[i] == c)
            {
                return i;
            }
        }
        return -1;
    }
    int countChar(const char &c) const//字符出现次数
    {
        int cnt = 0;
        for(int i = 0; i < getLength(); i++)
        {
            if(buffer[i] == c)
            {
                cnt++;
            }
        }
        return cnt;
    }
    myString getSubString(const int &startIndex, const int &len)const//子串
    {
        int endIndex = startIndex + len;
        if(endIndex > getLength())
        {
            endIndex = getLength();
        }
        char* temp = new char[endIndex - startIndex + 1];
        strncpy(temp, buffer + startIndex, endIndex - startIndex);
        temp[endIndex - startIndex] = '\0';
        myString result(temp);
        //delete[] temp;
        return result;
    }
    void reverse()//字符串倒置
    {
        int len = getLength();
        for(int i = 0; i < len/2; i++)
        {
            char temp = buffer[i];
            buffer[i] = buffer[len-i-1];
            buffer[len-i-1] = temp;
        }
    }
    void removeChar(const char &c)//删除
    {
        int j = 0;
        for(int i = 0; buffer[i] != '\0'; i++)
        {
            if(buffer[i] != c)
            {
                buffer[j++] = buffer[i];
            }
        }
        buffer[j] = '\0';
    }
    void replaceChar(const char &c1, const char &c2)//替换
    {
        for(int i = 0; buffer[i] != '\0'; i++)
        {
            if(buffer[i] == c1)
            {
                buffer[i] = c2;
            }
        }
    }
    myString& operator+=(const char &c)
    {
        append(c);
        return *this;
    }
     myString& operator+=( const myString &s)
    {
         append(s);
         return *this;
     }
    myString& operator+=( const char *cstr)
    {
        append(cstr);
        return *this;
    }
    char* getBuffer()const
    {
        return buffer;
    }
    
    
};

myString operator+(const myString &s1,const myString &s2)
{
    myString res = s1;
    res += s2;
    return res;
}
bool operator>(const myString &s1,const myString &s2)
{
    return strcmp(s1.getBuffer(), s2.getBuffer()) > 0;
}
bool operator>=(const myString &s1,const myString &s2)
{
    return strcmp(s1.getBuffer(), s2.getBuffer()) >= 0;
}
bool operator<(const myString &s1,const myString &s2)
{
    return strcmp(s1.getBuffer(), s2.getBuffer()) < 0;
}
bool operator<=(const myString &s1,const myString &s2)
{
    return strcmp(s1.getBuffer(), s2.getBuffer()) <= 0;
}
bool operator==(const myString &s1,const myString &s2)
{
    return strcmp(s1.getBuffer(), s2.getBuffer()) == 0;
}
bool operator!=(const myString &s1,const myString &s2)
{
return strcmp(s1.getBuffer(), s2.getBuffer()) != 0;
}
ostream& operator<<(ostream& out, const myString &s)
{
    out << s.getBuffer();
    return out;
}
istream& operator>>(istream& in,  myString &s)
{
    char temp[1010];
    in >> temp;
    s = temp;
    return in;
}
int main()
{
    myString s1,s2;
    cin >> s1 >> s2;
    
    
    if(s1 > s2)
        cout << "s1=" << "\"" << s1 << "\"" << ">s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << ">s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    if(s1 >= s2)
        cout << "s1=" << "\"" << s1 << "\"" << ">=s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << ">=s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    if(s1 < s2)
        cout << "s1=" << "\"" << s1 << "\"" << "<s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << "<s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    if(s1 <= s2)
        cout << "s1=" << "\"" << s1 << "\"" << "<=s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << "<=s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    if(s1 == s2)
        cout << "s1=" << "\"" << s1 << "\"" << "==s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << "==s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    if(s1 != s2)
        cout << "s1=" << "\"" << s1 << "\"" << "!=s2=" << "\"" << s2 << "\"" << " is " << "true.\n";
    else
        cout << "s1=" << "\"" << s1 << "\"" << "!=s2=" << "\"" << s2 << "\"" << " is " << "false.\n";

    cout << "Appending s2=\"" << s2 << "\"" << " to s1=\"" << s1 << "\"" << " gives s1=\"";
    s1.append(s2);
    cout << s1 << "\".\n";

    char c; cin >> c;
    cout << "Appending ch='" << c << "'" << " to s1=\"" << s1 << "\"" << " gives s1=\"";
    s1.append(c);
    cout << s1 << "\".\n";
    cout << "ch='" << c << "'" << " is found in s1=\"" << s1 << "\" "<< s1.countChar(c) << " times.\n";
    
    int n; cin >> n;
    cout << "ch='" << c << "' is found in s1=\"" << s1 << "\" at index " << s1.findCharIndex(c, n) << " from index " << n << ".\n";
    
    char ch; cin >> ch;
    cout << "Replacing ch='" << c << "' from s1=\"" << s1 <<"\" with '" << ch << "' gives s1=\"";
    s1.replaceChar(c, ch);
    cout << s1 << "\".\n";
    
    cout << "Removing ch='" << ch << "' from s1=\"" << s1 <<"\"" << " gives s1=\"";
    s1.removeChar(ch);
    cout << s1 << "\".\n";
    
    cout << "Reversing s1=\"" << s1 <<"\" gives s1=\"";
    s1.reverse();
    cout << s1 << "\".\n";
    
    int a,b;
    cin >> a >> b;
    cout << "A substring of s1=\"" << s1 << "\" starting from index " << a << " with " << b << " characters is ";
    myString tmp;
    tmp = s1.getSubString(a, b);
    cout << "\"" << tmp << "\", and appending it to s2=\"" << s2 << "\" gives s2=\"";
    s2.append(tmp);
    cout << s2 << "\".\n";
    return 0;
}
