def max_marks(N, K, marks):
    max_sum_prev = [-float('inf')] * (K + 1)
    max_sum_curr = [-float('inf')] * (K + 1)
    
   
    for j in range(K + 1):
        max_sum_prev[j] = 0
    
    total = -float('inf')  
    for i in range(1, N + 1):
        for j in range(K + 1):
            max_sum_curr[j] = max(max_sum_prev[j] + marks[i - 1], marks[i - 1])
            
            if j > 0:
                max_sum_curr[j] = max(max_sum_curr[j], max_sum_prev[j - 1])
            
            total = max(total, max_sum_curr[j])
        
        max_sum_prev, max_sum_curr = max_sum_curr, max_sum_prev
    
    return total

N, K = map(int, input().split())  
marks = [int(input()) for _ in range(N)]  

print(max_marks(N, K, marks))
