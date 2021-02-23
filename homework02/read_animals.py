import json
import random
import string

# Unit tests for animal body parts.
def check_animal_head(head):
	assert isinstance(head, str), 'The head should be a string'

def check_animal_body(body):
	assert isinstance(body, str), 'The body should be a string'

def check_animal_arms(arms):
	assert isinstance(arms, int), 'The arms should be an int'

def check_animal_legs(legs):
	assert isinstance(legs, int), 'The legs should be an int'

def check_animal_tail(tail):
	assert isinstance(tail, int), 'The tails should be an int'

# Returns a bred animal from two random parents.
def breedAnimal(data):

	i = random.sample(range(0,19), 2)
	
	bredAnimal = []

	# Breeds the animal to have a mixed head type.
	bredAnimal.append(data['head'][i[0]])
	bredAnimal[0] += '-' + data['head'][i[1]]

	# Breeds the animal to have a mixed body type.
	# Since body already contains multiple body types, the string is partitioned to have only one per parent.
	bodyPartition1 = data['body'][i[0]].partition('-')
	bodyPartition2 = data['body'][i[1]].partition('-')

	# Selects a random index of the body partition to add that is not '-'
	j = random.randint(0,1) * 2
	bredAnimal.append(bodyPartition1[j])
	
	k = random.randint(0,1) * 2
	if (bodyPartition1[j] != bodyPartition2[k]):
		bredAnimal[1] += '-' + bodyPartition2[k]

	# Breeds the animal to have the average number of arms between the parents.
	armAvg = int((data['arms'][i[0]] + data['arms'][i[1]]) / 2)
	bredAnimal.append(armAvg)
	
	# Breeds teh animal to have the average number of legs between the parents.
	legAvg = int((data['legs'][i[0]] + data['legs'][i[1]]) / 2)
	bredAnimal.append(legAvg)

	# Breeds the animal to have the average number of tails between the parents.
	tailAvg = int((data['tail'][i[0]] + data['tail'][i[1]]) / 2)
	bredAnimal.append(tailAvg) 

	return bredAnimal

# Returns a random animal from the list.
def randAnimal(data):

	i = random.randint(0,19)
	
	randomAnimal = []
	randomAnimal.append(data['head'][i])
	randomAnimal.append(data['body'][i])
	randomAnimal.append(data['arms'][i])
	randomAnimal.append(data['legs'][i])
	randomAnimal.append(data['tail'][i])

	return randomAnimal

def main():
	
	with open('animals.json', 'r') as f:
		data = json.load(f)

	# Increments over animals and checks that they are each of the right type.
	for i in range(0,20):
		check_animal_head( data['head'][i])
		check_animal_body( data['body'][i])
		check_animal_arms( data['arms'][i])
		check_animal_legs( data['legs'][i])
		check_animal_tail( data['tail'][i])

	print(breedAnimal(data))
	print(randAnimal(data))

if __name__ == '__main__':
	main()
