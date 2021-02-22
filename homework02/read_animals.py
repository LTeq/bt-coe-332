import json
import random
import string

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
	tailAvg = int((data['tail'][i[0]] + data['legs'][i[1]]) / 2)
	bredAnimal.append(tailAvg) 

	print(bredAnimal)

def randAnimal(data):

	i = random.randint(0.,19)
	
	randomAnimal = []
	
	randomAnimal.append(data['head'][i])
	randomAnimal.append(data['body'][i])
	randomAnimal.append(data['arms'][i])
	randomAnimal.append(data['legs'][i])
	randomAnimal.append(data['tail'][i])
	
	print(randomAnimal)

def main():
	
	with open('animals.json', 'r') as f:
		data = json.load(f)
	
	breedAnimal(data)
	randAnimal(data)

if __name__ == '__main__':
	main()
