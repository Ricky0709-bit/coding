def water_jug_dfs(jug1, jug2, target, x=0, y=0, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []

    if x == target or y == target:
        print("Solution found! Steps:")
        for step in path + [(x, y)]:
            print(step)
        return True

    if (x, y) in visited:
        return False
    visited.add((x, y))

    next_states = [
        (jug1, y),  
        (x, jug2),  
        (0, y),     
        (x, 0),     
        (max(0, x + y - jug2), min(jug2, x + y)),  
        (min(jug1, x + y), max(0, x + y - jug1))   
    ]

    for state in next_states:
        if state not in visited:
            if water_jug_dfs(jug1, jug2, target, state[0], state[1], visited, path + [(x, y)]):
                return True

    return False

if __name__ == "__main__":
    jug1_capacity = int(input("Enter Jug 1 capacity: "))
    jug2_capacity = int(input("Enter Jug 2 capacity: "))
    target_amount = int(input("Enter target amount: "))

    print(f"Jug 1 Capacity: {jug1_capacity}, Jug 2 Capacity: {jug2_capacity}, Target Amount: {target_amount}")
    if not water_jug_dfs(jug1_capacity, jug2_capacity, target_amount):
        print("No solution found.")