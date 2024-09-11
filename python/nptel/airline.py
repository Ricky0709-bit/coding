def onehop(l):
    from collections import defaultdict

    adj_list = defaultdict(set)
    for i, j in l:
        adj_list[i].add(j)
    
    result = set()
    for i in adj_list:
        for k in adj_list[i]:
            if k in adj_list:  
                for j in adj_list[k]:
                    if i != j:  
                        result.add((i, j))
    
    
    sorted_result = sorted(result)
    
    return sorted_result

print(onehop([(2,3),(1,2)]))