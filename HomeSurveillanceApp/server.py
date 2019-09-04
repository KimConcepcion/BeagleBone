from http.server import BaseHTTPRequestHandler

class Server(BaseHTTPRequestHandler):

    def do_HEAD(self):
        return

    def do_GET(self):
        self.respond()
        return

    def do_POST(self):
        return

    def http_handle(self, status, content_type):
        self.send_response(status)
        self.send_header('Content_type', content_type)
        self.end_headers()
        return bytes('Hello motherfucker', 'UTF-8')

    def respond(self):
        content = self.http_handle(200, 'text/html')
        self.wfile.write(content)
