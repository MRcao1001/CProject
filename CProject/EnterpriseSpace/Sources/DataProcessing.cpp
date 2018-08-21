#include "../Include/DataProcessing.h"

//在程序开始时就生成数据处理类的对象.将文件读取到类的私有成员向量,在执行操作的过程中将经过修改的向量内容写入到文件
DataProcessing::DataProcessing(){
    fileService = new FileService();
    fileService->readUserInfoToVector(companyMembersVector_userInfo);
    // for(int i = 0 ; i <companyMembersVector_userInfo.size(); i++){
    //     cout << companyMembersVector_userInfo[i].number <<" " << companyMembersVector_userInfo[i].name <<" " << companyMembersVector_userInfo[i].password<<" " << companyMembersVector_userInfo[i].key <<endl;
    // }
    fileService->readKeyToVector(vector_key);
    // for(int i = 0 ; i <vector_key.size(); i++){
    //     cout << vector_key[i]<<endl;
    // }
}

//FINISH: 传入用户名和密码来登陆
int DataProcessing::LoginProcessing(string &userName, string &passWord, string &nowTime){
    user_real = new userReal;
    userVector.clear();
    for(int i = 0 ; i <companyMembersVector_userInfo.size(); i++){
        cout << companyMembersVector_userInfo[i].name <<" " << companyMembersVector_userInfo[i].password<<" " << companyMembersVector_userInfo[i].key <<endl;
        if(userName == companyMembersVector_userInfo[i].name && passWord == companyMembersVector_userInfo[i].password){
            //fileService->LOGme(userName,nowTime,);
            //登陆时候根据key不同对用户类赋值,并读取对应用户名的文件的信息到对应类型的向量
            if(companyMembersVector_userInfo[i].key.find("PTT") != string::npos){
                user_real = new userReal;
                thisTypeOfUser = "PTT";
                user_real->key = companyMembersVector_userInfo[i].key;
                user_real->name = userName;
                user_real->password = passWord;
                user_real->number = nowTime;
                user_real->wages = "0";
                user_real->Log = "unLog";
                user_real->Message_ptt = "NULL";
                fileService->LOGme(nowTime, thisTypeOfUser,*user_real);
                return 3;
            }
            if(companyMembersVector_userInfo[i].key.find("PTS") != string::npos){
                user_real = new userReal;
                thisTypeOfUser = "PTS";
                user_real->key = companyMembersVector_userInfo[i].key;
                user_real->name = userName;
                user_real->password = passWord;
                user_real->number = nowTime;
                user_real->wages = "0";
                user_real->SalesVolume_pts = "0";
                user_real->Message_ptt = "NULL";
                fileService->LOGme(nowTime, thisTypeOfUser,*user_real);
                return 3;
            }
            if(companyMembersVector_userInfo[i].key.find("PJM") != string::npos){
                user_real = new userReal;
                thisTypeOfUser = "PJM";
                user_real->key = companyMembersVector_userInfo[i].key;
                user_real->name = userName;
                user_real->password = passWord;
                user_real->number = nowTime;
                user_real->wages = "0";
                user_real->keyStartWords = "nokey";
                user_real->NumberOfEmployees_pjm = "0";
                fileService->LOGme(nowTime, thisTypeOfUser,*user_real);
                return 2;
            }
            if(companyMembersVector_userInfo[i].key.find("SLM") != string::npos){
                user_real = new userReal;
                thisTypeOfUser = "SLM";
                user_real->key = companyMembersVector_userInfo[i].key;
                user_real->name = userName;
                user_real->password = passWord;
                user_real->number = nowTime;
                user_real->wages = "0";
                user_real->NumberOfEmployees_slm = "0";
                user_real->SalesVolume_slm = "0";
                fileService->LOGme(nowTime, thisTypeOfUser,*user_real);
                return 2;
            }
        }
    }
    return 0;
}

//FINISH: 传入用户名密码手机号和key来注册
int DataProcessing::RegisterProcessing(string &userName, string &passWord, string &key){
    //判断用户名是否被注册
    for(int i = 0 ; i <companyMembersVector_userInfo.size(); i++){
        cout << companyMembersVector_userInfo[i].name <<" " << companyMembersVector_userInfo[i].password<<" " << companyMembersVector_userInfo[i].key <<endl;
        if(userName == companyMembersVector_userInfo[i].name ){
            return 1;
        }
    }
    cout << "您输入的key: "<< key << endl;
    for(int i = 0 ; i < vector_key.size(); i++){
        cout << "key" << i << ": " << vector_key[i] << endl; 
        if(key == vector_key[i]){
            //FINISH: 找到对应的key ,删除key记录开始注册
            vector_key.erase(vector_key.begin()+i);
            CompanyMembers *createCompanyMenbers = new CompanyMembers;
            createCompanyMenbers->number = to_string(  companyMembersVector_userInfo.size() );
            createCompanyMenbers->name = userName;
            createCompanyMenbers->password = passWord;
            createCompanyMenbers->key = key;
            companyMembersVector_userInfo.push_back( *createCompanyMenbers);
            //FINISH: 将向量数据写入到文件
            fileService->writeVectorToUserInfo(companyMembersVector_userInfo); 
            //FINISH:将key向量写入文件
            fileService->writeVectorToKey(vector_key);
            //创建一个新用户的同名文件
            return 0;
        }
        //没有对应的key,拒绝注册申请
    }
    //重新读取文件
    fileService->readUserInfoToVector(companyMembersVector_userInfo);
    return 2;
}

