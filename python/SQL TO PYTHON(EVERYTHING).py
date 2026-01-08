from getpass import getpass
from getpass import getuser

User = getuser()
password = getpass("Enter password to connect mysql to python :----")

import mysql.connector

db = mysql.connector.connect(
    host = "localhost",
    user = User,
    password = password
)
cur = db.cursor()

def show_databases():
    cur.execute("SHOW DATABASES")
    data = cur.fetchall()
    for i in data:
        print(i[0])
show_databases()

def CreateDatabase():
    Database = input("Enter name for new database:- ")
    query = "CREATE DATABASE %s" % Database
    cur.execute(query)
    print("Your Database with name %s has been added to MySQL with the help of MY sql Connectivty program" % Database)

def CreateTable():
    try:
        Table_name = input("Enter Table Name:- ")
        if not Table_name:
            raise ValueError("Table name cannot be empty.")
        num_columns = int(input("Enter How many columns you want to add :--- "))
        if num_columns <= 0:
            raise ValueError("Number of columns must be greater then 0.")
        elif not num_columns:
            raise ValueError("Number of columns cant be left empty.")
        
        columns = []
        for i in range(num_columns):
            column_name = input("Enter column %d name for table %s:- " % (i+1, Table_name))
            if not column_name:
                raise ValueError("Column name cant be left Empty.")
            column_type = input("Enter column %d type for table %s:- " % (i+1, Table_name))
            if not column_type:
                raise ValueError("Column type cant be left Empty.")
            columns.append(f"`{column_name}` {column_type}")

        primary_key = input("Enter the name of the column to set as the primary Key:-  ")
        if not primary_key:
            raise ValueError("Primary key cant be left empty.")

        create_query = f"CREATE TABLE `{Table_name}` ("
        create_query += f", ".join(columns)
        create_query += f", PRIMARY KEY (`{primary_key}`))"

        cur.execute(create_query)
        print(f"Table {Table_name} Has been created.")
    
    except ValueError as ve:
        print(f"Error:- {ve}")
    except mysql.connector.Error as err:
        print(f"Error:- {err}")
    except Exception as e:
        print(f"Error:- {e}")

