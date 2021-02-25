#!/usr/bin/env python3
import json
import random
import string
import sys

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
def breed_animal(animal_dict):

	i = random.sample(range(0,19), 2)
	
	bred_animal = {}

	# Merges the animals' heads as long as they are different.
	bred_animal['head'] = str(animal_dict['animals'][i[0]]['head'])
	if(str(animal_dict['animals'][i[1]]['head']) != str(animal_dict['animals'][i[0]]['head']):
		bred_animal['head'] += '-' + str(animal_dict['animals'][i[1]]['head'])

	# Partitions out the bodies of the parents so that there are only at max 2 body types.
	bodyPartition1 = animal_dict['animals'][i[0]]['body'].partition('-')
	bodyPartition2 = animal_dict['animals'][i[0]]['body'].partition('-')
	j = random.randint(0,1) * 2
	bred_animal['body'] = bodyPartition1[j]
	k = random.randint(0,1) * 2
	if (bodyPartition1[j] != bodyPartition2[k]):
		bred_animal['body'] += '-' + bodyPartition2[k]

	# Merges the animals' arm count by taking an average.
	bred_animal['arms'] = int((animal_dict['animals'][i[0]]['arms'] + animal_dict['animals'][i[1]]['arms']) / 2)
	bred_animal['legs'] = int((animal_dict['animals'][i[0]]['legs'] + animal_dict['animals'][i[1]]['legs']) / 2)
	bred_animal['tail'] = int((animal_dict['animals'][i[0]]['tail'] + animal_dict['animals'][i[1]]['tail']) / 2)

	return bred_animal

def main():
	with open(sys.argv[1], 'r') as f:
		animal_dict = json.load(f)
	print('Random animal: ')
	print(random.choice(animal_dict['animals']))
	bred = breed_animal(animal_dict)
	
	# Checks that the bred animal has body parts that follow the right types.
	check_animal_head( bred['head'])
	check_animal_body( bred['head'])
	check_animal_arms( bred['arms'])
	check_animal_legs( bred['legs'])
	check_animal_tail( bred['tail'])
	
	# Prints the bred animal.
	print('\nBred animal: ')
	print(bred)

	# Checks each animal inside animal_dict to see if they follow the right types.
	for x in range(0, 20):
		check_animal_head( animal_dict['animals'][x]['head'])
		check_animal_body( animal_dict['animals'][x]['body'])
		check_animal_arms( animal_dict['animals'][x]['arms'])
		check_animal_legs( animal_dict['animals'][x]['legs'])
		check_animal_tail( animal_dict['animals'][x]['tail'])

if __name__ == '__main__':
	main()