void DataProcessing::showUserInfo(string &userName){
    //在文件处理函数中遍历搜索对应名字的文件,并返回向量
    vector <userReal> getUserinfoFromFourDataFileVector;
    fileService->read_PTT_PTS_LJM_SLM_ToVector(getUserinfoFromFourDataFileVector,thisTypeOfUser);
    searchUserByUsername(getUserinfoFromFourDataFileVector,userName);
    if(thisTypeOfUser == "PTT"){
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
        cout<< "| 日    期 |  姓  名(a)  | 密  码(b) |         k e y(c)         | 日 薪 | 打 卡 | 任 务 |" << endl;
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
    }
    if(thisTypeOfUser == "PJM"){
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
        cout<< "| 日    期 |  姓  名(a)  | 密  码(b) |         k e y(c)         | 日 薪 | 人 数 | 私 钥 |" << endl;
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
    }
    if(thisTypeOfUser == "PTS"){
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
        cout<< "| 日    期 |  姓  名(a)  | 密  码(b) |         k e y(c)         | 日 薪 | 销 售 | 任 务 |" << endl;
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
    }
    if(thisTypeOfUser == "SLM"){
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
        cout<< "| 日    期 |  姓  名(a)  | 密  码(b) |         k e y(c)         | 日 薪 | 人 数 | 销 售 |" << endl;
        cout<< "+-----------------------------------------------------------------------------------+" << endl;
    }
    for(int i=0; i< getUserinfoFromFourDataFileVector.size(); i++){
        cout<<"| "<<getUserinfoFromFourDataFileVector[i].number
            <<" | "<<getUserinfoFromFourDataFileVector[i].name
            <<" | "<<getUserinfoFromFourDataFileVector[i].password
            <<" | "<<getUserinfoFromFourDataFileVector[i].key
            <<" | "<<getUserinfoFromFourDataFileVector[i].wages;
        if(thisTypeOfUser == "PTT"){
            cout<<" | "<<getUserinfoFromFourDataFileVector[i].Log
            <<" | "<<getUserinfoFromFourDataFileVector[i].Message_ptt
            <<" |"<<endl;
        }
        if(thisTypeOfUser == "PJM"){
            cout<<" | "<<getUserinfoFromFourDataFileVector[i].NumberOfEmployees_pjm
            <<" | "<<getUserinfoFromFourDataFileVector[i].keyStartWords
            <<" |"<<endl;
        }
        if(thisTypeOfUser == "SLM"){
            cout<<" | "<<getUserinfoFromFourDataFileVector[i].NumberOfEmployees_slm
            <<" | "<<getUserinfoFromFourDataFileVector[i].SalesVolume_slm
            <<" |"<<endl;
        }
        if(thisTypeOfUser == "PTS"){
            cout<<" | "<<getUserinfoFromFourDataFileVector[i].SalesVolume_pts
            <<" | "<<getUserinfoFromFourDataFileVector[i].Message_pts
            <<" |"<<endl;
        }
    }
}

void DataProcessing::changeInfo(string &changeChose, string &changeValue){
    cout << user_real->name<<endl;
    cout << changeChose << "--" << changeValue << endl;
    for(int i = 0; i <companyMembersVector_userInfo.size(); i++){
        cout <<companyMembersVector_userInfo[i].name<<endl;
        if (user_real->name == companyMembersVector_userInfo[i].name){
            cout<<"找到了对应用户名"<<endl;
            if(changeChose == "a"){
                companyMembersVector_userInfo[i].name = changeValue;
                cout << "将用户名修改为: "<< companyMembersVector_userInfo[i].name;
                break;
            }
            if(changeChose == "b"){
                companyMembersVector_userInfo[i].password = changeValue;
                cout << "将密码修改为: "<< companyMembersVector_userInfo[i].password;
                break;
            }
            if(changeChose == "c"){
                companyMembersVector_userInfo[i].key = changeValue;
                cout << "将key修改为: "<< companyMembersVector_userInfo[i].key;
                break;
            }
        }
        //break;
    }    
    fileService->writeVectorToUserInfo(companyMembersVector_userInfo);
    //重新读取文件
    fileService->readUserInfoToVector(companyMembersVector_userInfo);
}

DataProcessing::~DataProcessing(){
    delete fileService;
    delete user_real;
}

void searchUserByUsername(vector <userReal> &userRealVector, string &userName){
    for(int i = 0; i < userRealVector.size(); i++){
        if(userRealVector[i].name != userName){
            userRealVector.erase(userRealVector.begin()+i);
            i--;
        }
        
    }
}