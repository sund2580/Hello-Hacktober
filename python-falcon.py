# Hello World written in Falcon (nano) web framework

# 1. To install falcon run: pip install falcon (or with pipenv: pipenv install falcon)
# 2. To serve a Falcon app, you will need a WSGI server: install uwsgi or gunicorn (pip install gunicorn)
# 3. Run the app with: gunicorn python-falcon:app
# 4. Profit! Also you might want to visit http://127.0.0.1:8000

import falcon

class HelloWorldResource:
    def on_get(self, req, resp):
        """Handles GET requests"""
        resp.status = falcon.HTTP_200
        resp.body = "Hello World!"

app = falcon.API()
hello_world = HelloWorldResource()
app.add_route('/', hello_world)
