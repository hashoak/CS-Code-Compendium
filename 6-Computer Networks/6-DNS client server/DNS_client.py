import socket

def resolve_dns(hostname):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 53)

    client_socket.sendto(hostname.encode('utf-8'), server_address)
    ip_address, _ = client_socket.recvfrom(1024)

    return ip_address.decode('utf-8')

hostname = input('Enter the hostname to resolve: ')
ip_address = resolve_dns(hostname)
print(f'The Hostname of {hostname} is {ip_address}')
