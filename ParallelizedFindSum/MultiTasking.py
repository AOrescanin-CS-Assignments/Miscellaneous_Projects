#****************************************************************************************************
#
#       Name:       Alex Orescanin
#       File:       MultiTaskin.py
#       Description:
#               This program calculates the sum of numbers using multiprocessing
#
#****************************************************************************************************

import multiprocessing

#****************************************************************************************************

def main():
    number_list = []

    print('Enter 10 values:')

    for i in range(10):

        num = int(input(' '))
        number_list.append(num)

    p1 = multiprocessing.Process(target=print_star, args=(10,))
    p2 = multiprocessing.Process(target=calc_sum, args=(number_list, ))
    p3 = multiprocessing.Process(target=display_nums, args=(number_list,))

    p1.start()
    p2.start()
    p3.start()

    p1.join()
    p2.join()
    p3.join()

    print('Done!')

#****************************************************************************************************

def print_star(num):
    print('*' * num)

#****************************************************************************************************

def calc_sum(number_list):
    sum = 0

    for i in range(len(number_list)):
        sum += number_list[i]

    print('sum is ', sum)

#****************************************************************************************************

def display_nums(number_list):
    print('all numbers:')

    print(number_list)

#****************************************************************************************************

if __name__ == "__main__":
    main()