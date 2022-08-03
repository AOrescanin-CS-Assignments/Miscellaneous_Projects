#****************************************************************************************************
#
#       Name:       Alex Orescanin
#       File:       sales_associate.py
#       Description:
#           This program holds the class SalesAssociate, which is subclass of Person
#
#       Other files included: store.py, customer.py, person.py
#
#****************************************************************************************************

import person

#****************************************************************************************************

class SalesAssociate(person.Person):

    def __init__(self, name, phone, ID, commission):
        person.Person.__init__(self, name, phone)
        self.__ID = ID
        self.__commission = commission

# ****************************************************************************************************

    def set_ID(self, ID):
        self.__ID = ID

# ****************************************************************************************************

    def get_ID(self):
        return self.__ID

# ****************************************************************************************************

    def set_commission(self, commission):
        self.__commission = commission

# ****************************************************************************************************

    def get_commission(self):
        return self.__commission

# ****************************************************************************************************

    def __str__(self):
        return self.get_name() + ' ' + self.get_phone() + ' ' + \
               self.get_ID()+ ' ' + self.get_commission() + '\n'