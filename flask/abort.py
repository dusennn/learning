from flask import (Flask, abort, )


app = Flask(__name__)

@app.route('/user/<id>')
def get_user(id):
	def load_user(id):
		return {
			'id': id,
			'name': 'test',
		}
	user = load_user(id)
	if not user:
		abort(404)
	return '<h1>Hello, %s</h1>' % user['name']

if __name__ == '__main__':
	app.run(debug=True)