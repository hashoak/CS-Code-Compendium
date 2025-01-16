import socket

def start_udp_file_client():
    server_address = ('localhost', 8000)
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    file_name = input('Enter the file name: ')
    client_socket.sendto(file_name.encode('utf-8'), server_address)

    data, server_address = client_socket.recvfrom(1024)

    if data:
        print("Data in the file:")
        print(data.decode('utf-8'))
        with open("recieved"+file_name, 'wb') as file:
            file.write(data)
        print('File transfer completed successfully.')
    else:
        print(f'Error: File "{file_name}" not found.')

    client_socket.close()

start_udp_file_client()
