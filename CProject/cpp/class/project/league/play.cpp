#include "./play.h"
#include "chose_league.h"
#include <unistd.h>

void star(ChoseLeague &CL1, ChoseLeague &CL2){
    bool bSign = false;
    while(true){
        if(bSign){
            CL2.beAttacked(CL1);
            if(CL2.isLose()){
                CL1.win();
                CL2.lose();
                break;
            }
        }
        else{
            CL1.beAttacked(CL2);
            if(CL1.isLose()){
                CL2.win();
                CL1.lose();
                break;
            }
        }
        bSign = !bSign;
        sleep(1);
    }
}

int main(int argc, char const *argv[])
{
    ChoseLeague CL1("召唤师1", 3000);
    ChoseLeague CL2("召唤师2", 3000);
    star(CL1,CL2);   
    return 0;
}
