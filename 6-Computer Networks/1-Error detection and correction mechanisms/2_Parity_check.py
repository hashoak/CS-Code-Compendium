def perform_parity_check(data):
    ones_count=data.count('1')

    if ones_count%2==0:
        parity_bit='0'
    else:
        parity_bit='1'

    return data+parity_bit


def detect_error(data_with_parity):
    ones_count=data_with_parity.count('1')

    if ones_count%2==0:
        return False
    else:
        return True

data=input("Enter the Data Word: ")
data_with_parity=perform_parity_check(data)
print("Data with parity bit:",data_with_parity)

code_word=input("Enter the Code Word: ")
error_detected=detect_error(code_word)
if error_detected:
    print("Error detected.")
else:
    print("No error detected.")
