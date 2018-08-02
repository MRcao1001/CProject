#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string str[5]{"banana", "king always lucky", "orange", "cola", "apple"};
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                string temp;
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }           
        }
    }
    cout<<endl << str[0] << "--" << str[1] << "--" << str[2] << "--" << str[3] << "--" << str[4];
    return 0;
}
