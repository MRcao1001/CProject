def cheese_adn_crackers(cheese_count, boxes_of_crackers):
    print ("you have %d cheeses !" % cheese_count)
    print ("you have %d boxes of crackers !" % boxes_of_crackers)
    print ("man thar's enough for a party !")
    print ("get a blanket.\n")


print ("we can just give the function numbers directly:")
cheese_adn_crackers(20, 30)


print ("or, we can use variables from our script:")
amount_of_cheese = 10
amount_of_crackers = 50

cheese_adn_crackers(amount_of_cheese, amount_of_crackers)

print ("we can eveb do math inside too:")
cheese_adn_crackers(10 + 20, 5 + 6)

print ("and we can combine the tow, ariables and math:")
cheese_adn_crackers(amount_of_cheese + 100, amount_of_crackers + 100)
