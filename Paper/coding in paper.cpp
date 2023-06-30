/* 18-19 程序输出题1*/
#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int x): val(x) {}
    void Print() const { cout << 1 << val; }
    void Print() { cout << 2 << val; }
private:
    int val;
};

int main() {
    const MyClass obj1(10);
    MyClass obj2(20);
    obj1.Print();
    obj2.Print();
    return 0;
}

/* 18-19 程序输出题2*/
#include<iostream>
using namespace std;

class AA {
public:
    AA() { cout << 1; }
    ~AA() { cout << 2; }
};
class BB: public AA {
    AA aa;
    public:
    BB() { cout << 3; }
    ~BB() { cout << 4; }
};

int main() {
    BB bb;return 0;
}

/* 18-19 程序输出题3*/
#include <iostream>
using namespace std;
class A {
    public:
    A() { cout << 1; }
}a;
int main(){
    cout << 2;A a;
    return o;
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



/* 18-19 程序输出题5*/
#include <iostream>
using namespace std;

class TEST {
    int num;

public:
    TEST(int num = 0);
    void increment();
    ~TEST();
};

TEST::TEST(int num) : num(num) {
    cout << num << endl;
}

void TEST::increment() {
    num++;
}

TEST::~TEST() {
    cout << num << endl;
}

int main() {
    TEST array[2];
    array[0].increment();
    array[1].increment();
    return 0;
}

class A {
    A( ) {};
    virtual f() {};
    int i;
};
// 对于上述定义的类，为什么下面三句都是对的？
// i is private
// f() is an inline function
// i is a member of class A

#include <iostream>
#include <string.h>
using namespace std;

class Employee
{
public:
    Employee( const char * const, const char * const );
    ~Employee();
    const char   *getFirstName()  const;
    const char *getLastName() const;
    static int getCount();
private:
    char *firstName;
    char *lastName;
    static int count;
};

int Employee::count = 0;
int Employee::getCount()
{
    return count;
}

Employee::Employee( const char * const first, const char * const last )
{
    firstName = new char[strlen( first ) + 1 ];
    strcpy( firstName, first );

    lastName = new char[ strlen( last ) + 1 ];
    strcpy( lastName, last );

    count++;

    cout << "Employee constructor for " << firstName
         << ' ' << lastName << " called." << endl;
}
Employee::~Employee()
{
    cout << "~Employee() called for " << firstName
         << ' ' << lastName << endl;

    delete [] firstName;
    delete [] lastName;

    count--;
}
const char *Employee::getFirstName() const
{
    return firstName;
}
const char *Employee::getLastName() const
{
    return lastName;
}
int main(){
    cout << "Number of employees: "
         << Employee::getCount() << endl;

    Employee *e1Ptr = new Employee( "Susan", "Baker" );
    Employee *e2Ptr = new Employee( "Robert", "Jones" );
    cout << "Number of employees: "
         << e1Ptr->getCount();

    cout << "\n\nEmployee 1: "
         << e1Ptr->getFirstName() << " " << e1Ptr->getLastName()
         << "\nEmployee 2: "
         << e2Ptr->getFirstName() << " " << e2Ptr->getLastName() << "\n\n";

    delete e1Ptr;
    e1Ptr = 0;
    delete e2Ptr;
    e2Ptr = 0;
    cout << "Number of employees: "
         << Employee::getCount() << endl;
    return 0;
}


#include <iostream>
using namespace std;

class A
{
public:
    A(int i) : mi(i) {}
//    A(const A& rhs) : mi(rhs.mi)
//    {
//        cout << "A::A(&)" << endl;
//    }
    A& operator=(const A&rhs)
    {
        mi = rhs.mi;
        cout << "A::operator=()" << endl;
        return *this;
    }
    virtual void f()
    {
        cout << "A::f(), " << mi << endl;
    }
protected:
    int mi;
};

class B : public A
{
public:
    B(int i, int j) : A(i), mj(j) {}
    void f() override
    {
        cout << "B::f(), " << mi << ", " << mj << endl;
    }
private:
    int mj;
};

int main(){
    B b(3,4);


    A a2 = b;
    a2.f();
}

/* 作业题7.5 */
#include <iostream>
#include <stdexcept>

class BufferIndexError : public std::out_of_range{
    private:
        int index;
    public:
    BufferIndexError(int idx) : std::out_of_range(""), index(idx) {}
    int getIndex() const { return index; }
};

template <typename T, int N>
struct Buffer{
    int size() const{return N;}
    bool empty() const{return N == 0;}
    const T& operator[](int i) const{
        if (i >= 0 && i < N)
            return elems[i];
        throw   BufferIndexError(i);
    }
    const T& front() const{
        return elems[0];
    }
    const T& back() const{
        return elems[N - 1];
    }
    T elems[N];
};

template <typename T, int N>
std::ostream &operator<<(std::ostream &out, const Buffer<T, N> &buf){
    for (int i = 0; i < N; ++i)
        out << buf[i];
    return out;
}

int main(){
    Buffer<int, 4> numbers = {1, 3, 1, 4};
    Buffer<int, 0> no_numbers;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';
    Buffer<char, 16> letters = {
        'D','o',' ','n','o','t',' ','a','n','s','w','e','r','!','!','!'
    };
    if (!letters.empty()){
        std::cout << "The first character is: " << letters.front() << '\n';
        std::cout << "The last character is: " << letters.back() << '\n';
    }
    std::cout << letters << '\n';
    try{
        int k = 0;
        while (true)
        std::cout << letters[k++];
    }
    catch (const BufferIndexError& ex) {
        std::cout << "\nBuffer index is out of range: " << ex.getIndex() << std::endl;
    }
}

#include<iostream>
using namespace std;
class Base{
protected:
    int x;
public:
    Base(int b=0): x(b) { }
    virtual void display() const {cout << x << endl; }
};
class Derived : public Base{
    int y;
public:
    Derived(int d=6): y(d) { }
    void display( ) {cout << x << "," << y << endl; }
};
int main(){
    Base b(1);
    Derived d(2);
    Base *p = &d;
    b.display();
    d.display();
    p->display();
}


/*************************** 程序输出题程序  ****************************/
#include <cstring>
#include <iostream>
using namespace std;

class Str{
    char m_s[10];
    char *m_p;
public:
    Str(char *s ){strcpy(m_s,s);m_p = m_s;}
    operator char*(){ return m_p; }
    char *operator++(){return ++m_p; }
    char operator [](int i){ return m_s[i]; }
};

int main(){
    Str s("Hi");
    cout<<*s << endl;
    ++s;
    cout <<s[0]<< endl;
    cout<<*s<< endl;
}



#include <iostream>
using namespace std;
class A{
public:
    A(){cout <<"A()"<< endl;}
    ~A(){cout<<"~A()"<< endl; }
};
class B : public A{
public:
    B(){cout <<"B()" << endl; }
    ~B(){cout<<"~B()"<< endl; }
};
int main(){
    A a;
    B b;
}



#include <iostream>
struct A {
    A() { std::cout <<"A"<< std::endl; }
    A(const A &a) { std::cout <<"B"<< std::endl;}
    A& operator=(const A &a) { std::cout <<"c" << std::endl; return*this; }
};
int main(){
    A a[2];
    A b = a[0];
    A c;
    c = a[1];
}


#include <iostream>
class C{
    public:
        explicit C(int){
            std::cout<<"i"<< std::endl;
        };
        C(double){
            std::cout <<"d"<< std::endl;
    };
};
int main(){
    C c1(7);
    C c2=7;
}

#include <iostream>
template<class T> void f(T &i) { std:: cout<< 1;]
templatec<> void f(const int &i) { std:: cout c< 2;}
int main(){
int i = 24;f(i);}




#include <iostream>
using namespace std;

class A{
public:
    void F(int){cout<<"A: : F(int)" <<endl; }
    void F(double){cout <<"A: : F(double)"<< endl; }
    void F2(int){ cout <<"A::F2(int)" << endl;}
};
class B : public A{
public:
    void F(double){cout <<"B: :F(double)" << endl; }
};
int main(){
    B b;
    b.F(2.0);
    b.F(2);
    b.F2(2);
}



#include <iostream>
struct A{
    virtual void foo(int a = 1) {
        std::cout <<"A"<< '\n'<< a;
    }
};
struct B :A{
    virtual void foo(int a = 2) {
        std::cout <<"B"<< '\n' << a;
    }
};
int main () {
    A *a = new B;
    a->foo();
}



#include <iostream>
using namespace std;
class A{
public:
    static void f(double){
        cout << "f(double)" << endl;
    }
    void f(int){
        cout<< "f(int)" << endl;
    }
};
int main(){
    const A a;
    a.f(3);
}



#include <iostream>
using namespace std;
class A{
public:
    virtual ~A(){}
};
class B: public A0;
int main(){
    A a;
    B b;
    A *ap= &a;
    if (dynamic_cast<B *>(ap))
        cout << "OK1" <<endl;
    else
        cout i<"FAIL"<< endl;
    if(static_cast<B *>(ap))
        cout <<"OK2" << endl;
    else
        cout 〈<"FAIL"<< endl;
    ap = &b;
    if(dynamic_cast<B *>(ap))
        cout <<"OK3" <<endl;
    else
        cout<<"FAIL"<< endl;
    if (static_cast<B *>( ap ))
        cout<<"OK4" <<endl;
    else
    cout<<"FAIL"<<endl;
}



#include <iostream>
using namespace std;
class A {
    int i;
public :
    A() : i(0){}
    ~A() { cout << get(); }
    void set(int i) { this->i = i; }
    int get() { return i; }
};
int main(){
    A *p = new A[2];
    delete p;
}



class MyClass{
public:
	MyClass(int id) { cout << "MyClass::Ctor\n"; }
	~MyClass() { cout << "MyClass::Dtor\n"; }

private:
	int id;
};

class Base{
public:
	Base(int _id):myclass(_id) { cout << "Base::Ctor\n"; }
	~Base() { cout << "Base::Dtor\n"; }
	virtual void foo() { cout << "Base::foo\n"; }
private:
	MyClass myclass;
};

class Derived : public Base{
public:
	Derived(int _id):Base(_id){ cout << "Derived::Ctor\n"; foo(); }
	~Derived(){ cout << "Derived::Dtor\n"; foo(); }
	virtual void foo() { cout << "Derived::foo\n"; }
private:

};

int main(){
	Base* p = new Derived(10);
	delete p;
	return 0;
}

#include <iostream>
using namespace std;
class A {
    static int m;
    int n;
public:
    A(int m, int n) {
        this->m = m;
        this->n = n;
    }

    void print() {
        cout << m << "---" << n << endl;
    };
};
    int A::m;

    int main(){
        A a1(3,4);
        A a2(5,6);
        a1.print();
        a2.print();
    }




#include <iostream>
using namespace std;
class A{
public:
    A(){ cout <<"A()" << endl;}
    A(const A&){ cout<<"A(const A&)" << endl ; }
    A &operator=(const A&){
        cout <<"operator-(constA&)" << endl;
        return *this;
    }
};
int main(){
    A a1,a2;
    a2 =a1;
    A a3 = a2;
}



#include <iostream>
struct Base{
    virtual ~Base(){
        std :: cout << "Destructing Base" << std :: endl;
    }
    virtual void f(){
        std :: cout << "I 'm in Base" << std :: endl;
    }
};
struct Derived : public Base{
    ~Derived(){
        std :: cout<< "Destructing Derived" << std :: endl;
    }
    void f(){
        std :: cout << "I 'm in Derived" << std ::endl;
    }
};
int main(){
    Base *p = new Derived();
    (*p).f();
    p->f();
    delete p;
}
