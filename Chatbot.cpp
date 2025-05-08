#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Chatbot{
public:
	void chatbot()
	{
		cout << "Hi I'm Edubot!!" << endl;
    cout << "I'm here to help you, ask me anything related to admission." << endl;

    string input;

    while (true) {
        cout << "You: ";
        getline(cin, input);

        // Convert input to lowercase
        transform(input.begin(), input.end(), input.begin(), ::tolower);

        if (input.find("exit") != string::npos || input.find("bye") != string::npos) {
            cout << "Edubot: Thank you for your interest! All the best for your future." << endl;
            break;
        } else if (input.find("courses") != string::npos || input.find("offers") != string::npos || input.find("programs") != string::npos) {
            cout << "Edubot: We offer BTech, MTech, BBA, BPharm, and MBA programs across various disciplines." << endl;
        } else if (input.find("fees") != string::npos) {
            cout << "Edubot: Annual Fees for the courses offered here range from 80,000 to 1,00,000." << endl;
        } else {
            cout << "Edubot: I'm sorry, could you please rephrase or ask something else related to admission?" << endl;
        }
    }
	}
};

int main() {
    Chatbot obj;
    obj.chatbot();
    return 0;
}
