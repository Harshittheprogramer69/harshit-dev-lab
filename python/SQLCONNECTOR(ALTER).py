import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="harshit2006",
    database="HARSHIT"
)

cur = mydb.cursor()

def Alter():
    table_name = input("Enter the table name you want to alter:- ")
    
    try:
        cur.execute(f"DESCRIBE {table_name}")
        
        columns = cur.fetchall()

        column_name = input("Enter column name you want to modify:- ") #Name column
        column_type = input("Enter column type you want to change:- ") #new Type
        SQL = f"ALTER TABLE {table_name} MODIFY COLUMN {column_name} {column_type}"
        cur.execute(SQL)
        mydb.commit()
        print(f"Column {column_name} in table {table_name} has been altered to {column_type} successfully!")
    except mysql.connector.Error as err:
        print(f"Error: {err}")

Alter()

cur.close()

mydb.close()   