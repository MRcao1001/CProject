#include "star.h"

int exchange(string num_c){
    int num = 0;
    bool flag;
    for (int i = 0; i < num_c.size(); i++)
    {
        int tmp = (int)num_c[i];
        if (tmp >= 48 && tmp <= 57)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return std::atoi(num_c.c_str());
}
void Shopping()
{
    Warehose Wh(1000, 800, 700, 400);
    CheckOutCounter COC(0, 0);
    while (1)
    {
        system("clear");
        char chose = '0';
        string num_c;
        int num = 0;
        cout << "你好欢迎光临,请自由选购" << endl
             << "1: 确认    2: 离开" << endl;
        cin >> chose;
        if( !(chose>= '0'&&chose <= '1')){
            cout << "输入错误，请重新选择"<<endl;
            setbuf(stdin, NULL);
            continue;
        }
        if (chose == '1')
        {
            Customer Ct(0, 0, 0, 0, 300);
            cout << "今日营业额: " << COC.getTurnover() << endl;
            cout << "--------商品货架--------" << endl
                 << "0 买完了,去结账" << endl
                 << "1 樱桃味尖叫(￥3 ): 库存" << Wh.getGoodsNum("cola") << endl
                 << "2 法式小面包(￥5 ): 库存" << Wh.getGoodsNum("bread") << endl
                 << "3 清风餐巾纸(￥10): 库存" << Wh.getGoodsNum("paper") << endl
                 << "4 过滤嘴香烟(￥60): 库存" << Wh.getGoodsNum("cigarette") << endl;
            while (1)
            {
                int type = 0;
                cout << "购物车:"
                     << "樱桃味尖叫" << Ct.showGoodsNum("cola") << "     法式小面包" << Ct.showGoodsNum("bread") << "    清风餐巾纸" << Ct.showGoodsNum("paper") << "    过滤嘴香烟" << Ct.showGoodsNum("cigarette") << endl;
                cout << "你想购买什么呢: ";
                cin >> chose;
                if( !(chose>= '0'&&chose <= '4')){
                    cout << "输入错误，请重新选择"<<endl;
                    char c;
                    while ((c = getchar()) != EOF && c != '\n');
                    continue;
                }
                switch (chose)
                {
                case '0':
                {
                    int pay = 0;
                    cout << "正在前往收银台..." << endl;
                    string goods[4] = {"cola", "bread", "paper", "cigarette"};
                    for (int i = 0; i < 4; i++)
                    {
                        COC.setAmount(goods[i], Ct.showGoodsNum(goods[i]));
                    }
                    cout << "您一共需要支付" << COC.getAmount() << "元" << endl;
                    cout << "请支付:";
                    cin >> num_c;
                    pay = exchange(num_c);
                    if (pay > Ct.showBalance())
                    {
                        cout << "您的余额不足,支付失败"<<endl;
                        COC.setAmount("all",0);
                        type = 1;
                        sleep(2);
                        break;
                    }
                    int money = COC.getAmount();
                    if(pay == money){
                        COC.setTurnover(pay);
                        type = 1;
                        COC.setAmount("all",0);
                        cout << "支付成功! 余额: " << Ct.pay(pay) << endl;
                        sleep(2);
                        break;
                    }
                    cout << "支付失败! 请支付等量余额"<<endl;
                    COC.setAmount("all",0);
                    break;
                }

                case '1':
                {
                    char c;
                    cout << "您要买多少瓶樱桃味尖叫呢: ";
                    while ((c = getchar()) != EOF && c != '\n');
                    cin >> num_c;
                    num = exchange(num_c);
                    if (num > Wh.getGoodsNum("cola"))
                    {
                        cout << "库存不足,请重试..." << endl;
                        continue;
                    }
                    if(num  == 0){
                        cout << "您取消了购买，正在返回..."<<endl;
                        continue;
                    }
                    Wh.setGoodsNum("cola", num);
                    Ct.addToShoppingCarts("cola", num);
                    cout << "加入购物车成功!" << endl;
                    sleep(1);
                    continue;
                }
                case '2':
                {
                    cout << "您要买多少包法式小面包呢: ";
                    cin >> num_c;
                    num = exchange(num_c);
                    if (num > Wh.getGoodsNum("bread"))
                    {
                        cout << "库存不足,请重试..." << endl;
                        continue;
                    }
                    if(num  == 0){
                        cout << "您取消了购买，正在返回..."<<endl;
                        continue;
                    }
                    Wh.setGoodsNum("bread", num);
                    Ct.addToShoppingCarts("bread", num);
                    cout << "加入购物车成功!" << endl;
                    continue;
                }
                case '3':
                {
                    cout << "您要买多少包清风餐巾纸呢: ";
                    cin >> num_c;
                    num = exchange(num_c);
                    if (num > Wh.getGoodsNum("paper"))
                    {
                        cout << "库存不足..." << endl;
                        continue;
                    }
                    if(num  == 0){
                        cout << "您取消了购买，正在返回..."<<endl;
                        continue;
                    }
                    Wh.setGoodsNum("paper", num);
                    Ct.addToShoppingCarts("paper", num);
                    cout << "加入购物车成功!" << endl;
                    continue;
                }
                case '4':
                {
                    cout << "您要买多少包香烟呢: ";
                    cin >> num_c;
                    num = exchange(num_c);
                    if (num > Wh.getGoodsNum("cigarette"))
                    {
                        cout << "库存不足,请重试..." << endl;
                        continue;
                    }
                    if(num  == 0){
                        cout << "您取消了购买，正在返回..."<<endl;
                        continue;
                    }
                    Wh.setGoodsNum("cigarette", num);
                    Ct.addToShoppingCarts("cigarette", num);
                    cout << "加入购物车成功!" << endl;
                    continue;
                }
                }
                if (type == 1)
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    Shopping();
    return 0;
}
