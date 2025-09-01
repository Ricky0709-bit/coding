class Bike:
    def __init__(self, name, price, mileage, type):
        self.name = name
        self.price = price
        self.mileage = mileage
        self.type = type

bikes = [
    Bike("hero", 75000, 70, "commuter"),
    Bike("bmw", 385000, 65, "sports"),
    Bike("pulsar", 105000, 50, "commuter"),
    Bike("apache", 115000, 45, "sports"),
    Bike("yamaha", 125000, 48, "commuter"),
    Bike("royal_enfield", 195000, 35, "cruiser"),
    Bike("ktm", 210000, 33, "sports")
]

def get_bike(name):
    for bike in bikes:
        if bike.name == name:
            return bike
    return None

def cheaper_bike(bike1, bike2):
    return bike1.price < bike2.price

def costlier_bike(bike1, bike2):
    return bike1.price > bike2.price

def equal_price(bike1, bike2):
    return bike1.price == bike2.price

def better_mileage(bike1, bike2):
    return bike1.mileage > bike2.mileage

def worse_mileage(bike1, bike2):
    return bike1.mileage < bike2.mileage

def same_mileage(bike1, bike2):
    return bike1.mileage == bike2.mileage

def bike_type(bike, type_):
    return bike.type == type_

b1 = get_bike("hero")
b2 = get_bike("bmw")

if b1 and b2:
    print("Cheaper:", cheaper_bike(b1, b2))          
    print("Costlier:", costlier_bike(b1, b2))       
    print("Equal Price:", equal_price(b1, b2))       
    print("Better Mileage:", better_mileage(b1, b2)) 
    print("Same Type:", bike_type(b1, "commuter"))   

