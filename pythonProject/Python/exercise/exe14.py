from sys import argv

script,user_name = argv#因为不确定argv包的内容所以提示警告
prompt = '> '

print ("hi %s, I'm the %s script." %(user_name,script))
print ("I'd like to ask you a few question.")

print ("do you like me %s?"%user_name)
likes = input(prompt)

print ("where do you live %s?"%user_name)
lives = input(prompt)

print ("what kind of conputer do you have?")
computer = input(prompt)

print ("""
Alright , so you said  %r about liking me.
you live in %r. Not sure where that is.
And you have a %r computer. Nice.
"""%(likes, lives,computer))