import socket

def tcp_echo_client():
    server_address = ('localhost', 8000)
    message = input('Enter a message: ')

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(server_address)

    client_socket.sendall(message.encode('utf-8'))
    response = client_socket.recv(1024)

    print('Server response:', response.decode('utf-8'))

    client_socket.close()

tcp_echo_client()
