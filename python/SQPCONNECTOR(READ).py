import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="harshit2006",
    database="harshit"
)

cur = mydb.cursor()

def read():
    try:
        cur.execute("SHOW TABLES")
        tables = cur.fetchall()
        print("Availables tables in database are:-")
        for table in tables:
            print(tables[0])
        
        table_name=input("Enter the table name you want to read:- ")
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
