def contracting(l):
    
    if len(l) < 2:
        return False
    diff = l[0] - l[1]
    for i in range(1,len(l)-1):
        new_diff =l[i] - l[i+1]
        if new_diff >= diff:
           return False
        diff = new_diff
        return True
    
print(contracting([9,2,7,3,1]))
print(contracting([-2,3,7,2,-1]))
print(contracting([10,7,4,1]))