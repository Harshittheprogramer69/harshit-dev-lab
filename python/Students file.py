from getpass import getpass, getuser

username = getuser()  # Gets the system username
password = getpass("Enter your password: ")  # Hides input for security

if username == password:
    print("Login successfully")
else:
    raise Exception("Login failed: Incorrect password")
