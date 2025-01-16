import socket
import threading

def handle_client_udp(message, address):
    print(f'Received from {address}: {message}')

    # Broadcast the received message to all connected client_addresses_udp
    broadcast_udp(message, address)

def broadcast_udp(message, sender_address):
    for client_address in client_addresses_udp:
        if client_address != sender_address:
            try:
                server_socket.sendto(message.encode('utf-8'),client_address)
            except socket.error as e:
                print(f'Error occurred while broadcasting message: {str(e)}')

def start_udp_chat_server():
    global server_socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 8000)
    server_socket.bind(server_address)

    print('UDP Chat server started. Listening on port 8000...')

    while True:
        message, client_address = server_socket.recvfrom(1024)
        if client_address:
            client_addresses_udp.add(client_address)

            client_thread = threading.Thread(target=handle_client_udp, args=(message.decode('utf-8'), client_address))
            client_thread.start()

client_addresses_udp = set()

start_udp_chat_server()
