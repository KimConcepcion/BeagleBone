import os
from response.requestHandler import RequestHandler

class StaticHandler(RequestHandler):

    def __init__(self):
        self.filetypes = {
        ".js" : "text/javascript",
        ".css" : "text/css",
        ".jpg" : "image/jpeg",
        ".png" : "image/png",
        "notfound" : "text/plain"
        }

    def find(self, file_path):
        # Use splittext function from OS module to capture extension of
        # file. File should be <filename + extension>. The extension variable
        # contains the file extension from the 1 element in the array:
        split_path = os.path.splitext(file_path)
        extension = split_path[1]

        try:
            if extension in (".jpg", ".jpeg", ".png"):
                self.contents = open("public{}".format(file_path), 'rb')
            else:
                self.contents = open("public{}".format(file_path), 'r')

            self.setContentType(extension)
            self.setStatus(200)
            return True

        except:
            self.setContentType('notfound')
            self.setStatus(404)
            return False

    def setContentType(self, ext):
        self.contentType = self.filetypes[ext]
