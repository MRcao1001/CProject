#include <iostream>

using namespace std;
struct STU{
    string name;
    int age;
    int gread;
};


int my_add (const int a, const int b){
    return a+b;
}
float my_add (const float a, const float b){
    return a+b;
}
double my_add (const double a, const double b){
    return a+b;
}
string my_add (const string a, const string b){
    return a+b;
}


int main(int argc, char const *argv[])
{
    int a = 1 , b = 2;
    cout<< my_add(a,b) ; 
    return 0;
}