from google import genai

client = genai.Client(api_key="vAIzaSyAnlaAOrpt4t787JVsqDr0JZOdfpSWwzTA")

while True:
    msg = input("You: ")

    if msg.upper() == "EXIT":
        break

    response = client.models.generate_content(
        model="gemini-1.5-flash",
        contents=msg
    )

    print("AI:", response.text)

print("Chat ended 👋")