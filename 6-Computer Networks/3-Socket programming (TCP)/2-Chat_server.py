import socket
import threading

def handle_client_tcp(client_socket, address):
    print(f'Connected new client: {address}')

    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')

            if not message:
                print(f'Client {address} disconnected.')
                break

            print(f'Received from {address}: {message}')

            # Broadcast the received message to all connected clients
            broadcast_tcp(message, client_socket)

        except ConnectionResetError:
            print(f'Client {address} forcibly disconnected.')
            break

    client_socket.close()

def broadcast_tcp(message, sender_socket):
    for client in client_sockets_tcp:
        if client != sender_socket:
            try:
                client.sendall(message.encode('utf-8'))
            except socket.error as e:
                print(f'Error occurred while broadcasting message: {str(e)}')

def start_tcp_chat_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 8000)
    server_socket.bind(server_address)
    server_socket.listen(5)

    print('TCP Chat server started. Listening on port 8000...')

    while True:
        client_socket, client_address = server_socket.accept()
        client_sockets_tcp.add(client_socket)

        client_thread = threading.Thread(target=handle_client_tcp, args=(client_socket, client_address))
        client_thread.start()

client_sockets_tcp = set()

start_tcp_chat_server()
