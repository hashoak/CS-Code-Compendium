import socket

def start_tcp_file_server():
    server_address = ('localhost', 8000)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(server_address)
    server_socket.listen(1)

    print('TCP File Transfer Server started. Waiting for connections...')

    while True:
        client_socket, client_address = server_socket.accept()
        print(f'Connected to client: {client_address[0]}:{client_address[1]}')

        file_name = client_socket.recv(1024).decode('utf-8')
        print(f'Requested file: {file_name}')

        try:
            with open(file_name, 'rb') as file:
                data = file.read()
                client_socket.sendall(data)
            print('File transfer completed successfully.')
        except IOError:
            print(f'Error: File "{file_name}" not found.')

        client_socket.close()

    server_socket.close()

start_tcp_file_server()
