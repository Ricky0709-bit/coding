def sumprimes(l):
    def is_prime(n):
        if n < 2:
           return False
        for i in range(2, int(n**0.5)+1):
            if n % i == 0:
                return False
        return True
    
    return sum(x for x in l if is_prime(x))
    
print(sumprimes([-3,1,6]))