import socket

DNS_RECORDS = {
    'example.com': '192.168.0.1',
    'localhost': '127.0.0.1',
    'google.com': '8.8.8.8',
}

def resolve_hostname(hostname):
    if hostname in DNS_RECORDS:
        return DNS_RECORDS[hostname]
    else:
        return None

def start_dns_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 53))

    print('DNS server started. Listening on port 53...')

    while True:
        data, address = server_socket.recvfrom(1024)
        hostname = data.decode('utf-8').strip()
        ip_address = resolve_hostname(hostname)
        print(f"{address} requested for {hostname}")

        if ip_address:
            print(f"hostname '{hostname}' found")
            response = ip_address.encode('utf-8')
        else:
            print(f"hostname '{hostname}' not found")
            response = 'not found'.encode('utf-8')

        server_socket.sendto(response, address)

start_dns_server()
