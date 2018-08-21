#ifndef FILE_SERVICE_H
#define FILE_SERVICE_H
#include "../Include/PublicHeader.h"
#include "../Include/CompanyMembers.h"
#include <fstream>
#include <time.h>
class FileService{
    public:
    FileService();
    bool readUserInfoToVector(vector <CompanyMembers> &companyMembersVector);
    bool writeVectorToUserInfo(vector <CompanyMembers> &companyMembersVector);
    bool readKeyToVector(vector <string> &vector_key);
    bool writeVectorToKey(vector <string> &vector_key);
    
    //bool readUserNameFileToVector(string &userName,vector <AutoVector> userVector);
    bool writeVectorToUserNameFile();
    //定义一个模板向量引用,根据传入的向量的类型确定引用的类型
    bool LOGme(string &nowTime, string &thisTypeOfUser, userReal &user_real);
    bool hasBeenLoginAtPastTime(string &thisTypeOfUser, string &number,string &username);
    bool read_PTT_PTS_LJM_SLM_ToVector(vector <userReal> &userRealVector, string &fileName);
    ~FileService();


    private:
    fstream ResourcesHaveTheFile;
    string LogFile;
    string MonthlyReport;
    string tomorrowLogFile;
    string userInfoFile;
    string keyFile;
    //四类用户文件,文件类每一条记录对应的是:日期,用户名,key,是否签到(销售额),日工资,
    string PJM_File;
    string PTT_File;
    string PTS_File;
    string SLM_File;

    ProjectManager *_projectManager;
    SalesManager *_salesManager;
    PartTimeSales *_partTimeSales;
    PartTimeTechnicians *_partTimeTechnicians;

};
#endif