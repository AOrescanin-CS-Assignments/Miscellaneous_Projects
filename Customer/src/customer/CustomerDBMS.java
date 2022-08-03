//***************************************************************************************************** 
// 
//          File:                   CustomerDBMS.java
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
//          This houses the CustomerDBMS class
// 
//          Other files required:  Assignment12.java
//                                  
// 
//*****************************************************************************************************

package customer;

//*****************************************************************************************************

import java.sql.*;

//*****************************************************************************************************//

public class CustomerDBMS 
{
    final String DB_URL = "jdbc:derby://localhost:1527/CoffeeDB;create=true";
    private Connection conn;
    private Statement stmt;
    private String SQLQuery;
    
//*****************************************************************************************************
    
    public CustomerDBMS() throws SQLException
    {
        conn = DriverManager.getConnection(DB_URL);
        stmt = conn.createStatement();
        SQLQuery = " ";
    }
    
//*****************************************************************************************************
    
    public void displayTable()
    {
        try
        {
            SQLQuery = "SELECT * "
                     + "FROM Customer";
            ResultSet result = stmt.executeQuery(SQLQuery);
            
            System.out.println("All Customers");
            
            for(int i = 0; i < 99; i++)
            {
                System.out.print('-');
            }
            
            System.out.println();
            
            while(result.next())
            {
                System.out.printf("%9s %9s %9s %9s %9s %9s\n",
                                  result.getString("CustomerNumber"),
                                  result.getString("Name"),
                                  result.getString("Address"),
                                  result.getString("City"),
                                  result.getString("State"),
                                  result.getString("Zip"));
            }
            
            for(int i = 0; i < 99; i++)
            {
                System.out.print('-');
            }
            
            System.out.println();
        }
        catch(SQLException e)
        {
            System.out.println(e);
        }
    }
    
//*****************************************************************************************************
    
    public void insert (String customerNum, String customerName, String address, 
                        String city, String state, String zip)
    {
        try
        {
            SQLQuery = "INSERT INTO Customer (CustomerNumber, Name, Address, City, State, Zip) "
                       + "VALUES ('" + customerNum + "',"
                                + " '" + customerName + "',"
                                + " '" + address + "',"
                                + " '" + city + "',"
                                + " '" + state + "',"
                                + " '" + zip + "')";
            stmt.executeUpdate(SQLQuery);               
        }
        catch(SQLException e)
        {
            System.out.println(e);
        }
    }
    
//*****************************************************************************************************
    
    public void delete(String customerNum)
    {
        try
        {
            SQLQuery = "DELETE FROM Customer "
                     + "WHERE CustomerNumber = '" + customerNum +"'"; 
            stmt.executeUpdate(SQLQuery);
        }
        catch(SQLException e)
        {
            System.out.println(e);
        }
    }
    
//*****************************************************************************************************
    
    public int count()
    {
        int count = 0;
        
        try
        {
            SQLQuery = "SELECT COUNT(*) "
                     + "FROM Customer";
            ResultSet result = stmt.executeQuery(SQLQuery);
            result.next();
            count = result.getInt(1);
        }
        catch(SQLException e)
        {
            System.out.println(e);
        }
        
        return count;
    }
}
