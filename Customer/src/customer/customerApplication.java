//***************************************************************************************************** 
// 
//          File:                   Assignment12.java
// 
//          Student:                Alex Orescanin
// 
//          Assignment:             Assingment 12
// 
//          Course Name:            Java I 
// 
//          Course Number:          COSC 2050 -01 
// 
//          Due:                    May 5th, 2021 
// 
// 
//          This houses the main function
// 
//          Other files required:  CustomerDBMS.java
//                                  
// 
//*****************************************************************************************************

package customer;

//*****************************************************************************************************

import java.util.Scanner;
import java.sql.*;

//*****************************************************************************************************

public class customerApplication 
{

    public static void main(String[] args) throws SQLException
    {
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        CustomerDBMS cust = new CustomerDBMS();
        String customerNum,
                customerName,
                address,
                city,
                state,
                zip;
        
        while (choice != 4)
        {
            for(int i = 0; i < 99; i++)
            {
                System.out.print('*');
            }
            System.out.println("\n1. View all customer information");
            System.out.println("2. Insert a customer");
            System.out.println("3. Delete a customer's infromation");
            System.out.println("4. Quit");
            System.out.println("Enter a choice: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            if(choice == 1)
            {
                cust.displayTable();
            }
            else if(choice == 2)
            {
                System.out.print("Customer number: ");
                customerNum = sc.nextLine();
                System.out.print("Customer name: ");
                customerName = sc.nextLine();
                System.out.print("Customer address: ");
                address = sc.nextLine();
                System.out.print("City: ");
                city = sc.nextLine();
                System.out.print("State: ");
                state = sc.nextLine();
                System.out.print("Zip code: ");
                zip = sc.nextLine();
                
                cust.insert(customerNum, customerName, address, city, state, zip);
            }
            else if(choice == 3)
            {
                System.out.print("Customer number: ");
                customerNum = sc.nextLine();
                
                cust.delete(customerNum);
            }
        }
        
        System.out.println("There are " + cust.count() + " Customers\nGoodbye");
    }
    
}

/******************************************************************************************************
 Sample Output:
 
***************************************************************************************************
1. View all customer information
2. Insert a customer
3. Delete a customer's infromation
4. Quit
Enter a choice: 
2
Customer number: 13245
Customer name: Garry
Customer address: Barry Street
City: Fairy City
State: MO
Zip code: 41325
***************************************************************************************************
1. View all customer information
2. Insert a customer
3. Delete a customer's infromation
4. Quit
Enter a choice: 
1
All Customers
---------------------------------------------------------------------------------------------------
101        Downtown Cafe             17 N. Main Street         Asheville           NC     55515
102        Main Street Grocery       110 E. Main Street        Canton              NC     55555
103        The Coffee Place          101 Center Plaza          Waynesville         NC     55516
369        Alex Orescanin            123 Happy Lane            St. Louis           MO     63125
13245      Garry                     Barry Street              Fairy City          MO     41325
---------------------------------------------------------------------------------------------------
***************************************************************************************************
1. View all customer information
2. Insert a customer
3. Delete a customer's infromation
4. Quit
Enter a choice: 
3
Customer number: 369
***************************************************************************************************
1. View all customer information
2. Insert a customer
3. Delete a customer's infromation
4. Quit
Enter a choice: 
4
There are 4 Customers
Goodbye

* ***************************************************************************************************/