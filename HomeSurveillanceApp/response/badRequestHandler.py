from response.requestHandler import RequestHandler

class BadRequestHandler(RequestHandler):

    def __init__(self):
        super().__init__()
        self.contentType = 'text/html'
        self.setStatus(404)

    def bad_request(self):
        template_file = open('templates/404.html')
        return template_file
