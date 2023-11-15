import socket
import threading
from mensajes import send_message, recv_message

def handle_client(client_socket,client_address):
  print("========================================================")
  print(f"Connection accepted from {client_address[0]}:{client_address[1]}")
  # ----------------------------------------------------
  # CODIGO PRINCIPAL
  # ----------------------------------------------------
  request = recv_message(client_socket)
  response = "Message from the server"
  send_message(client_socket,response)
  # ----------------------------------------------------
  client_socket.close()

def main():
  server_address = ("localhost",5000)
  with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_socket:
    try:
      server_socket.bind(server_address)
      server_socket.listen(4)
      
      print(f"Listening at {server_address[0]}:{server_address[1]}")
      while True:
        client_socket, client_address = server_socket.accept()
        t = threading.Thread(target=handle_client,args=(client_socket,client_address))
        t.start()

    except KeyboardInterrupt:
      print("\nExiting")

    except Exception as err:
      print(f"Aborting: {err}")

if __name__ == "__main__":
  main()
  