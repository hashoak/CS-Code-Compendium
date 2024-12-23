def generate_hamming_code(data):
    r=0
    while 2**r<len(data)+r+1:
        r+=1

    hamming_code=[None]*(len(data)+r)

    j=0
    for i in range(len(hamming_code)):
        if i+1 in [2**x for x in range(r)]:
            hamming_code[i]=0
        else:
            hamming_code[i]=int(data[j])
            j+=1

    for i in range(r):
        position=2**i-1
        count=0
        for j in range(position,len(hamming_code),2*position+2):
            for k in range(j,j+position+1):
                if k<len(hamming_code):
                    count+=hamming_code[k]
        hamming_code[position]=count%2

    return hamming_code


def detect_error(hamming_code):
    r=0
    while 2**r<len(hamming_code):
        r+=1

    error_position=0
    for i in range(r):
        position=2**i-1
        count=0
        for j in range(position,len(hamming_code),2*position+2):
            for k in range(j,j+position+1):
                if k<len(hamming_code):
                    count+=hamming_code[k]
        if count%2!=0:
            error_position+=position

    return error_position


def correct_error(hamming_code,error_position):
    if error_position!=0:
        hamming_code[error_position-1]=1-hamming_code[error_position-1]

    return hamming_code

data=input("Enter the Data Word: ")
hamming_code=generate_hamming_code(data)
print("Original Hamming code:",hamming_code)

hamming_code[1]=0

error_position=detect_error(hamming_code)
print("Detected error at position:",error_position)

corrected_code=correct_error(hamming_code,error_position)
print("Corrected Hamming code:",corrected_code)
