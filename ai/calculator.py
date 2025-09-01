def calculate(operation, x, y):
    if operation == "add":
        return x + y
    elif operation == "subtract":
        return x - y
    elif operation == "multiply":
        return x * y
    elif operation == "divide":
        if y == 0:
            raise ValueError("Cannot divide by zero")
        return x / y
    else:
        raise ValueError("Unknown operation")


def main():
    while True:
        print("\n--- Calculator Menu ---")
        print("1. Add")
        print("2. Subtract")
        print("3. Multiply")
        print("4. Divide")
        print("5. Exit")

        choice = input("Enter your choice (1-5): ")

        if choice == "5":
            print("Exiting calculator. Goodbye!")
            break

        try:
            x = float(input("Enter first number: "))
            y = float(input("Enter second number: "))

            if choice == "1":
                result = calculate("add", x, y)
            elif choice == "2":
                result = calculate("subtract", x, y)
            elif choice == "3":
                result = calculate("multiply", x, y)
            elif choice == "4":
                result = calculate("divide", x, y)
            else:
                print("Invalid choice! Try again.")
                continue

            print(f"Result: {result}")

        except ValueError as e:
            print("Error:", e)


if __name__ == "__main__":
    main()
