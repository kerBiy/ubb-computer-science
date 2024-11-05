.PHONY: server client python

server:
	gcc server.c -o server && ./server

client:
	gcc client.c -o client && ./client 127.0.0.1 1234 

python:
	python3 client.py 127.0.0.1 1234