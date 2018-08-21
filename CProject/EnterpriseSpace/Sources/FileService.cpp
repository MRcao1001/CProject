#include "../Include/FileService.h"

FileService::FileService(){
    /*获取本地时间来生成一个每日签到文件名*/
    time_t timer = time(NULL);
    struct tm *tblock;
    tblock = localtime(&timer);
    LogFile  = "../Resources/Logfile/" + std::to_string(tblock->tm_year+1900)+std::to_string(tblock->tm_mon+1)+std::to_string(tblock->tm_mday);
    //NOTE: 可以不用创建明天的文件,暂时省去
    //tomorrowLogFile  = "../Resources/" + std::to_string(tblock->tm_year+1900)+std::to_string(tblock->tm_mon+1)+std::to_string(tblock->tm_mday+1);
    MonthlyReport = "../Resources/MonthlyReport";
    userInfoFile = "../Resources/userInfo";
    // string userslefFile = "../Resources/" + fileName;
    keyFile = "../Resources/keys";
    /*尝试打开每个需要使用的文件保证他是存在的,如果不存在就创建他*/
    PJM_File = "../Resources/PJM";
    PTT_File = "../Resources/PTT";
    PTS_File = "../Resources/PTS";
    SLM_File = "../Resources/SLM";
    try{
        //打开月度报表文件
        ResourcesHaveTheFile.open(MonthlyReport);
        if(ResourcesHaveTheFile.good()){
            cout << "open reportFilePointer success" << endl;
        }
        else{
            cout << "MonthlyReport is missed recreating ....";
            ResourcesHaveTheFile.open(MonthlyReport,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat MonthlyReport success !" << endl;
            }
            else{
                cout << "creat MonthlyReport filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();

        //打开今日签到文件
        ResourcesHaveTheFile.open(LogFile);
        if(ResourcesHaveTheFile.good()){
            cout << "open logFilePointer success" << endl;
        }
        else{
            cout << "LogFile is missed recreating ....";
            ResourcesHaveTheFile.open(LogFile,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat LogFile success !" << endl;
            }
            else{
                cout << "creat LogFile filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();

        //生成明日签到文件
        // ResourcesHaveTheFile.open(tomorrowLogFile);
        // if(ResourcesHaveTheFile.good()){
        //     cout << "open tomorrowLogPointer success" << endl;
        // }
        // else{
        //     cout << "tomorrowLogFile is missed recreating ....";
        //     ResourcesHaveTheFile.open(tomorrowLogFile,ios::out);
        //     if(ResourcesHaveTheFile.good()){
        //         cout << "creat tomorrowLogFile success !" << endl;
        //     }
        //     else{
        //         cout << "creat tomorrowLogFile filed !" << endl;
        //         throw;
        //     }
        // }
        // ResourcesHaveTheFile.close();
        // ResourcesHaveTheFile.clear();

        //打开登陆注册用户信息文件
        ResourcesHaveTheFile.open(userInfoFile);
        if(ResourcesHaveTheFile.good()){
            cout << "open userInfoFilePointer success" << endl;
        }
        else{
            cout << "userInfoFile is missed recreating ....";
            ResourcesHaveTheFile.open(userInfoFile,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat userInfoFile success !" << endl;
            }
            else{
                cout << "creat userInfoFile filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();

        //打开秘钥文件,如果没有就创建他
        ResourcesHaveTheFile.open(keyFile);
        if(ResourcesHaveTheFile.good()){
            cout << "open keyFile success" << endl;
        }
        else{
            cout << "keyFile is missed recreating ....";
            ResourcesHaveTheFile.open(keyFile,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat keyFile success !" << endl;
            }
            else{
                cout << "creat keyFile filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();

        //尝试打开四类用户文件
        //打开PJM
        ResourcesHaveTheFile.open(PJM_File);
        if(ResourcesHaveTheFile.good()){
            cout << "open PJM_File success" << endl;
        }
        else{
            cout << "PJM_File is missed recreating ....";
            ResourcesHaveTheFile.open(PJM_File,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat PJM_File success !" << endl;
            }
            else{
                cout << "creat PJM_File filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();

        //打开SLM
        ResourcesHaveTheFile.open(SLM_File);
        if(ResourcesHaveTheFile.good()){
            cout << "open SLM_File success" << endl;
        }
        else{
            cout << "SLM_File is missed recreating ....";
            ResourcesHaveTheFile.open(SLM_File,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat SLM_File success !" << endl;
            }
            else{
                cout << "creat SLM_File filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();
        //打开PTT文件
        ResourcesHaveTheFile.open(PTT_File);
        if(ResourcesHaveTheFile.good()){
            cout << "open PTT_File success" << endl;
        }
        else{
            cout << "PTT_File is missed recreating ....";
            ResourcesHaveTheFile.open(PTT_File,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat PTT_File success !" << endl;
            }
            else{
                cout << "creat PTT_File filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();
        //打开PTS文件
        ResourcesHaveTheFile.open(PTS_File);
        if(ResourcesHaveTheFile.good()){
            cout << "open PTS_File success" << endl;
        }
        else{
            cout << "PTS_File is missed recreating ....";
            ResourcesHaveTheFile.open(PTS_File,ios::out);
            if(ResourcesHaveTheFile.good()){
                cout << "creat PTS_File success !" << endl;
            }
            else{
                cout << "creat PTS_File filed !" << endl;
                throw;
            }
        }
        ResourcesHaveTheFile.close();
        ResourcesHaveTheFile.clear();
    }
    catch(exception e){
        cout <<"FileService_112"<< e.what() <<endl;
    }
}

//QUESTION: 如何定义含有 vector <CompanyMembers> &companyMembersVector 的引用 或者  vector <CompanyMembers> 的返回值类型
bool FileService::readUserInfoToVector(vector <CompanyMembers> &companyMembersVector){
    
    ifstream userinfo(userInfoFile,ios::in);
    //vector <CompanyMembers> companyMembersVector;
    while(! userinfo.eof()){
        CompanyMembers *companyMembers = new CompanyMembers();
        char info[1024];
        userinfo.getline(info,100);
        int key = 1;
        companyMembers->number = "";
        companyMembers->name = "";
        companyMembers->password = "";
        companyMembers->key = "";
        for(int j = 0 ; j < 1024 ; j++){
            if(info[j] == '_'){
                j++;
                key ++;
            }
            if(info[j] == '\0'){
                break;
            }
            if(key == 1){
                companyMembers->number+=info[j];
                //cout<<companyMembers->name;
            }
            if(key == 2){
                companyMembers->name+= info[j];
                //cout<<companyMembers->password;
            }
            if(key == 3){
                companyMembers->password+= info[j];
                //cout<<companyMembers->key;
            }
            if(key == 4){
                companyMembers->key+= info[j];
            }
        }
        companyMembersVector.push_back( *companyMembers );
    }
    return true;
}

bool FileService::writeVectorToUserInfo(vector <CompanyMembers> &companyMembersVector){
    ofstream userInfo;
    try{
        userInfo.open(userInfoFile);
        if(! userInfo.good()){
            throw;
        }
    }
    catch(exception e){
        cout << "open userInfo :" <<e.what()<<endl;
    }
    for(int i = 0 ; i < companyMembersVector.size(); i ++){
        if(companyMembersVector[i].number==""||companyMembersVector[i].name==""||companyMembersVector[i].password==""||companyMembersVector[i].key==""){
            continue;
        }
        userInfo    << companyMembersVector[i].number << "_" 
                    << companyMembersVector[i].name << "_" 
                    << companyMembersVector[i].password <<"_" 
                    << companyMembersVector[i].key << endl;
    }
}

bool FileService::readKeyToVector(vector <string> &vector_key){
    ifstream Keys;
    try{
        Keys.open(keyFile);
        if(! Keys.good()){
            throw;
        }
    }
    catch(exception e){
        cout << "open keys :" <<e.what()<<endl;
    }
    //vector <CompanyMembers> companyMembersVector;
    string info_str = "";
    while(! Keys.eof()){
        char info[1024];
        Keys.getline(info,100);
        info_str = info;
        vector_key.push_back( info_str );
        info_str ="";
    }
    return true;
}

bool FileService::writeVectorToKey(vector <string> &vector_key){
    ofstream Key;
    try{
        Key.open(keyFile);
        if(! Key.good()){
            throw;
        }
    }
    catch(exception e){
        cout << "open Key :" <<e.what()<<endl;
    }
    for(int i = 0 ; i < vector_key.size(); i ++){
        Key<< vector_key[i]<< endl;
    }
}

//登陆之后将登陆用户信息追缴写入对应文件和日志文件
bool FileService::LOGme(string &nowTime, string &thisTypeOfUser, userReal &user_real){
    ofstream insertIntoFile;
    string FileName = "../Resources/"+thisTypeOfUser;
    try{
        insertIntoFile.open(FileName,ios::app);
        if(! insertIntoFile.good()){
            cout<< FileName <<"打开失败!"<<endl;
            throw;
        }
    }
    catch(exception e){
        cout << "open "<<FileName<<e.what()<<endl;
    }
    cout<< FileName <<"打开成功!"<<endl;
    //判断用户今日是否将数据写入到文件中过  
    if(hasBeenLoginAtPastTime(thisTypeOfUser, nowTime, user_real.name) == false){
        cout << user_real.name << "今天"<<nowTime<<"登陆过,所以不重复写入文件" << endl;
        return false;
    }
    //未写过则追加一行写入
    if(thisTypeOfUser == "PJM"){
        cout<< thisTypeOfUser <<"即将写入的信息是:"<<endl
                        << user_real.number << "_" 
                        << user_real.name << "_" 
                        << user_real.password <<"_" 
                        << user_real.key <<"_" 
                        << user_real.wages <<"_" 
                        << user_real.NumberOfEmployees_pjm <<"_" 
                        << user_real.keyStartWords << endl;
            insertIntoFile<< user_real.number << "_" 
                        << user_real.name << "_" 
                        << user_real.password <<"_" 
                        << user_real.key <<"_" 
                        << user_real.wages <<"_" 
                        << user_real.NumberOfEmployees_pjm <<"_" 
                        << user_real.keyStartWords << endl;
    }
    if(thisTypeOfUser == "SLM"){
        cout<< thisTypeOfUser <<"即将写入..."<<endl;
            insertIntoFile<< user_real.number << "_" 
                        << user_real.name << "_" 
                        << user_real.password <<"_" 
                        << user_real.key <<"_" 
                        << user_real.wages <<"_" 
                        << user_real.SalesVolume_slm <<"_" 
                        << user_real.NumberOfEmployees_slm << endl;
        
    }
    if(thisTypeOfUser == "PTT"){
        cout<< thisTypeOfUser <<"即将写入..."<<endl;
            insertIntoFile<< user_real.number << "_" 
                        << user_real.name << "_" 
                        << user_real.password <<"_" 
                        << user_real.key <<"_" 
                        << user_real.wages <<"_" 
                        << user_real.Log <<"_" 
                        << user_real.Message_ptt << endl;
    }
    if(thisTypeOfUser == "PTS"){
        cout<< thisTypeOfUser <<"即将写入..."<<endl;
            insertIntoFile<< user_real.number << "_" 
                        << user_real.name << "_" 
                        << user_real.password <<"_" 
                        << user_real.key <<"_" 
                        << user_real.wages <<"_" 
                        << user_real.SalesVolume_pts <<"_"  
                        << user_real.Message_pts << endl;
    }
    cout << user_real.name << "与"<<nowTime<<"将信息写入到文件" << endl;
}
//判断当天是否登陆过一次的函数,根据thisTypeOfUser遍历不同文件写入vector在循环遍历是否存在一条信息username和number和将要写入的都相同的,如果有不写入,如果没有就写入
bool FileService::hasBeenLoginAtPastTime(string &thisTypeOfUser, string &number,string &username){
    string FileName = "../Resources/"+thisTypeOfUser;
    ifstream searchFromFile(FileName);
    vector <userReal> userVector_parttime;
    //vector <CompanyMembers> companyMembersVector;
    cout << "检测用户是否写入过"<<endl;
    while(! searchFromFile.eof()){
        userReal *userReal_parttime = new userReal();
        char info[1024];
        searchFromFile.getline(info,100);
        int key = 1;
        userReal_parttime->number = "";
        userReal_parttime->name = "";
        userReal_parttime->password = "";
        userReal_parttime->key = "";
        for(int j = 0 ; j < 1024 ; j++){
            if(info[j] == '_'){
                j++;
                key ++;
            }
            if(info[j] == '\0'){
                break;
            }
            if(key == 1){
                userReal_parttime->number+=info[j];
                //cout<<companyMembers->name;
            }
            if(key == 2){
                userReal_parttime->name+= info[j];
                //cout<<companyMembers->password;
            }
        }
        userVector_parttime.push_back( *userReal_parttime );
    }
    for(int i = 0; i <userVector_parttime.size(); i++){
        if(userVector_parttime[i].number == number && userVector_parttime[i].name == username){
            return false;
        }
    }
    return true;
}


//遍历PTT PTS SLM PJM文件并返回对应的向量
bool FileService::read_PTT_PTS_LJM_SLM_ToVector(vector <userReal> &userRealVectorc, string &fileName){
    string FileName = "../Resources/"+fileName;
    ifstream userinfo(FileName,ios::in);
    //vector <CompanyMembers> companyMembersVector;
    userReal *user_real = new userReal();
    while(! userinfo.eof()){
        char info[1024];
        userinfo.getline(info,100);
        int key = 1;
        user_real->number = "";
        user_real->name = "";
        user_real->password = "";
        user_real->key  = "";
        user_real->wages = "";
        user_real->Log = "";
        user_real->Message_ptt = "";
        user_real->Message_pts = "";
        user_real->NumberOfEmployees_pjm = "0";
        user_real->NumberOfEmployees_slm = "0";
        user_real->SalesVolume_pts = "0";
        user_real->SalesVolume_slm = "0";
        user_real->keyStartWords = "";
        for(int j = 0 ; j < 1024 ; j++){
            if(info[j] == '_'){
                j++;
                key ++;
            }
            if(info[j] == '\0'){
                break;
            }
            if(key == 1){
                user_real->number+=info[j];
                //cout<<companyMembers->name;
            }
            if(key == 2){
                user_real->name+= info[j];
                //cout<<companyMembers->password;
            }
            if(key == 3){
                user_real->password+= info[j];
                //cout<<companyMembers->key;
            }
            if(key == 4){
                user_real->key+= info[j];
            }
            if(key == 5){
                user_real->wages+= info[j];
                
                //cout<<companyMembers->key;
            }
            if(key == 6){
                if(fileName == "PTT"){
                    user_real->Log+= info[j];
                }
                if(fileName == "PTS"){
                    user_real->SalesVolume_pts+= info[j];
                }
                if(fileName == "PJM"){
                    user_real->NumberOfEmployees_pjm+=info[j];
                }
                if(fileName == "SLM"){
                    user_real->NumberOfEmployees_slm+=info[j];
                }
            }
            if(key == 7){
                if(fileName == "PTT"){
                    user_real->Message_ptt+= info[j];
                }
                if(fileName == "PTS"){
                    user_real->Message_pts+= info[j];
                }
                if(fileName == "PJM"){
                    user_real->keyStartWords+=info[j];
                }
                if(fileName == "SLM"){
                    user_real->NumberOfEmployees_slm+=info[j];
                }
            }
        }
        userRealVectorc.push_back( *user_real );
    }
    return true;
}

FileService::~FileService(){

}