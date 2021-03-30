import redis, json, random, uuid, datetime
from flask import Flask, request

rd = redis.StrictRedis(host='redis', port=6379, db=0)

app = Flask(__name__)

# --- Writing to Redis Database ---
# Puts into redis's database the information from data_file.json
def write_to_redis():
	with open("../data/data_file.json", "r") as json_file:
		userdata = json.load(json_file)
		for x in userdata:
			rd.hmset(str(x), x)
# Print Test		print(rd.hget(str(x),'uid'))
	return userdata

# Executes and stores database information to data.
data = write_to_redis()
# Print Test print(data)

# Hello World Tester Route
@app.route('/helloworld', methods=['GET'])
def hello_world():
	return "Hello World!\n"
# ---

# Tester for returning dates
#@app.route('/animals/dates', methods=['GET'])
#def get_date():
#	date_list = []
#	for x in data:
#		date_list.append(rd.hget(str(x), 'created_on'))
#	return date_list

#query a range of dates
@app.route('/animals/dates', methods=['GET'])
def get_dates():
	start = request.args.get('start')
	startdate = datetime.datetime.strptime(start, "'%Y-%m-%d_%H:%M:%S.%f'")
	end = request.args.get('end')
	enddate = datetime.datetime.strptime(end, "'%Y-%m-%d_%H:%M:%S.%f'")
	return json.dumps([x for x in data if (datetime.datetime.strptime( x['created_on'], "'%Y-%m-%d_%H:%M:%S.%f'") >= startdate) and (datetime.datetime.strptime( x['created_on'], "'%Y-%m-%d_%H:%M:%S.%f'") <= enddate)])
# Print Test print(get_date())

# deletes a selection of animals by a date ranges
@app.route('/animals/delete_dates', methods=['GET'])
def delete_dates():
	start = request.args.get('start')
	startdate = datetime.datetime.strptime(start, "'%Y-%m-%d_%H:%M:%S.%f'")
	end = request.args.get('end')
	enddate = datetime.datetime.strptime(end, "'%Y-%m-%d_%H:%M:%S.%f'")
	date_data = []
	for x in data:
		if (datetime.datetime.strptime( x['created_on'], "'%Y-%m-%d_%H:%M:%S.%f'") <= startdate) and (datetime>datetime>strptime( x['created_on'], "'%Y-%m-%d_%H:%M:%S.%f'") >= enddate):
			date_data.append(x)
		else
			rd.delete(str(x))
	return json.dumps(date_data)
# ---
# selects by a unique identifier
# edits a particular creature by passing the UUID and updated "stats"
@app.route('/animals/select_UUID', methods=['GET'])
def select_UUID():
	uid = request.args.get('uid') #, Debugger uid Code: '5baaf418-75fa-4621-be31-09aa31756e79')
	part = request.args.get('part')
	value = request.args.get('value')
	animal = []
	for x in data:
		if uid != None and x['uid'] == uid:
			animal = x
			if part != None:
				animal[str(part)] = value
				rd.hmset(str(x), x)
	return json.dumps(animal)
# ---

# returns the average number of legs per animal
@app.route('/animals/avg_legs', methods=['GET'])
def avg_legs():
	leg_count = 0
	for x in data:
		leg_count += x['legs']
	leg_count = leg_count / len(data)
	return json.dumps(leg_count)

# returns the total animal count
@app.route('/animals/total', methods=['GET'])
def tot_animals():
	return json.dumps(len(data))

# --- Prior Code for Previous Homeworks / Miscellaneous ---

#@app.route('/animals', methods=['GET'])
#def get_animals():
#	return json.dumps(getdata())

#@app.route('/animals/total', methods=['GET'])
#def tot_animals():
#	return json.dumps(len(getdata()))

#@app.route('/animals/UUID', methods=['GET'])
#def get_UUID():
#	library = getdata()
#	output = []
#	for x in library:
#		output.append(x['uid'])
#	return json.dumps(output)
#
#@app.route('/animals/avg_legs', methods=['GET'])
#def avg_legs():
#	library = getdata()
#	output = 0
#	for x in library:
#		output += x['legs']
#	output = output / int(tot_animals())
#	return str(output)
#
#def getdata():
#	with open("/app/data_file.json", "r") as json_file:
#		userdata = json.load(json_file)
#	return userdata
#
#if __name__ == '__main__':
#	app.run(debug=True, host='0.0.0.0')
