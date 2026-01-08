import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="harshit2006",
    database="Connector"
)

cur = mydb.cursor()

def CreateTable():
    Table_name = input("Enter table name: ")  
    num_columns = int(input("Enter how many columns you want to add: "))  

    columns = []  
    for i in range(num_columns):
        column_name = input(f"Enter the name of column {i+1}: ")  
        column_type = input(f"Enter the type of column {i+1}: ")  
        columns.append(f"`{column_name}` {column_type}")  

    primary_key = input("Enter the name of the column to set as the primary key: ")  

    create_query = f"CREATE TABLE `{Table_name}` ("  
    create_query += ", ".join(columns)  
    create_query += f", PRIMARY KEY (`{primary_key}`))"  

    try:
        cur.execute(create_query)  
        print(f"Table `{Table_name}` has been created.")  
    except mysql.connector.Error as err:
        print(f"Error: {err}")  

CreateTable()

cur.close()
mydb.close()
