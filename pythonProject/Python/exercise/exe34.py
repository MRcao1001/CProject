from sys import exit
def gold_room():
    print("this room is full of gold, how much do you take ? ")

    next = input(">> ")
    if "0" in next or "1" in next :
        how_much = int (next)
    else:
        dead("man, learn to type a number. ")
    
    if how_much < 50:
        print ("nice, you are not greedy, you win ")
        exit(0)
    else:
        dead("you areedy bastard! ")



def bear_room():
    print ("there is a bear here. ")
    print ("the bear has a bunch of honey. ")
    print ("the fat bear is in frount of another door")
    print ("how are you going to move the bear?")
    bear_moved = False

    while True:
        next = input(">> ")

        if next == "take honey:":
            dead("the bear looks at you then slaps your face off. ")
        elif next == "taunt bear" and not bear_moved:
            print ("the bear has moved from the door. you can gp through it now.")
        elif next == "open door" and bear_moved:
            gold_room()
        else:
            print ("I got no idea what that means.")



def cthulhu_room():
    print ("here you the the great evil cthulu.")
    print ("he, it, whatever stares at you and go insane.")
    print ("do you fiee for you life or eat you head?")

    next = input(">> ")

    if "flee" in next:
        start()
    elif "head" in next:
        dead("well that was tasty")
    else:
        cthulhu_room()




def dead(why):
    print (why, "good job!")
    exit(0)



def start():
    print ("you are in a dark room")
    print ("there is door to your right and left")
    print ("which one do you take?")


    next = input(">> ")
    
    if next == "left":
        bear_room()
    elif next == "right":
        cthulhu_room()
    else:
        dead("you stumble around the room ubtill you starve.")

start()