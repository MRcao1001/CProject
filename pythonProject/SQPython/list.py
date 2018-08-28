import copy
"""
Python List 列表
知识点: 列表
理论输出:
    ['heart', 12, 46, 'name', ['hello', 'world', 3.14]]
    heart
    12
    46
    name
    ['hello', 'world', 3.14]

    
"""
list = ["heart", 12, 46, "name", ["hello", "world", 3.14]]
print(list)
for i in list:
    print(i)


"""
list 切片
知识点: 切片
理论输出:
    heart
    12
    46
    [46]
"""
print(list[2: 3])  # [2,3)


"""
list 倒置输出
知识点: 切片
理论输出:
    [['hello', 'world', 3.14], 'name', 46, 12, 'heart']
"""
print(list[:: -1])


"""
list 元素定位
知识点: index()
理论输出:
    > name
    3
"""
tem = input("> ")
if tem in list:
    ret = list.index(tem)
    print(ret)
else:
    print("not in list")


"""
拷贝 使用copy产生一个新的list对象
知识点: 深拷贝:copy.deepcopy(), 浅拷贝copy()
理论输出:
    list2: ['heart', 12, 46, 'name', ['hello', 'world', 3.14]]
    list: ['heart', 12, 46, 'name', ['hello', 'lll', 3.14]]
    list3: ['heart', 12, 46, 'name', ['hello', 'lll', 3.14]]
    list: ['heart', 12, 46, 'name', ['hello', 'lll', 3.14]]
    list4: ['heart', 12, 46, 'name', ['hello', 'aaa', 3.14]]
"""
list2 = list.copy()
print("list2: %r" % list2)
# 在此处修改list2中的列表的元素时会同时改动list1中的元素,因为浅拷贝中的列表和原来列表中的列表是同一个列表的引用-----浅拷贝
list3 = list[:]
list3[4][1] = "lll"
print("list: %r" % list)
print("list3: %r" % list3)
#引用 copy 模组,使用copy.deepcopy()深拷贝函数,可以实现从内存地址的拷贝,拷贝前后的对象完全独立
list4 = copy.deepcopy(list)
list4[4][1] = "aaa"
print("list: %r" % list)
print("list4: %r" % list4)


"""
搜索元素并删除,同时插入一个新元素"未命名"
知识点: 切片, find(), remove(), append()
理论结果:
    > 王
    王大
    王二
    王八
    ['曹操', '陈浩', '孙大佬']
"""
print("------------------------------------")
nameList = ["王大", "王二", "王八", "曹操", "陈浩", "孙大佬"]
nameInput = input("> ")
for name in nameList[:]:
    #此处对namelist切片,于是name在list的切片中遍历,remove在list中操作,避免了跳过元素的bug
    if not name.find(nameInput):
        print(name)
        nameList.remove(name)
        nameList.append("未命名")
print(nameList)
