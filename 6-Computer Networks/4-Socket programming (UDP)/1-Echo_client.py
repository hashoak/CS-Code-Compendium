import socket

def udp_echo_client():
    server_address = ('localhost', 8000)
    message = input('Enter a message: ')

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client_socket.sendto(message.encode('utf-8'), server_address)

    response, _ = client_socket.recvfrom(1024)

    print('Server response:', response.decode('utf-8'))

    client_socket.close()

udp_echo_client()
