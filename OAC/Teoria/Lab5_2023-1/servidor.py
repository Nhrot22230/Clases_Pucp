import socket
from mensajes import send_message, recv_message

HOST = "localhost"
PORT = 5000
FILENAME = "Escrito.txt"

def handle_client(client_socket,client_address):
    print("========================================================")
    print(f"Connection accepted from {client_address[0]}:{client_address[1]}")
    # ----------------------------------------------------
    # CODIGO PRINCIPAL
    # ----------------------------------------------------
    
    with open(FILENAME, "w") as file:
        while True:
            response = recv_message(client_socket)
            if(not response): break
            file.write(response + '\n')
    
    # ----------------------------------------------------
    client_socket.close()

def main():
    server_address = (HOST, PORT)
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_socket:
        try:
            server_socket.bind(server_address)
            server_socket.listen(4)
            
            print(f"Listening at {server_address[0]}:{server_address[1]}")
            while True:
                client_socket, client_address = server_socket.accept()
                handle_client(client_socket,client_address)

        except KeyboardInterrupt:
            print("\nExiting")

        except Exception as err:
            print(f"Aborting: {err}")
        finally:
            server_socket.close()

if __name__ == "__main__":
  main()
  