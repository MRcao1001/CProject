#ifndef COMPANY_MEMBERS_H
#define COMPANY_MEMBERS_H
#include "../Include/PublicHeader.h"
class CompanyMembers{
    public:
        CompanyMembers();

        friend class FileService;
        string number;
        string name;
        string password;
        string key;
        string wages;
        
        void setKeyAndWorkType(string &getKey,string &getworkType);
        void setWages(int &getWages);
        void setPhone(string &getPhone);
};
class PartTimeSales:virtual public CompanyMembers{
    public:
        PartTimeSales();
        string SalesVolume_pts = "0";
        string Message_pts= "noMsg";
        void setSalesVolume(int &salesVolume);
};
class PartTimeTechnicians:virtual public CompanyMembers{
    public:
        PartTimeTechnicians();
        string Log = "unlog";
        string Message_ptt = "noMsg";
        void setWorkTime(string &getWorkTime);
};
class ProjectManager:virtual public CompanyMembers{
    public:
       ProjectManager();
       string keyStartWords = "noKey";
       string NumberOfEmployees_pjm = "0";
       void setNumberOfEmployees(int &getNumberOfEmployees);
       void setKeyStartWords();
};
class SalesManager:virtual public CompanyMembers{
    public:
       SalesManager();
       string NumberOfEmployees_slm = "0";
       string SalesVolume_slm = "0";
       void setNumberOfEmployees(int &getNumberOfEmployees);
       void setSalesVolume();
};
class userReal:public PartTimeSales, public PartTimeTechnicians, public ProjectManager, public SalesManager{
    public:
    userReal();
    ~userReal();
};
#endif