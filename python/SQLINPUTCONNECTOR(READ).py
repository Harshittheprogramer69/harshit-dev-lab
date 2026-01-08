import mysql.connector

a = input("Enter the Host to connect sql:-")
b = input("Enter the user to connect sql:-")
c = input("Enter the password to connect sql:-")
d = input("Enter the database to connect sql:-")
mydb = mysql.connector.connect(
    host=a,
    user=b,
    password=c,
    database=d
)

cur = mydb.cursor()

def read():
    table_name=input("Enter the table name you want to read:- ")

    try:
        cur.execute(f"Select * From {table_name}")
        
        columns = cur.fetchall()

        print(f"DATA in table {table_name} are:- ")
        for column in columns:
            print(column)
    
    except mysql.connector.Error as err:
        print(f"ERROR: {err}")
read()

cur.close()
mydb.close()
