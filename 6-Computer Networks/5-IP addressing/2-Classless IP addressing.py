def binary_to_dotted_decimal(binary):
    return '.'.join(str(int(binary[i:i+8],2)) for i in range(0,32,8))

host_ip,prefix=input("Enter IP address/Prefix: ").split('/')
prefix=int(prefix)

host_binary=''.join(format(int(x),'08b') for x in host_ip.split('.'))

num_addresses=2**(32-prefix)

subnet_binary=host_binary[:prefix]+'0'*(32-prefix)
subnet_address=binary_to_dotted_decimal(subnet_binary)

broadcast_binary=host_binary[:prefix]+'1'*(32-prefix)
broadcast_address=binary_to_dotted_decimal(broadcast_binary)

first_host_binary=host_binary[:prefix]+'0'*(32-prefix-1)+'1'
first_host_address=binary_to_dotted_decimal(first_host_binary)

last_host_binary=host_binary[:prefix]+'1'*(32-prefix-1)+'0'
last_host_address=binary_to_dotted_decimal(last_host_binary)

print("IP Address:", host_ip)
print("Number of Addresses:", num_addresses)
print("Subnet Address:", subnet_address)
print("Broadcast Address:", broadcast_address)
print("Usable Range of Host IPs:")
print("First Host:", first_host_address)
print("Last Host:", last_host_address)
