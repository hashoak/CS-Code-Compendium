def calculate_checksum(data):
    checksum = 0

    for word in data:
        word_int = int(word, 2)
        checksum += word_int

    checksum = (checksum & 0xFF) + (checksum >> 8)
    checksum = (~checksum) & 0xFF

    return bin(checksum)[2:].zfill(8)


def verify_checksum(data, checksum):
    calculated_checksum = 0

    for word in data:
        word_int = int(word, 2)
        calculated_checksum += word_int

    calculated_checksum += int(checksum, 2)
    calculated_checksum = (calculated_checksum & 0xFF) + (calculated_checksum >> 8)

    if (~calculated_checksum & 0xFF) == 0:
        return True
    else:
        return False
data = input("Enter the binary data (in 8-bit words): ").split()
checksum = calculate_checksum(data)
print("Checksum:", checksum)

verify = input("Enter the received binary data to verify (including checksum): ").split()
if verify_checksum(verify[:-1], verify[-1]):
    print("Checksum is valid, no error detected.")
else:
    print("Checksum is invalid, error detected.")