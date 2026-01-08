import mysql.connector

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="harshit2006",
    database="connector"
)

cur = mydb.cursor()
def InsertVALUES():
    table_name=input("Enter the table name you want to add values in:- ")

    cur.execute(f"DESCRIBE {table_name}")
    columns = [col[0] for col in cur.fetchall()]

    print(f"Columns in {table_name}: {', '.join(columns)}")

    values = []
    for col in columns:
        value = input(f"Enter the value for {col}: ")
        values.append(value)
    
    placeholders = ", ".join(["%s"] * len(columns))
    insert_query = f"INSERT INTO {table_name} ({', '.join(columns)}) VALUES ({placeholders})"

    try:
        cur.execute(insert_query, tuple(values))
        mydb.commit()
        print(f"Values inserted succcessfully into `{table_name}`.")
    except mysql.connector.Error as err:
        print(f"Error: {err}")

InsertVALUES()

cur.close()
mydb.close()