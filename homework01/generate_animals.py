import json
import random

# Generates a list of heads from petname list using a random variable.
headlist = []
for x in range(0,20):
        i = random.randint(1,5)
        if (i == 1):
                headlist.append('snake')
        if (i == 2):
                headlist.append('bull')  
        if (i == 3):
                headlist.append('lion')
        if (i == 4):
                headlist.append('raven')
        if (i == 5):
                headlist.append('bunny')

# Generates a list of bodies from petname list using two random variables.
bodylist = []
for x in range(0,20):
        i = random.randint(1,5)
        j = random.randint(1,5)
        if (i == 1):
                bodylist.append('snake')
        if (i == 2):
                bodylist.append('bull')
        if (i == 3):
                bodylist.append('lion')
        if (i == 4):
                bodylist.append('raven')
        if (i == 5):
                bodylist.append('bunny')

        if (j == 1):
                bodylist[x] += '-snake'
        if (j == 2):
                bodylist[x] += '-bull'
        if (j == 3):
                bodylist[x] += '-lion'
        if (j == 4):
                bodylist[x] += '-raven'
        if (j == 5):
                bodylist[x] += '-bunny'

# creates an empty list to add tails into.
taillist = []

# Creates a list of arms.
armlist = []
for x in range(0,20):
        armlist.append(random.randrange(2,10,2))

# Creates a list of legs.
leglist = []
for x in range(0,20):
        leglist.append(random.randrange(3,12,3))

for x in range(0,20):
        taillist.append(armlist[x] + leglist[x])

# Creates a list with each location signifying each body part.
animals = []

# 0 = head
# 1 = body
# 2 = tail
# 3 = arm
# 4 = leg
animals.append(headlist)
animals.append(bodylist)
animals.append(taillist)
animals.append(armlist)
animals.append(leglist)

# Writes to the json file.
with open("animals.json", "w") as write_file:
        json.dump(animals[0], write_file)
	json.dump(animals[1], write_file)
	json.dump(animals[2], write_file)
	json.dump(animals[3], write_file)
	json.dump(animals[4], write_file)
