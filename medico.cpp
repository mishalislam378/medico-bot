// #include <iostream>
// #include <stack>
// #include <string>
// #include <fstream> 

// using namespace std;

// // Node for symptom decision tree
// struct Node {
//     string questionOrCondition;
//     Node* yes;
//     Node* no;

//     Node(string text) : questionOrCondition(text), yes(nullptr), no(nullptr) {}
// };


// struct HistoryEntry {
//     Node* node;
//     string answer;
// };

// // Linked list node to store diagnosis summaries along with patient name
// struct DiagnosisNode {
//     string patientName;
//     string summary;
//     DiagnosisNode* next;
//     DiagnosisNode(const string& name, const string& s) : patientName(name), summary(s), next(nullptr) {}
// };

// // Linked list class for diagnoses
// class DiagnosisList {
//     DiagnosisNode* head;
// public:
//     DiagnosisList() : head(nullptr) {}

//     void addDiagnosis(const string& patientName, const string& summary) {
//         DiagnosisNode* newNode = new DiagnosisNode(patientName, summary);
//         if (!head) {
//             head = newNode;
//         }
//         else {
//             DiagnosisNode* temp = head;
//             while (temp->next)
//                 temp = temp->next;
//             temp->next = newNode;
//         }
//     }
//     void clearAllHistory(const string& filename) {
//         // Delete all linked list nodes
//         DiagnosisNode* temp;
//         while (head) {
//             temp = head;
//             head = head->next;
//             delete temp;
//         }
//         head = nullptr;

        
//         ofstream outFile(filename, ios::trunc); // Truncate the file
//         if (!outFile) {
//             cerr << "Error clearing the file.\n";
//         }
//         outFile.close();

//         cout << "All diagnosis history cleared successfully.\n";
//     }

//     // Print all diagnoses (all patients)
//     void printAll() {
//         if (!head) {
//             cout << "No past diagnoses found.\n";
//             return;
//         }
//         cout << "\n=== Past Diagnoses ===\n";
//         int count = 1;
//         DiagnosisNode* temp = head;
//         while (temp) {
//             cout << count++ << ". Patient: " << temp->patientName << "\n" << temp->summary << "\n";
//             temp = temp->next;
//         }
//         cout << "=====================\n";
//     }

//     // Print diagnoses for a specific patient name
//     void printDiagnosesForPatient(const string& name) {
//         if (!head) {
//             cout << "No past diagnoses found.\n";
//             return;
//         }
//         DiagnosisNode* temp = head;
//         int count = 0;
//         cout << "\n=== Past Diagnoses for " << name << " ===\n";
//         while (temp) {
//             if (temp->patientName == name) {
//                 cout << ++count << ". " << temp->summary << "\n";
//             }
//             temp = temp->next;
//         }
//         if (count == 0) cout << "No records found for " << name << ".\n";
//         cout << "=====================\n";
//     }

//     void saveToFile(const string& filename) {
//         ofstream outFile(filename);
//         if (!outFile) {
//             cerr << "Error saving diagnosis history to file.\n";
//             return;
//         }
//         DiagnosisNode* temp = head;
//         while (temp) {
            
//             outFile << temp->patientName << "\n" << temp->summary << "\n---ENTRY---\n";
//             temp = temp->next;
//         }
//         outFile.close();
//     }

//     void loadFromFile(const string& filename) {
//         ifstream inFile(filename);
//         if (!inFile) {
//             // No file found, no past history to load
//             return;
//         }
//         string line, patientName, entry;
//         bool readingSummary = false;
//         while (getline(inFile, line)) {
//             if (line == "---ENTRY---") {
//                 addDiagnosis(patientName, entry);
//                 patientName.clear();
//                 entry.clear();
//                 readingSummary = false;
//             }
//             else if (patientName.empty()) {
//                 patientName = line;  
//                 readingSummary = true;
//             }
//             else if (readingSummary) {
//                 entry += line + "\n";
//             }
//         }
//         inFile.close();
//     }

//     ~DiagnosisList() {
//         DiagnosisNode* temp;
//         while (head) {
//             temp = head;
//             head = head->next;
//             delete temp;
//         }
//     }
// };

// // FOR BACKTRACKING 
// stack<HistoryEntry> answerHistory;


// Node* buildSymptomTree() {
//     Node* flu = new Node("You might have the Flu.");
//     Node* cold = new Node("You might have a Common Cold.");
//     Node* migraine = new Node("You might be experiencing a Migraine.");
//     Node* covid = new Node("You might have COVID-19. Please get tested.");
//     Node* allergy = new Node("You might have Seasonal Allergies.");
//     Node* healthy = new Node("You seem healthy!");

