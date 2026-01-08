import mysql.connector

connection = mysql.connector.connect(
    host="localhost",  
    user="root",  
    password="Pencil",  
    database="ITEMDB"  
)

cur = connection.cursor()

def AddAndDisplay():
    itemNO = int(input("Enter the itemno:- "))
    itemName = input("Enter Item name:- ")
    price = float(input("Enter the price of item:- "))
    qty = int(input("Enter the quantity:- "))
    query = "INSERT INTO STATIONREY VALUES(%s,%s,%s,%s)"
    cur.execute(query, (itemNO, itemName, price, qty))
    connection.commit()
    cur.execute("SELECT * FROM STATIONERY WHERE price > 120")
    records = cur.fetchall()
    if records:
        print("Items greater then price of 120:- ")
        for record in records:
            print(record)
    
AddAndDisplay()

cur.close()
connection.close()