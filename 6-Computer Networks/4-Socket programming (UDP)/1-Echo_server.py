import socket

def start_udp_echo_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 8000)
    server_socket.bind(server_address)

    print('UDP Echo server started. Listening on port 8000...')

    while True:
        print('Waiting for a message...')
        data, address = server_socket.recvfrom(1024)

        server_socket.sendto(data, address)

start_udp_echo_server()
