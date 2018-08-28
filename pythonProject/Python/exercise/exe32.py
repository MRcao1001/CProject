the_count = [1, 2, 3, 4, 5]
fruites = ['apples', 'oranges', 'pears', 'apricots']
change = [1, 'pennies', 2, 'dimes', 3, 'quarters']

for number in the_count:
    print ("this is count : %d" % number)


for fruit in fruites:
    print ("A fruit of type : %s" % fruit)


for i in change:
    print ("I got %r" % i)


elements = []
k = 10
for i in range(k):
    print ("Adding %d to the list." % i)
    elements.append(i)

for i in elements:
    print ("element was: %d" % i)
