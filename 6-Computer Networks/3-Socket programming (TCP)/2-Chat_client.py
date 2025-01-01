import socket
import threading

def receive_tcp(client_socket_tcp):
    while True:
        try:
            message = client_socket_tcp.recv(1024).decode('utf-8')
            print('Received:', message)
        except ConnectionResetError:
            print('Disconnected from the server.')
            break

def send_tcp(client_socket_tcp):
    while True:
        message = input()
        client_socket_tcp.sendall(message.encode('utf-8'))

def start_tcp_chat_client():
    server_address = ('localhost', 8000)

    client_socket_tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket_tcp.connect(server_address)
    
    receive_thread = threading.Thread(target=receive_tcp,args=(client_socket_tcp,))
    send_thread = threading.Thread(target=send_tcp,args=(client_socket_tcp,))

    send_thread.start()
    receive_thread.start()

    send_thread.join()
    receive_thread.join()

start_tcp_chat_client()
