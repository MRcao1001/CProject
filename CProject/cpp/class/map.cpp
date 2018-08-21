#include <iostream>
#include <vector>
using namespace std;

class VECTOR{
    public:
    VECTOR();
    int &operator=(vector <int> y);
    private:
    vector <int> X;
    vector <int> Y;
};

int VECTOR::operator=(std::vector <int > y){

}
main(int argc, char const *argv[])
{
    vector <int> X[10];
    vector <int> Y[10];
    return 0;
}
