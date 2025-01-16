import socket

def start_udp_file_server():
    server_address = ('localhost', 8000)
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(server_address)

    print('UDP File Transfer Server started. Waiting for connections...')

    while True:
        file_name, client_address = server_socket.recvfrom(1024)
        file_name = file_name.decode('utf-8')
        print(f'Requested file: {file_name}')

        try:
            with open(file_name, 'rb') as file:
                data = file.read()
                server_socket.sendto(data, client_address)
            print('File transfer completed successfully.')
        except IOError:
            print(f'Error: File "{file_name}" not found.')

    server_socket.close()

start_udp_file_server()
