#include "chose_league.h"
#include <time.h>
#include <stdlib.h>

ChoseLeague::ChoseLeague(string name, int blood){
    m_strName = name;
	m_blood = blood;
    cout<<name<<"正在选择他要使用的英雄"<<endl;
    init();
}

void ChoseLeague::init(){
    int number_in_init = 0;
    int source = 600;
    cout << "选择最多三个你要使用的英雄"<<endl
            <<"1 符文法师(170): 守护瓦罗兰大陆的古老法师,魔法之力,源源不绝,生命之力,经久不息"<<endl
            <<"“当你忙着拯救世界时,每个人却都想和你聊上半天”"<<endl
            <<"2 暮光星灵(250): 传言在一个世界生成和毁灭之时,他将会降临那个世界,什么目的?没有目的,只不过是好玩罢了"<<endl
            <<"“世界总是上上下下左右摇摆进进出出,但从来没有严丝合缝过...啊别在意,我在开玩笑,真的!”"<<endl
            <<"3 铸星龙王(200): 他的神力被一个古老的咒语限制,当群星降临之时,他将再度重现,铸星的神迹!"<<endl
            <<"“自然如此”"<<endl
            <<"4 星界游神(150): 他游荡在平行宇宙之间,为了防止一个个世界不意外崩塌而永远的游荡着"<<endl
            <<"“... ...”"<<endl
            <<"5 诡术妖姬(300): 魔杖轻抬魔印起,镜花水月计重施"<<endl
            <<"“黑玫瑰,将再次绽放”"<<endl
            <<"0 小兵(50): 德玛西亚万岁"<<endl
            <<"“冲啊!!!!!”"<<endl;
    for(int i=0; i<3; i++){
        cout<<"剩余的施法资源: "<<source<<endl;
        cin >> number_in_init;
        switch(number_in_init){
            case 1:{
                source -= 170;
                if(source <= 0){
                    cout<<"施法资源不足,请重新选择"<<endl;
                    source += 170;
                    i--;
                }
                break;
            }
            case 2:{
                source -= 250;
                if(source <= 0){
                    cout<<"施法资源不足,请重新选择"<<endl;
                    source += 250;
                    i--;
                }
                break;
            }
            case 3:{
                source -= 200;
                if(source <= 0){
                    cout<<"施法资源不足,请重新选择"<<endl;
                    source += 200;
                    i--;
                }
                break;
            }
            case 4:{
                source -= 150;
                if(source <= 0){
                    cout<<"施法资源不足,请重新选择"<<endl;
                    source += 150;
                    i--;
                }
                break;
            }
            case 5:{
                source -= 300;
                if(source <= 0){
                    cout<<"施法资源不足,请重新选择"<<endl;
                    source += 300;
                    i--;
                }
                break;
            }
        }
        
        m_setLeague[i] = new SetLeague(number_in_init);
        
    }
}

SetLeague * ChoseLeague::setLeague(){
    srand((unsigned int)time(NULL));
    int i = rand()%3;
    return m_setLeague[i];
}

void ChoseLeague::beAttacked(ChoseLeague &other){
    SetLeague *setLeague = other.setLeague();
    int iDropBlood = 0;
    if(m_blood < setLeague->getAttack()){
        iDropBlood = m_blood;
    }
    else{
        iDropBlood = setLeague->getAttack();
    }
    m_blood= m_blood-iDropBlood;
    cout << m_strName << "被" <<other.m_strName<<"的"<<setLeague->getName()<<"命中"<<endl<<"—"<<iDropBlood<<endl<<"HP: "<<m_blood<<endl<<endl;

}
bool ChoseLeague::isLose()
{
    bool bLose = false;
    if(0 == m_blood){
        bLose = true;
    }
    return bLose;
}

void ChoseLeague::win(){
    cout<<m_strName<<"[ You Have Slain An Enemy ]"<<endl; 
}
void ChoseLeague::lose(){
    cout<<m_strName<<"[ You Have Been Slain ]"<<endl; 
}