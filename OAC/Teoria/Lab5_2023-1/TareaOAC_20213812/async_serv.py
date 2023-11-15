import socket
import asyncio
from mensajes import send_message, recv_message

async def handle_client(client_socket,client_address):
    print("========================================================")
    print(f"Connection accepted from {client_address[0]}:{client_address[1]}")
    # ----------------------------------------------------
    # CODIGO PRINCIPAL
    # ----------------------------------------------------
    request = recv_message(client_socket)
    await asyncio.sleep(0)

    response = "Message from the server"
    send_message(client_socket,response)
    await asyncio.sleep(0)

    # ----------------------------------------------------
    client_socket.close()

async def main():
    loop = asyncio.get_event_loop()
    server_address = ("localhost",5000)
    with socket.socket(socket.AF_INET,socket.SOCK_STREAM) as server_socket:
        try:
            server_socket.bind(server_address)
            server_socket.listen(4)
            server_socket.setblocking(False)

            print(f"Listening at {server_address[0]}:{server_address[1]}")
            while True:
                client_socket, client_address = await loop.sock_accept(server_socket)
                asyncio.create_task(handle_client(client_socket,client_address))

        except KeyboardInterrupt:
            print("\nExiting")
            loop.close()
    
if __name__ == "__main__":
  asyncio.run(main())
  