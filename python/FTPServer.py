#!/usr/bin/python3

from pyftpdlib.authorizers import DummyAuthorizer
from pyftpdlib.handlers import FTPHandler
from pyftpdlib.servers import FTPServer

authorizer = DummyAuthorizer()
authorizer.add_user(
    "test", "test", "/Users/username", perm="elradfmw")

handler = FTPHandler
handler.authorizer = authorizer
handler.passive_ports = range(60000, 61000)

server = FTPServer(("172.20.10.3", 2000), handler)
server.serve_forever()
