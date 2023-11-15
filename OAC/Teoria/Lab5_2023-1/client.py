import socket
from mensajes import recv_message, send_message

HOST = "localhost"
PORT = 5000
FILENAME = "big_file.txt"

def handle_connection(client_socket):
    # ----------------------------------------------
    # CODIGO PRINCIPAL
    # ----------------------------------------------
    with open(FILENAME, "r") as file:
        for line in file:
            send_message(client_socket, line)
       
    # ----------------------------------------------

def main():
    server_address = (HOST,PORT)
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as client_socket:
        client_socket.connect(server_address)
        handle_connection(client_socket)

if __name__ == "__main__":
    main()