import socket
import sys

if len(sys.argv) < 3:
    print("Usage: python3 client.py <IP address> <Port>")
    sys.exit(1)

server_ip = sys.argv[1]
server_port = int(sys.argv[2])

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    client_socket.connect((server_ip, server_port))
    print("Conectat la server")
except Exception as e:
    print("Eroare la conectarea la server:", e)
    sys.exit(1)

string = input("Enter the string: ")
client_socket.sendall(string.encode())

reversed_string = client_socket.recv(1024).decode()
print("The reversed string is:", reversed_string)

client_socket.close()