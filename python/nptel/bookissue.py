books = {}
borrowers = {}
checkouts = []

current_section = None

while True:
    line = input().strip()
    
    if line == "Books":
        current_section = "Books"
    elif line == "Borrowers":
        current_section = "Borrowers"
    elif line == "Checkouts":
        current_section = "Checkouts"
    elif line == "EndOfInput":
        break
    else:
        if current_section == "Books":
            accession_number, title = line.split('~')
            books[accession_number] = title
        elif current_section == "Borrowers":
            username, full_name = line.split('~')
            borrowers[username] = full_name
        elif current_section == "Checkouts":
            username, accession_number, due_date = line.split('~')
            checkouts.append((due_date, borrowers[username], accession_number, books[accession_number]))

sorted_checkouts = sorted(checkouts, key=lambda x: (x[0], x[1], x[2]))


for checkout in sorted_checkouts:
    print("~".join(checkout))
