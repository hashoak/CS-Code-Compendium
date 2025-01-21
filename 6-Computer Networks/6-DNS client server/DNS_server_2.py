import socket

DNS_RECORDS = {
    '192.168.0.1':'example.com',
    '127.0.0.1':'localhost',
    '8.8.8.8':'google.com',
}

def resolve_ip_address(ip_address):
    if ip_address in DNS_RECORDS:
        return DNS_RECORDS[ip_address]
    else:
        return None

def start_dns_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 53))

    print('DNS server started. Listening on port 53...')

    while True:
        data, address = server_socket.recvfrom(1024)
        ip_address = data.decode('utf-8').strip()
        hostname = resolve_ip_address(ip_address)
        print(f"{address} requested for {ip_address}")

        if hostname:
            print(f"ip_address '{ip_address}' found")
            response = hostname.encode('utf-8')
        else:
            print(f"ip_address '{ip_address}' not found")
            response = 'not found'.encode('utf-8')

        server_socket.sendto(response, address)

start_dns_server()
