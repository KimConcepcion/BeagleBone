
## Standard imports:
import os

## Local imports:
from http.server import BaseHTTPRequestHandler
from routes.main import routes
from pathlib import Path
from response.templateHandler import TemplateHandler
from response.badRequestHandler import BadRequestHandler
from response.staticHandler import StaticHandler

class Server(BaseHTTPRequestHandler):

    def do_POST(self):
        return

    def do_HEAD(self):
        return

    def do_GET(self):
        split_path = os.path.splitext(self.path)
        request_extension = split_path[1]

        if request_extension is "" or request_extension is ".html":
            if self.path in routes:
                handler = TemplateHandler()
                handler.find(routes[self.path])
            else:
                handler = BadRequestHandler()
        elif request_extension is ".py":
            handler = BadRequestHandler()
        else:
            handler = StaticHandler()
            handler.find(self.path)

        self.respond({
            'handler' : handler
        })

    def http_handle(self, handler):
        status_code = handler.getStatus()
        self.send_response(status_code)

        if status_code is 200:
            content = handler.getContents()
            self.send_header('Content_type', handler.getContentType)
        else:
            #content = handler.bad_request()
            content = "404 Not Found"

        self.end_headers()

        # Check if content(image) from handler is in bytes or bytearray
        # If the content is already in e.g. bytes then return it:
        if isinstance( content, (bytes, bytearray) ):
            return content

        return bytes(content, 'UTF-8')

    def respond(self, opts):
        reponse = self.http_handle(opts['handler'])
        self.wfile.write(reponse)