//     // New questions
//     Node* tasteLoss = new Node("Have you lost your sense of taste or smell?");
//     tasteLoss->yes = covid;
//     tasteLoss->no = flu;

//     Node* sneezing = new Node("Are you sneezing a lot?");
//     sneezing->yes = allergy;
//     sneezing->no = cold;

//     Node* cough = new Node("Do you have a cough?");
//     cough->yes = tasteLoss;
//     cough->no = sneezing;

//     Node* nausea = new Node("Do you feel nauseous or lightheaded?");
//     nausea->yes = migraine;
//     nausea->no = healthy;

//     Node* headache = new Node("Do you have a headache?");
//     headache->yes = nausea;
//     headache->no = healthy;

//     Node* fever = new Node("Do you have a fever?");
//     fever->yes = cough;
//     fever->no = headache;

//     return fever;  
// }


// string startDiagnosis(Node* root, const string& patientName) {
//     answerHistory = stack<HistoryEntry>(); 
//     Node* current = root;
//     string input;

//     while (current->yes != nullptr && current->no != nullptr) {
//         cout << current->questionOrCondition << " (yes/no/back): ";
//         cin >> input;

//         for (auto& c : input) c = tolower(c);

//         if (input == "yes" || input == "y") {
//             answerHistory.push(HistoryEntry{ current, "yes" });
//             current = current->yes;
//             cout << "(Hmm... sounds suspicious )\n";
//         }
//         else if (input == "no" || input == "n") {
//             answerHistory.push(HistoryEntry{ current, "no" });
//             current = current->no;
//             cout << "(Alright, dodged that symptom like a ninja! )\n";
//         }
//         else if (input == "back") {
//             if (answerHistory.empty()) {
//                 cout << "You're already at the start! Can't go further back in time \n";
//             }
//             else {
//                 HistoryEntry last = answerHistory.top();
//                 answerHistory.pop();
//                 current = last.node;
//                 cout << "Time travel engaged! Back to previous question...\n";
//             }
//         }
//         else {
//             cout << " That response went on a world tour! Try something like 'yes', 'no', or 'back' instead.\n";
//         }
//     }

//     cout << "\n== Diagnosis Result ==\n";
//     cout << " Medical Bot says: " << current->questionOrCondition << "\n";
//     cout << "(But don't worry, WebMD once told someone they had 4 hours to live for a sore throat )\n";

    
//     string summary = "Diagnosis: " + current->questionOrCondition + "\nYour answers:\n";

//     // Reverse stack to print answers in correct order
//     stack<HistoryEntry> tempStack = answerHistory;
//     stack<HistoryEntry> reverseStack;
//     while (!tempStack.empty()) {
//         reverseStack.push(tempStack.top());
//         tempStack.pop();
//     }

//     while (!reverseStack.empty()) {
//         HistoryEntry p = reverseStack.top();
//         reverseStack.pop();
//         summary += p.node->questionOrCondition + " -> " + p.answer + "\n";
//     }

//     return summary;
// }

// int main() {
//     system("Color 0B");

//     DiagnosisList history;
//     const string filename = "diagnosis_history.txt";

//     // Load history from file on start
//     history.loadFromFile(filename);

//     cout << "=======  Welcome to the Health Symptom Checker  =======\n\n";
//     cout << "Disclaimer: I'm not a doctor, but I did pass a few Google searches!\n\n";
//     cout << "Answer questions with yes/no. Type 'back' to go to previous question.\n";


//     Node* root = buildSymptomTree();

//     while (true) {
//         cout << "\nMenu:\n1. Start new diagnosis\n2. View past diagnoses for a patient\n 3.view all \n 4. Clear all saved diagnosis history\n5.Exit\nChoose: ";
//         string input;
//         int choice;
//         cin >> choice;
//         cin.ignore(); 

//         if (choice == 1) {
//             string patientName;
//             cout << "Enter patient name: ";
//             getline(cin >> ws, patientName); 
//             string result = startDiagnosis(root, patientName);
//             history.addDiagnosis(patientName, result);

           
//             history.saveToFile(filename);
//         }

//         else if (choice == 2) {
//             cout << "Enter patient name to view past diagnoses: ";
//             string searchName;
//             getline(cin, searchName);
//             history.printDiagnosesForPatient(searchName);
//         }

//         else if (choice == 3) { history.printAll(); }


//         else if (choice == 4) { history.clearAllHistory(filename); }


//         else if (choice == 5) {
//             cout << "Goodbye! Stay healthy and keep dodging those germs like a pro! \n";
//             break;
//         }
//         else {
//             cout << "invalid choice,try again!\n";

//         }
//     }

//     return 0;
// }