a, b = 2, 3
P = 67
E1 = (2, 22)
d = 4

def point_addition(p1, p2):
    if p1 == "O":
        return p2
    if p2 == "O":
        return p1

    x1, y1 = p1
    x2, y2 = p2

    if x1 == x2 and y1 == -y2 % P:
        return "O"

    if p1 == p2:
        m = (3 * x1 * x1 + a) * pow(2 * y1, -1, P) % P
    else:
        m = (y2 - y1) * pow(x2 - x1, -1, P) % P

    x3 = (m * m - x1 - x2) % P
    y3 = (m * (x1 - x3) - y1) % P

    return (x3, y3)

def scalar_multiplication(k, p):
    result = "O"
    while k > 0:
        if k % 2 == 1:
            result = point_addition(result, p)
        p = point_addition(p, p)
        k = k // 2
    return result

def generate_key():
    return scalar_multiplication(d, E1)

def encrypt(plaintext,public_key):
    r = 2
    C1 = scalar_multiplication(r, E1)
    C2 = point_addition(plaintext,scalar_multiplication(r, public_key))
    return (C1, C2)

def point_negation(p):
    if p == "O":
        return "O"
    x, y = p
    return (x, -y % P)

def decrypt(ciphertext):
    shared_secret = scalar_multiplication(d, ciphertext[0])
    plaintext_point = point_addition(ciphertext[1], point_negation(shared_secret))
    return plaintext_point

print("Enter the plaintext:")
plaintext = (int(input("x: ")),int(input("y: ")))
E2=generate_key()

ciphertext = encrypt(plaintext,E2)
print("Ciphertext (C1,C2):", ciphertext)

decrypted_plaintext = decrypt(ciphertext)
print("Decrypted plaintext:", decrypted_plaintext)
