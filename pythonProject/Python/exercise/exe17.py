from sys import argv
from os.path import exists

script, from_file, to_file = argv

print ("copying from %s to %s" %(from_file, to_file))
file_input = open(from_file)
indata = file_input.read()

print ("The input file is %d bytes long" % len(indata))

print ("does the output file exist ? %r"% exists(to_file))
print ("ready, hit RETURN to continue, CTRL-C to abort.")
input ()

file_output = open(to_file, 'w')
file_output.write(indata)

print ("Alrigt, all done")

file_output.close()
file_input.close()