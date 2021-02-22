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
        i = random.sample((1,5), 2)
        if (i[0] == 1):
                bodylist.append('snake')
        if (i[0] == 2):
        	bodylist.append('bull')
        if (i[0] == 3):
                bodylist.append('lion')
        if (i[0] == 4):
                bodylist.append('raven')
        if (i[0] == 5):
                bodylist.append('bunny')
        if (i[1] == 1):
                bodylist[x] += '-snake'
        if (i[1] == 2):
                bodylist[x] += '-bull'
        if (i[1] == 3):
                bodylist[x] += '-lion'
        if (i[1] == 4):
                bodylist[x] += '-raven'
        if (i[1] == 5):
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
animals = {}

# 0 = head
# 1 = body
# 2 = tail
# 3 = arm
# 4 = leg

animals['head'] = headlist
animals['body'] = bodylist
animals['tail'] = taillist
animals['arms'] = armlist
animals['legs'] = leglist

# Writes to the json file.
with open("animals.json", "w") as write_file:
        json.dump(animals, write_file, indent = 5)
