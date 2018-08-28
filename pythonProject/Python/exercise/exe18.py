#this one is like your scripts with argv
def print_tow(*args):
    arg1,arg2 = args
    print("arg1:%r, arg2:%r" %(arg1, arg2))

#ok, that *args is actually pointless, we can just do this
def print_tow_agian(arg1,arg2):
    print ("arg1:%r, arg2:%r" % (arg1, arg2))

#this just takes one argument
def print_one(arg1):
    print("arg1:%r" % arg1)

#this one takes no arguments
def print_none():
    print("no arguments")

print_tow("zed", "shaw")
print_tow_agian("zed", "shaw")
print_one("first!")
print_none()