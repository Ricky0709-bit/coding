def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def mod_inverse(e, phi):
    for d in range(1, phi):
        if (e * d) % phi == 1:
            return d
    return None

def rsa_keygen(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    e = 17  
    while gcd(e, phi) != 1:
        e += 2
    
    d = mod_inverse(e, phi)
    
    return (e, n), (d, n)

def encrypt(M, e, n):
    return pow(M, e, n)

def decrypt(C, d, n):
    return pow(C, d, n)

p = 61
q = 53

public_key, private_key = rsa_keygen(p, q)

print(f"Public Key: {public_key}")
print(f"Private Key: {private_key}")

M = 123

C = encrypt(M, public_key[0], public_key[1])
print(f"Encrypted Message: {C}")

decrypted_message = decrypt(C, private_key[0], private_key[1])
print(f"Decrypted Message: {decrypted_message}")
