import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user='root',
    password='harshit2006'
)

cur = mydb.cursor()
cur.execute("SHOW DATABASES")
print("Existing databases:")
for db in cur:
    print(db[0])

database = input("Enter the name for new database:- ")

if database == ' ':
    print("NO database has been created")
else:
    SQL = "CREATE DATABASE %s" % database 
    cur.execute(SQL)

    cur.execute("SHOW DATABASES")
    print("Existing databases:")
    for db in cur:
        print(db[0])

cur.close()
mydb.close()
