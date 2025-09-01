from collections import deque

def is_visited(state, visited):
    return state in visited

def water_jug_bfs(jug1, jug2, target):
    start = (0, 0)
    visited = set()
    queue = deque([(start, [])])

    while queue:
        (x, y), path = queue.popleft()
        if x == target or y == target:
            print("Solution found! Steps:")
            for step in path + [(x, y)]:
                print(step)
            return True

        if is_visited((x, y), visited):
            continue
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
            if not is_visited(state, visited):
                queue.append((state, path + [(x, y)]))

    print("No solution found.")
    return False

if __name__ == "__main__":
    jug1_capacity = int(input("Enter Jug 1 capacity: "))
    jug2_capacity = int(input("Enter Jug 2 capacity: "))
    target_amount = int(input("Enter target amount: "))

    print(f"Jug 1 Capacity: {jug1_capacity}, Jug 2 Capacity: {jug2_capacity}, Target Amount: {target_amount}")
    water_jug_bfs(jug1_capacity, jug2_capacity, target_amount)
