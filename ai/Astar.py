import heapq

goal_positions = {}
def heuristic_distance(state, goal):
    distance = 0
    for i, val in enumerate(state):
        if val != 0:
            goal_i = goal_positions[val]
            distance += abs(i // 3 - goal_i // 3) + abs(i % 3 - goal_i % 3)
    return distance

def get_neighbors(state):
    neighbors = []
    i = state.index(0)
    x, y = divmod(i, 3)
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for dx, dy in moves:
        nx, ny = x + dx, y + dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_i = nx * 3 + ny
            new_state = list(state)
            new_state[i], new_state[new_i] = new_state[new_i], new_state[i]
            neighbors.append(tuple(new_state))
    return neighbors

def reconstruct_path(came_from, current):
    path = []
    while current in came_from:
        path.append(current)
        current = came_from[current]
    path.reverse()
    return path

def a_star(start, goal):
    open_set = []
    heapq.heappush(open_set, (0, start))
    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic_distance(start, goal)}

    while open_set:
        _, current = heapq.heappop(open_set)
        if current == goal:
            return reconstruct_path(came_from, current)
        for neighbor in get_neighbors(list(current)):
            tentative_g = g_score[current] + 1
            if tentative_g < g_score.get(neighbor, float("inf")):
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score[neighbor] = tentative_g + heuristic_distance(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))
    return None

if __name__ == "__main__":
    print("Enter initial state (row-wise, use 0 for blank):")
    start = tuple(map(int, input().split()))
    print("Enter goal state (row-wise, use 0 for blank):")
    goal = tuple(map(int, input().split()))

    for i, val in enumerate(goal):
        goal_positions[val] = i

    solution = a_star(start, goal)

    if solution:
        print(f"\nSolution found in {len(solution)} moves:")
        for step in solution:
            for i in range(0, 9, 3):
                print(step[i:i+3])
            print()
    else:
        print("No solution found.")
