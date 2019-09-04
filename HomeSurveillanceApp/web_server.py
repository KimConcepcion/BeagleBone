from http.server import HTTPServer
from server import Server

import time
import psutil

HOST_NAME = '192.168.1.34'
PORT = 5000

if __name__ == '__main__':
    httpd = HTTPServer((HOST_NAME, PORT), Server)
    print(time.asctime(), 'Server UP - %s:%s' % (HOST_NAME, PORT))
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    print(time.asctime(), 'Server DOWN - %s:%s' % (HOST_NAME, PORT))
