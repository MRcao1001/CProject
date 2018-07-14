#include "./game.h"
//选择系统界面的函数
int choise(int Ui, char key){
    
    
    
    if(key == 'w'){
        if(Ui > 1){
            Ui --;
        }
    }
    else if(key == 's'){
        if(Ui < 4){
            Ui ++;
        }
    }
    else{
        paintPlay();
    }
    switch(Ui){
        case 1:{
            paintPlay();
            break;
        }
        case 2:{
            paintHistory();
            break;
        }
        case 3:{
            paintHelp();
            break;
        }
        case 4:{
            paintExit();
            break;
        }
    }
    return Ui;
}

//进入系统功能界面的函数
int enterUI(int UI){
    switch(UI){
        case 1:{
            getchar(); 
            break;
        }
        case 2:{
            historyUI();
            getchar();
            break;
        }
        case 3:{
            helpUI();
            getchar();
            break;
        }
        case 4:{
            system("clear");
            exit(0);
            break;
        }
    }
    return 0;
}

int main(void){
    
    paintPlay();
    int ui = 1;
    char key;
    while(1){
        key = mygetch() ;
        if(key == '\n'){
            enterUI(ui);
        }
        ui = choise(ui,key);
    }
}
