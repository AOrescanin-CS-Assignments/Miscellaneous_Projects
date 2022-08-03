#****************************************************************************************************
#
#       Name:       Alex Orescanin
#       File:       person.py
#       Description:
#           This program holds the class Person
#
#       Other files included: store.py, customer.py, sales_associate.py
#
#****************************************************************************************************

class Person:

    def __init__(self, name, phone):
        self.__name = name
        self.__phone = phone

# ****************************************************************************************************

    def set_name(self, name):
        self.__name = name

# ****************************************************************************************************

    def get_name(self):
        return self.__name

# ****************************************************************************************************

    def set_phone(self, phone):
        self.__phone = phone

# ****************************************************************************************************

    def get_phone(self):
        return self.__phone