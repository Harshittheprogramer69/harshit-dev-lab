import mysql.connector

def connect_to_db():
    """Function to connect to the database."""
    try:
        db = mysql.connector.connect(
            host="localhost",
            user="root",  
            password="harshit2006",  
            database="ExaminationHall"  # Database name
        )
        return db
    except mysql.connector.Error as err:
        print(f"Error: {err}")
        return None

# Fetch questions from the database
def get_questions_from_db(subject_name):
    """Fetch questions and answers from the database based on the subject."""
    db = connect_to_db()
    if db is None:
        return [] #useless
    cursor = db.cursor()
    query = """
        SELECT q.QuestionText, q.CorrectAnswer
        FROM Questions q
        JOIN Subjects s ON q.SubjectID = s.SubjectID
        WHERE s.SubjectName = %s
    """
    cursor.execute(query, (subject_name,))
    questions = cursor.fetchall() #all the data print
    db.close()
    return questions

# Save results to the database
def save_results_to_db(student_name, subject, answer1, answer2, correct_answers):
    """Save the student's answers and number of correct answers to the database."""
    db = connect_to_db()
    if db is None:
        return
    cursor = db.cursor()
    query = """
        INSERT INTO Results (StudentName, Subject, Answer1, Answer2, CorrectAnswers)
        VALUES (%s, %s, %s, %s, %s)
    """
    cursor.execute(query, (student_name, subject, answer1, answer2, correct_answers))
    db.commit()
    db.close()

# Check answers and return the number of correct answers
def check_answers(user_answers, correct_answers):
    """Compare user's answers with correct answers and return the correct count."""
    correct_count = 0
    for i in range(len(user_answers)):
        if user_answers[i].strip().lower() == correct_answers[i].strip().lower():
            correct_count += 1
    return correct_count

# Main function
def main():
    """Main logic for the exam system."""
    print("Welcome to the Examination Hall System")
    student_name = input("Enter your name: ").strip()

    subjects = ['History', 'Political Science', 'English']
    total_correct_answers = {}

    for subject in subjects:
        print(f"\nSubject: {subject}")
        questions = get_questions_from_db(subject)

        if len(questions) < 2:
            print(f"Not enough questions for {subject}. Contact administrator.")
            continue

        user_answers = []
        correct_answers = []
        for i, (question, correct_answer) in enumerate(questions, 1):
            print(f"{i}. {question}")
            answer = input("Your Answer: ").strip()
            user_answers.append(answer)
            correct_answers.append(correct_answer)

        # Calculate correct answers for the subject
        correct_count = check_answers(user_answers, correct_answers)
        total_correct_answers[subject] = correct_count

        # Save results to the database
        save_results_to_db(student_name, subject, user_answers[0], user_answers[1], correct_count)

    print("\nExamination Complete! All answers have been submitted systematically.\n")
    print("Here is your result:")

    # Display the results
    for subject, correct in total_correct_answers.items():
        print(f"{subject}: {correct}/2 correct")

    print("\nThanks for cooperation")

# Execution
if __name__ == "__main__":
    main()