import socket
from mensajes import recv_message, send_message

def handle_connection(client_socket):
    # ----------------------------------------------
    # CODIGO PRINCIPAL
    # ----------------------------------------------
    request = "Message from the client"
    send_message(client_socket,request)
    response = recv_message(client_socket)
    # ----------------------------------------------

def main():
    server_address = ("localhost",5000)
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as client_socket:
        client_socket.connect(server_address)
        handle_connection(client_socket)

if __name__ == "__main__":
    main()

