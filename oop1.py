"""
Object-Oriented Programming (OOP) in Python
--------------------------------------------
This file provides a comprehensive overview of OOP concepts in Python with examples and explanations.
"""

# 1️⃣ Classes and Objects
class Car:
    """A simple class representing a car."""
    
    def __init__(self, brand, model, year):
        self.brand = brand  # Public attribute
        self.model = model  # Public attribute
        self.year = year  # Public attribute
    
    def display_info(self):
        """Displays the car's details."""
        return f"{self.year} {self.brand} {self.model}"

# Creating an object (instance) of the Car class
car1 = Car("Toyota", "Corolla", 2022)
print(car1.display_info())  # Output: 2022 Toyota Corolla


# 2️⃣ Encapsulation (Using Private Attributes)
class BankAccount:
    """A class representing a bank account with encapsulation."""
    
    def __init__(self, owner, balance):
        self.owner = owner
        self.__balance = balance  # Private attribute
    
    def deposit(self, amount):
        """Deposits money into the account."""
        if amount > 0:
            self.__balance += amount
    
    def withdraw(self, amount):
        """Withdraws money from the account if funds are sufficient."""
        if 0 < amount <= self.__balance:
            self.__balance -= amount
        else:
            print("Insufficient funds")
    
    def get_balance(self):
        """Returns the current balance (read-only)."""
        return self.__balance

# Creating a bank account
account = BankAccount("Alice", 1000)
account.deposit(500)
account.withdraw(300)
print(account.get_balance())  # Output: 1200

# account.__balance  # This will raise an AttributeError


# 3️⃣ Inheritance
class ElectricCar(Car):
    """A subclass of Car that represents an electric vehicle."""
    
    def __init__(self, brand, model, year, battery_size):
        super().__init__(brand, model, year)  # Call the parent constructor
        self.battery_size = battery_size
    
    def battery_info(self):
        return f"Battery size: {self.battery_size} kWh"

# Creating an instance of ElectricCar
e_car = ElectricCar("Tesla", "Model S", 2023, 100)
print(e_car.display_info())  # Output: 2023 Tesla Model S
print(e_car.battery_info())  # Output: Battery size: 100 kWh


# 4️⃣ Polymorphism
class Animal:
    """A base class for different animals."""
    def speak(self):
        raise NotImplementedError("Subclass must implement abstract method")

class Dog(Animal):
    def speak(self):
        return "Woof!"

class Cat(Animal):
    def speak(self):
        return "Meow!"

# Using polymorphism
animals = [Dog(), Cat()]
for animal in animals:
    print(animal.speak())  # Output: Woof! Meow!


# 5️⃣ Abstraction
from abc import ABC, abstractmethod

class Shape(ABC):
    """Abstract base class for shapes."""
    @abstractmethod
    def area(self):
        pass
    
class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return 3.1416 * self.radius * self.radius

# circle = Shape()  # This will raise an error (can't instantiate an abstract class)
circle = Circle(5)
print(circle.area())  # Output: 78.54
