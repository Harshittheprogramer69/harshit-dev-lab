import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user='root',
    password='harshit2006',
    database='harshit'
)

cur = mydb.cursor()
def Update():
    try:
        table_name = input("Enter table name:- ")
        read = f"Select * from {table_name}"
        cur.execute(read)

        results = cur.fetchall()
        print(f"Current data in Table {table_name}:- ")
        for row in results:
            print(row)

        
        column = input(f"Which column you want to update in table name:- ")
        data_update = input(f"Update data that we want to add in column {column}")
        column_verfication = input(f"Which column in {table_name} you would chose to verify the data:- ")
        verify = input(f"verification to update the {column} in {table_name}:-")
        query = f"UPDATE {table_name} SET {column} = %s WHERE {column_verfication} = %s"
        
        cur.execute(query ,(data_update, verify))
        mydb.commit()

        print(f"Column {column} is update with data {data_update} where {column_verfication} is {verify}")

    except mysql.connector.Error as err:
        print(f"Error : {err}")
    except Exception as e:
        print(f"Unexecpeted error: {e}")
Update()

cur.close()
mydb.close()