def convert_to_decimal(number, base):
    return int(number, base)


number = '3AF'  
base = 16
decimal_number = convert_to_decimal(number, base)
print(f"The decimal representation of {number} in base {base} is {decimal_number}")
