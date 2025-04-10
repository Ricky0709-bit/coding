def frequency(l):
    freq = {}
    
    for item in l:
        if item in freq:
            freq[item] += 1
        else:
            freq[item] = 1
    
    minfreq = min(freq.values())
    maxfreq = max(freq.values())
    
    minfreqlist = sorted([item for item, count in freq.items() if count == minfreq]) 
    maxfreqlist = sorted([item for item, count in freq.items() if count == maxfreq])
    
    return minfreqlist, maxfreqlist
print(frequency([13, 12, 11, 13, 14, 13, 7, 11, 13, 14, 12]))
