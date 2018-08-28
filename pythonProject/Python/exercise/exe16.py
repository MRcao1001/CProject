#!/usr/bin/env python3
from sys import argv

script,fileName = argv
txt  = open(fileName,'a')

print ("here is you file %r:" %fileName)

stuff = input("please input a words> ")
txt.write('\n'+stuff)

txt.close()

txt = open(fileName, "r")

