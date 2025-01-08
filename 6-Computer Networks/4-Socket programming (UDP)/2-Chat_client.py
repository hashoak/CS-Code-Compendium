import socket
import threading

def receive_udp(client_socket_udp,ntg):
    while True:
        try:
            message = client_socket_udp.recv(1024).decode('utf-8')
            print('Received:', message)
        except ConnectionResetError:
            print('Disconnected from the server.')
            break

def send_udp(client_socket_udp,server_address):
    while True:
        message = input()
        client_socket_udp.sendto(message.encode('utf-8'),server_address)

def start_udp_chat_client():
    server_address = ('localhost', 8000)

    client_socket_udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    for i in range(8001,9000):
        try: 
            client_socket_udp.bind(('localhost', i))
        except:
            continue
    
    receive_thread = threading.Thread(target=receive_udp,args=(client_socket_udp,"x"))
    send_thread = threading.Thread(target=send_udp,args=(client_socket_udp,server_address))

    send_thread.start()
    receive_thread.start()

    send_thread.join()
    receive_thread.join()

start_udp_chat_client()
