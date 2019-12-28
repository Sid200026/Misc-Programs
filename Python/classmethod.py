class Network:
    name = "Siddharth"

    def print_name(self):
        print(f"Hi I am, {self.name}")

net = Network()
net.print_name()
# This raises an error since print_name can be accessed only via the class instance
# Network.print_name()

class Network1:
    name = "Siddharth"

    @classmethod
    # cls is a class parameter that points to the class and not to the object of the class ( self )
    def print_name(cls):
        print(f"Hi I am, {cls.name}")

net = Network1()
net.print_name()
Network1.print_name()

# A class method takes cls as first parameter while a static method needs no specific parameters.

# A class method can access or modify class state while a static method can’t access or modify it.

# In general, static methods know nothing about class state. They are utility type methods
#  that take some parameters and work upon those parameters. On the other hand class methods
#  must have class as parameter