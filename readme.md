Here is the **README file** for your project titled **"Medico Bot"**:

---

# 💊 Medico Bot - Health Symptom Checker

### 🔍 Overview:

**Medico Bot** is an interactive C++ program that helps users perform a basic health self-diagnosis by answering a series of yes/no questions. It uses a decision tree for symptoms and allows backtracking, diagnosis history management, and personalized summaries with patient names.

---

### 🧠 Features:

* Interactive symptom checker using a **binary decision tree**
* Option to **go back** to the previous question
* Saves **diagnosis history per patient**
* **View all** or **individual patient history**
* **Clear all** saved diagnosis history
* Colorful and humorous console messages
* Allows user to **restart diagnosis** after completion
* Supports **file persistence** (`diagnosis_history.txt`)

---

### 🛠 How It Works:

1. User selects **"Start new diagnosis"**
2. Enters their **name**
3. Answers a series of questions (yes/no/back)
4. Bot gives a possible diagnosis
5. Stores the diagnosis summary in memory and in file
6. Offers menu options to review or clear history

---

### 📂 Files:

* `medico_bot.cpp` — Main C++ source file
* `diagnosis_history.txt` — Text file to store past diagnoses (auto-generated)

---

### 💡 Sample Run:

```
=======  Welcome to the Health Symptom Checker  =======

Disclaimer: I'm not a doctor, but I did pass a few Google searches!

Answer questions with yes/no. Type 'back' to go to previous question.

Menu:
1. Start new diagnosis
2. View past diagnoses for a patient
3. View all
4. Clear all saved diagnosis history
5. Exit
Choose: 1
Enter patient name: Ali

Do you have a fever? (yes/no/back): yes
(Hmm... sounds suspicious )

Do you have a cough? (yes/no/back): yes
(Hmm... sounds suspicious )

Have you lost your sense of taste or smell? (yes/no/back): yes
(Hmm... sounds suspicious )

== Diagnosis Result ==
Medical Bot says: You might have COVID-19. Please get tested.

Diagnosis: You might have COVID-19...
```

---

### 🔁 Restarting Diagnosis:

After finishing a diagnosis, the bot now offer options.

```

---

### 🖥 System Requirements:

* C++ compiler (e.g., g++)
* Windows terminal for colored output (`system("Color 0B");`)

---

### 📌 Notes:

* All data is saved automatically to `diagnosis_history.txt`
* Clearing history deletes file contents and memory
* Intended for **learning/demo purposes only** – not real medical advice

---




