import mysql.connector

# Connect to the database
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="harshit2006",
    database="Connector"
)

cur = mydb.cursor()

def CreateTable():
    Table_name = input("Enter table name: ")  # Get table name
    num_columns = int(input("Enter how many columns you want to add: "))  # Get the number of columns

    columns = []  # Initialize the columns list
    for i in range(num_columns):
        column_name = input(f"Enter the name of column {i+1}: ")  # Column name
        column_type = input(f"Enter the type of column {i+1}: ")  # Column type
        columns.append(f"`{column_name}` {column_type}")  # Add backticks around column names

    primary_key = input("Enter the name of the column to set as the primary key: ")  # Get primary key

    # Build the CREATE TABLE query
    create_query = f"CREATE TABLE `{Table_name}` ("  # Add backticks around table name
    create_query += ", ".join(columns)  # Add the columns to the query
    create_query += f", PRIMARY KEY (`{primary_key}`))"  # Add primary key with backticks

    try:
        cur.execute(create_query)  # Execute the query
        print(f"Table `{Table_name}` has been created.")  # Print the success message with formatted table name
    except mysql.connector.Error as err:
        print(f"Error: {err}")  # Handle errors

# Call the function
CreateTable()

# Close the cursor and connection
cur.close()
mydb.close()
