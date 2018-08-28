#将exe17.py的内容缩短到一条语句
from sys import argv
from os.path import exists
open(argv[2],'a').write(open(argv[1],'r').read())