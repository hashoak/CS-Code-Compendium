def xor(a,d):
    x=""
    for i in range(0,len(a)):
        if(a[i]==d[i]): x+='0'
        else: x+='1'
    return x

def CRC(msg,div):
    lm=len(msg)
    ld=len(div)
    a=msg[0:ld]
    for i in range(0,lm-ld):
        if(a[0]=='1'): a=xor(a,div)
        a=a[1:ld]+msg[ld+1]
    a=a[1:ld]
    return a

dataword=input("DataWord: ")
divisor=input("Divisor: ")
checksum=CRC(dataword+'0'*(len(divisor)-1),divisor)
print("Checksum:",checksum)
print("CodeWord: ",dataword+checksum)

dataword=input("New DataWord: ")
error=CRC(dataword+checksum,divisor)
print("CRC calculation:",error)
if(error=='0'*len(error)): print("No error")
else: print("Error detected")