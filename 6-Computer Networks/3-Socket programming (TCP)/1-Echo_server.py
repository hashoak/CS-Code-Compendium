import socket

def start_tcp_echo_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 8000)
    server_socket.bind(server_address)
    server_socket.listen(1)

    print('TCP Echo server started. Listening on port 8000...')

    while True:
        print('Waiting for a client to connect...')
        client_socket, client_address = server_socket.accept()
        print('Client connected:', client_address)

        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            client_socket.sendall(data)

        client_socket.close()
        print('Client disconnected.')

start_tcp_echo_server()
