def validate_ipv4_address(ip_address):
    parts=ip_address.split('.')
    if len(parts)!=4:
        return False
    for part in parts:
        if not part.isdigit() or int(part)<0 or int(part)>255:
            return False
    return True

def identify_ip_class(ip_address):
    first_octet=int(ip_address.split('.')[0])
    if first_octet>=1 and first_octet<=126:
        return 'Class A'
    elif first_octet>=128 and first_octet<=191:
        return 'Class B'
    elif first_octet>=192 and first_octet<=223:
        return 'Class C'
    else:
        return 'Not Class A, B, or C'

def extract_network_host_id(ip_address,subnet_mask):
    ip_parts=ip_address.split('.')
    mask_parts=subnet_mask.split('.')

    network_parts=[]
    host_parts=[]
    for i in range(4):
        network_parts.append(str(int(ip_parts[i]) & int(mask_parts[i])))
        host_parts.append(str(int(ip_parts[i]) & (255-int(mask_parts[i]))))

    network_id='.'.join(network_parts)
    host_id='.'.join(host_parts)
    return network_id,host_id

ip_address=input("Enter IPv4 address: ")

if not validate_ipv4_address(ip_address):
    print("Invalid IPv4 address!")
else:
    print("Valid IPv4 address.")

    ip_class=identify_ip_class(ip_address)
    print("IP Class:",ip_class)

    if ip_class in ['Class A','Class B','Class C']:
        subnet_mask='255.0.0.0' if ip_class == 'Class A' else ('255.255.0.0' if ip_class == 'Class B' else '255.255.255.0')
        network_id,host_id=extract_network_host_id(ip_address,subnet_mask)
        print("Network ID (Binary):",'.'.join(format(int(x),'08b') for x in network_id.split('.')))
        print("Network ID (Dotted Decimal):",network_id)
        print("Host ID (Binary):",'.'.join(format(int(x),'08b') for x in host_id.split('.')))
        print("Host ID (Dotted Decimal):",host_id)
