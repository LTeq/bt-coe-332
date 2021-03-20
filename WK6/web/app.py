from flask import Flask
app = Flask(__name__)

@app.route('/', methods = ['GET'])
def helloworld():
	return "Hello World!!!"

if __name__ == 'main':
	app.run(debug = True, host = '0.0.0.0')
