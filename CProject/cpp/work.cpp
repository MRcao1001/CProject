/*
 * @Author: MRcao on ubuntu18.04
 * @Date: 2018-08-01 17:05:58
 * @LastEditors: MRcao
 * @LastEditTime: 2018-08-02 14:13:00
 * @Description: 
 */
#include <iostream>

using namespace std;

/*this is the function of part 4*/
int bit_turn_on(unsigned int &ui, int pos)
{
    pos |= (1<<ui);
    return pos;
}
int bit_turn_off(unsigned int &ui, int pos)
{
    pos &= ~(1<<ui);
    return pos;
}
int flip_bit(unsigned int &ui, int pos)
{
    pos ^ (1<<ui);
    return pos;
}
bool bit_off(unsigned int ui, int pos)
{
    return ui & (1<<pos);
}
main(int argc, char const *argv[])
{
    //part 2
    // float i;
    // int j;
    // int *f;
    // i = j = f = 0;
    
    //part 3
    //unsigned int uni1 = 5, uni2=7;
    //cout << (uni1 & uni2) <<endl<< (uni1 | uni2) <<endl<< (uni1 && uni2)<<endl<<(uni1 || uni2);

    //part 4
        //where
    unsigned int ui;
    cin >> ui;
        //who
    int pos;
    cin >> pos;
    /*tips: int &ui = a; --> ui = a; &ui = &a;*/
    pos = bit_turn_on(ui, pos);
    pos = bit_turn_off(ui, pos);
    pos = flip_bit(ui,pos);
    bool result = bit_off(ui,pos);

    cout << pos << " " << result << endl;
    return 0;
}
