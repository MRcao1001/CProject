"""
字典
字典的数据为:键值对
""
stu = {1001:['jack', 18, '黄山'], 1002:['rose', 20, '洛阳'], 1003:['gbcf', 31, '合肥']}
print(type(stu))
print(stu)

""
修改
""
value = stu[1001]
value[0] = 'bob'
print (stu)
"""

"""
模拟超市
"""
#商品字典
Product = {'1:可口可乐':[3, 1000], '2:盼盼小面包':[2, 2000], '3:金华火腿':[20, 50], '4:正宗椰子汁':[5, 400]}
ShoppingCart = {'1:可口可乐':[3, 0], '2:盼盼小面包':[2, 0], '3:金华火腿':[20, 0], '4:正宗椰子汁':[5, 0]}
while 1:
    print(Product)
    inputWords = input("请输入选择的编号(输入exit退出)> ")
    if inputWords == "exit":
        break
    number_s = input("你要买多少? >")
    number = int(number_s)
    if inputWords == "1":
        ShoppingCart['1:可口可乐'][1]+=number
        Product['1:可口可乐'][1]-=number

    elif inputWords == "2":
        ShoppingCart['2:盼盼小面包'][1]+=number
        Product['2:盼盼小面包'][1]-=number

    elif inputWords == "3":
        ShoppingCart['3:金华火腿'][1]+=number
        Product['3:金华火腿'][1]-=number

    elif inputWords == "4":
        ShoppingCart['4:正宗椰子汁'][1]+=number
        Product['4:正宗椰子汁'][1]-=number

    

print ("购物车: %r"%ShoppingCart)
money = ShoppingCart['1:可口可乐'][0]*ShoppingCart['1:可口可乐'][1]
money+= ShoppingCart['2:盼盼小面包'][0]*ShoppingCart['2:盼盼小面包'][1]
money+= ShoppingCart['3:金华火腿'][0]*ShoppingCart['3:金华火腿'][1]
money+= ShoppingCart['4:正宗椰子汁'][0]*ShoppingCart['4:正宗椰子汁'][1]
print ("金额: %r"%money)