import mysql.connector as c

mydb = c.connect(
    host = "localhost",
    user = 'root',
    password = 'harshit2006',
    database = "Connector"
)

cur = mydb.cursor()

cur.execute("SHOW TABLES")

for i in cur.fetchall():
    print(i[0])

table = input("Enter which table data you want to see:- ")

query = "SELECT * FROM %s" % table

cur.execute(query)

for i in cur.fetchall():
    print(i)

mydb.close()