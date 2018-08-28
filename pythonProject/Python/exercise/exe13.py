#!/usr/local/bin/python3.6
#传参 解包 变量
from sys import argv
#引用参数变量功能包

script, first, second, third = argv

print ("The script is called:", script)
print ("you first variable is:", first)
print ("you second variables is:", second)
print ("you third variable is:", third)