def extended_gcd(a, b):
    x0, x1, y0, y1 = 1, 0, 0, 1
    while b != 0:
        q = a // b
        a, b = b, a % b
        x0, x1 = x1, x0 - q * x1
        y0, y1 = y1, y0 - q * y1
    return a, x0, y0  

def modular_inverse(a, b):
    gcd_val, x, _ = extended_gcd(a, b)
    if gcd_val != 1:
        return None  
    return x % b  
a = int(input("Enter the value of a:"))
b = int(input("Enter the value of b:"))
gcd_val, x, y = extended_gcd(a, b)
mod_inv = modular_inverse(a, b)

print(f"GCD of {a} and {b} is: {gcd_val}")
print(f"Modular inverse of {a} mod {b} is: {mod_inv}")
