#****************************************************************************************************
#
#       Name:       Alex Orescanin
#       File:       store.py
#       Description:
#               This program holds the main function and display the dictionary
#
#       Other files included: person.py, customer.py, sales_associate.py
#
#****************************************************************************************************

import customer
import sales_associate

#****************************************************************************************************

def main():
    associate1 = sales_associate.SalesAssociate('Jane', '123-987', 'A905', '8.7')
    associate2 = sales_associate.SalesAssociate('John', '905-437', 'X337', '9.5')
    associate3 = sales_associate.SalesAssociate('Joe', '314-636', 'B522', '10.7')
    customer1 = customer.Customer('Mary', '909-457', 'C921', True)
    customer2 = customer.Customer('Mike', '415-678', 'C100', False)
    customer3 = customer.Customer('Moe', '897-909', 'C607', True)
    storeDict = {associate1: customer1, associate2: customer2, associate3: customer3}

    print('All sales:')
    print('*' * 50)
    for key in storeDict.keys():
        print(key)

    print('\nAll customers')
    print('*' * 50)
    for value in storeDict.values():
        print(value)

    print('\nSales\tCustomers:')
    print('*' * 50)
    for key, value in storeDict.items():
        print(f"{key.get_name() : <10}", value.get_name())

#****************************************************************************************************

if __name__ == '__main__':
    main()

#****************************************************************************************************
# Sample Output:
# All sales:
# **************************************************
# Jane 123-987 A905 8.7
#
# John 905-437 X337 9.5
#
# Joe 314-636 B522 10.7
#
#
# All customers
# **************************************************
# Mary 909-457 C921 on mailing list
#
# Mike 415-678 C100 not on mailing list
#
# Moe 897-909 C607 on mailing list
#
#
# Sales	Customers:
# **************************************************
# Jane       Mary
# John       Mike
# Joe        Moe
#
# Process finished with exit code 0
#****************************************************************************************************
