import socket

def send_message(socket: socket.socket, message = "Mensaje default"):
  raw_message = message.encode("utf-8")
  socket.sendall(raw_message)
  print("========================================================")
  print(f"Sent: {message}")

def recv_message(socket: socket.socket, BUFFSIZE = 1024) -> str:
  raw_message = socket.recv(BUFFSIZE)
  message = raw_message.decode("utf-8")
  print("========================================================")
  print(f"Received: {message}")
  return message