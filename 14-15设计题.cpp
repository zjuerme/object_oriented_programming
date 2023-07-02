#include <iostream>
#include <string>
// Please implement your string class with functions listed below 
// like the string class in <string> and write a main function to test them.

/* you may need use following built-in functions

char * strcpy ( char * destination, const char * source );
size_t strlen ( const char * str );
int strcmp ( const char * str1, const char * str2 );

*/

class MyString{
    friend ostream& operator<< (ostream&, MyString&);
    friend istream& operator>> (istream&, MyString&);
    public:
        MyString(const char* str = NULL);
        MyString(const MyString &other);
        MyString& operator=(const MyString& other);
        bool operator==(const MyString&);
        char& operator[](unsigned int);
        size_t size();
        ~MyString();
    private:
	    char *m_data;
};

int main ();

// example here //
class MyString{
	friend ostream& operator<< (ostream&, MyString&);
	friend istream& operator>> (istream&, MyString&);
public:
	MyString(const char* str = NULL);
	MyString(const MyString &other);
	MyString& operator=(const MyString& other);
	bool operator==(const MyString&);
	char& operator[](unsigned int);
	~MyString(); (8)
private:
	char *m_data;
};

MyString::MyString(const char* str) {
	if (!str)
		m_data = NULL;
	else {
		int slen = strlen(str);
		m_data = new char[slen + 1];
		strcpy_s(m_data, slen+1, str);
    }
}

MyString::MyString(const MyString &other){
	if (!other.m_data)
		m_data = NULL;
	else{
		int slen = strlen(other.m_data);
		m_data = new char[slen + 1];
		strcpy_s(m_data, slen+1, other.m_data);
	}
}

MyString::~MyString(){
	delete[] m_data;
}

MyString& MyString::operator=(const MyString& other)  {
	if (this  != &other){
		delete[] m_data;
		if (!other.m_data)   
            m_data = 0;
		else{
			int slen = strlen(other.m_data);
			m_data = new char[slen + 1];
			strcpy(m_data, slen+1, other.m_data);
		}
	}
	return *this;
}

bool MyString::operator==(const MyString &s){
	if (strlen(s.m_data) != strlen(m_data))  
		return false;  
	return strcmp(m_data, s.m_data) ? false : true;
}

char& MyString::operator[](unsigned int e) {
	if (e >= 0 && e <= strlen(m_data))
		return m_data[e];
}

ostream& operator<<(ostream& os, MyString& str){
	os << str.m_data;
	return os;
}

istream &operator>>(istream &is, MyString &s){
	char temp[255];
	is >> setw(255) >> temp;
	s = temp;
	return is;
}

int main() {
	MyString str1 = "Aha!";
	MyString str2 = "My friend";
	MyString str3;
	if (!(str1 == str2)){
		str3 = str1 + str2;
	}
	cout << str3 << "\n" << str3.size() << endl;
	return 0;
}

template <class T, int bounds>
T& FixedVector<T, bounds>::operator[] (int i){
	return elements[i]; //no error checking
}


class A {
	A() {}  
  	A(const A& a) {} // 拷贝构造函数（用引用来记忆），一般为class (const class& copy_var)
	A& operator=(const A& a) {
      	return *this;
	}
};

Array& operator=(const Array& that) {
        if (this != &that) {
            size = that.size;
            delete [] data; // 一定要释放原来的空间！
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = that.data[i];
            }
        }
        return *this;
    }
// *构造函数*不可能定义*为虚函数*（友函数，静态成员函数，内联函数也不能为虚函数）
//默认参数由静态类型决定

counter& counter::operator++(){
	if( 3 == value)
        value = 0;
	else
		value += 1;
    return *this;
}
int counter::operator++(int){
	int t = value;
    if ( 3 == value)
        value = 0;
	else
		value += 1;
    return t;  //注意返回的是加之前的值
}

friend ostream& operator<< (ostream&, MyString&);
friend istream& operator>> (istream&, MyString&);

ostream& operator<<(ostream& os, MyString& str){
	os << str.m_data;
	return os;
}

istream &operator>>(istream &is, MyString &s){
	char temp[255];
	is >> setw(255) >> temp;
	s = temp;
	return is;
}

// this是一个指针，静态成员中不允许用

emplate<class T> bool compare(T x, T y){
    return x>y;
}


#include <iostream>
using namespace std;
enum ERROR{underFlow , overFlow};

template<typename T>
class stackTemplate {
    enum { ssize = 100 };
    T stack[ ssize];
    int top;
public:
    StackTemplate(): top(0){}
    void push(const T& i) {
        if (top >= ssize)
            trow OverFlow
        stack [top++] = i;
    T pop(){
        if (top <= 0)
            throw UnderFlow;
        return stack[--top];
    }
    int size() const{ return top; }
};
int fibonacci(int n);
int main(){
    try{
        stackTemplate<int> is;
        for(int i = e; i < 20; i++)
            is.push(fibonacci(i));
        for(int k = e; k < 20; k++)
            cout << is.pop() << "\t";
    }
    catch(ERROR e ){
        switch(e){
            case overFlow :
                exit;
            case UnderFlow :
                exit;
        }
    }
    catch(...){
        exit;
    }
    return 0;
}
int fibonacci(int n){
    const int sz = 188;
    int i;
    static int f[sz];
    if (n >= sz) 
        throw OverF1ow;
    f[0]= f[1] = 1;
    for(i = 0; i < sz; i++)
        if(f[i] == 0) 
        break;
    while(i <= n) {
        f[i] = f[i-1]+f[1-2];
        i++;
    }
    return f[n];
}