def Vowel():
    vowel = {"A", "E", "I", "O", "U", "a", "e", "i", "o", "u"}
    unique_words = set()  # Store unique vowel-starting words

    try:
        file = open("G:\\Codes\\Files\\File handling\\Games.txt", "r")
        data = file.readlines()
        
        for line in data:
            words = line.split()
            for word in words:
                if word[0] in vowel:
                    unique_words.add(word)  # Add to set (duplicates are ignored)
        
        print(f"Unique words starting with a vowel: {len(unique_words)}")
        print("Words:", unique_words)

    except FileNotFoundError:
        print("Error: File doesn't exist")
    

Vowel()