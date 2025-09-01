from kanren import Relation, facts, run, var, conde

parent = Relation()
male = Relation()
female = Relation()

facts(parent,
      ('John', 'Mary'),
      ('John', 'Tom'),
      ('Linda', 'Mary'),
      ('Linda', 'Tom')
      )

facts(male,
      ('John',),
      ('Tom',),
      )

facts(female,
      ('Mary',),
      ('Linda',),
      )

def mother(x, y):
    return conde((female(x), parent(x, y)))

def father(x, y):
    return conde((male(x), parent(x, y)))

x = var()

print("Mother of Tom:", run(1, x, mother(x, 'Tom')))
print("Father of Mary:", run(1, x, father(x, 'Mary')))
print("Children of John:", run(2, x, parent('John', x)))
print("All females in the family:", run(10, x, female(x)))
