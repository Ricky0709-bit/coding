def leftrotate(m):
    transpose = [[m[j][i] for j in range(len(m))] for i in range(len(m[0]))]
    rotate = transpose[::-1]
    return rotate

print(leftrotate([[1,2],[3,4]]))
print(leftrotate([[1,2,3],[4,5,6],[7,8,9]]))
print(leftrotate([[1,1,1],[2,2,2],[3,3,3]]))