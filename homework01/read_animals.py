import json
import random

with open('animals.json', 'r') as f:
        data = json.load(f)

# Generates a random index for the animal
i = random.randint(0,19)

# Selects a random animal from the list
randAnimal = [] 

randAnimal.append(data['head'][i])
randAnimal.append(data['body'][i])
randAnimal.append(data['arms'][i])
randAnimal.append(data['legs'][i])
randAnimal.append(data['tail'][i])

print(randAnimal)
