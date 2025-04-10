def matched(s):
    count = 0
    for i in range(0, len(s)):
        if s[i] == '(':
            count += 1
        elif s[i] == ')':
            count -= 1
        if count < 0:
            return False
    return count == 0

print(matched("(a+b) * (c+d)"))  
print(matched("((a+b) * (c+d)"))  
print(matched("(a+b)) * (c+d)"))  
print(matched("a + b"))           
print(matched("(a + (b + (c + d)))"))  