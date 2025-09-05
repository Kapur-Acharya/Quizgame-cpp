#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

struct Question
{
    string question;
    string options[4];
    char correctAnswer;
};

int main()
{
    ifstream file("questions.txt"); // file should be in same folder
    if (!file)
    {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    Question q;
    int score = 0, total = 0;

    // Read until end of file
    while (getline(file, q.question))
    {
        for (int i = 0; i < 4; i++)
        {
            getline(file, q.options[i]);
        }
        file >> q.correctAnswer;
        file.ignore(); // skip newline after answer

        cout << "\nQ" << (total + 1) << ": " << q.question << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << q.options[i] << endl;
        }

        char userAnswer;
        cout << "Your answer (a/b/c/d): ";
        cin >> userAnswer;

        if (tolower(userAnswer) == tolower(q.correctAnswer))
        {
            cout << "✅ Correct!\n";
            score++;
        }
        else
        {
            cout << "❌ Wrong! Correct answer was: " << q.correctAnswer << endl;
        }
        total++;
    }

    cout << "\n===== QUIZ OVER =====" << endl;
    cout << "Your Score: " << score << " / " << total << endl;

    file.close();
    return 0;
}
