import json
from flask import Flask, requests

app = Flask(__name__)

@app.route('/animals', methods=['Get'])
def print_Animals():
	return json.dumps(get_data())

# Returns animals with a head type as specified by the URL
# Can also be done using: output = [x for x in test if x['head'] == 'snake']
@app.route('/animals/head/<head_type>', methods=['Get'])
def print_Head_Type():
	animal_dict = get_data()
	new_animal_dict = {}
	for i in animal_dict['animals']:
		if (animal_dict['animals']['head'] == head_type):
			new_animal_dict['animals'].append(animal_dict['animals'][i])
	return new_animal_dict

# Returns animals with a leg count as specified by the URL
# Can also be done using: output = [x for x in test if x['head'] == 'snake']
@app.route('/animals/head/<leg_count>', methods=['Get'])
def print_Leg_Count():
        animal_dict = get_data()
        new_animal_dict = {}
        for i in animal_dict['animals']:
                if (animal_dict['animals']['legs'] == leg_type):
                        new_animal_dict['animals'].append(animal_dict['animals'][i])
        return new_animal_dict

def get_data():
	with open("/app/animals.json", 'r') as json_file:
		animal_dict = json.load(json_file)
	return animal_dict

if __name__ == '__main__':
	app.run(debug=True, host='0.0.0.0')
