from flask import Flask, render_template
from flask_script import Manager


app = Flask(__name__)
manager = Manager(app)

@app.route('/')
def index():
	return render_template('index.html')

@app.route('/user/<name>')
def user(name):
	return render_template('user.html', name=name)

@app.route('/variable/<myintvar>')
def variable(myintvar):
	mydict = {'key': 'this is dictinoary.'}
	mylist = [0, 1, 2, 3, 4, 5]

	return render_template('variable.html', mydict=mydict, mylist=mylist, myintvar=myintvar)

if __name__ == '__main__':
	manager.run()
