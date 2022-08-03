#****************************************************************************************************
#
#       Name:       Alex Orescanin
#       File:       customer.py
#       Description:
#           This program holds the class Customer, which is subclass of Person
#
#       Other files included: store.py, person.py, sales_associate.py
#
#****************************************************************************************************

import person

#****************************************************************************************************

class Customer(person.Person):

    def __init__(self, name, phone, number, mailingList):
        person.Person.__init__(self, name, phone)
        self.__number = number
        self.__mailingList = mailingList

# ****************************************************************************************************

    def set_number(self, number):
        self.__number = number

# ****************************************************************************************************

    def get_number(self):
        return self.__number

# ****************************************************************************************************

    def set_mailingList(self, mailingList):
        self.__mailingList = mailingList

# ****************************************************************************************************

    def get_mailingList(self):
        return self.__mailingList

# ****************************************************************************************************

    def __str__(self):
        if self.__mailingList == True:
            result = self.get_name() + ' ' + self.get_phone() + ' ' + \
                     self.get_number() + ' on mailing list' + '\n'
        else:
            result = self.get_name() + ' ' + self.get_phone() + ' ' + \
                     self.get_number() + ' not on mailing list' + '\n'

        return result