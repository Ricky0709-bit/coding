#9: Display the name of engineers who also serving as managers.

engineers = ["John Doe", "Jane Smith", "Mark Johnson", "Alice Johnson"]
managers = ["Jane Smith", "Mark Johnson"]

print("Engineers who also serve as managers:")

for engineer in engineers:
    if engineer in managers:
        print(engineer)
        