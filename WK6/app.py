import json
from flask import Flask, request

app = Flask(__name__)

@app.route('/helloworld', methods=['Get'])
def hello_world():
        return "Hello World!!\n"

@app.route('/helloworld/<name>', methods=['Get'])
def hello_name(name):
	return "Hello {}\n".format(name)

@app.route('/hello', methods=['GET'])
def hello_name1():
	print (request.args)
	for i in request.args.keys():
		print(i)
	name = request.args.get('name')
	return "(round2) Hello {}\n".format(name)

@app.route('/degrees', methods=['GET'])
def get_degrees():
	return json.dumps(get_data())

def get_data():
	return [{'id':0, 'year':1990, 'degrees':5000}, {'id':1,'year':1991, 'degrees':6000}]

if __name__ == '__main__':
        app.run(debug=True, host='0.0.0.0')
