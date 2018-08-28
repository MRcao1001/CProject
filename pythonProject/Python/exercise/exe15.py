from sys import argv

script,fileName = argv
txt  = open(fileName)

print ("here is you file %r:" %fileName)

print (txt.read())
txt.close()

print ("Type the filename agina:")
file_again = input("> ")
txt_again = open(file_again)
print (txt_again.read())
txt_again.close()