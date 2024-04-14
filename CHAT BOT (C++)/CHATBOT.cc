#include <iostream>
#include <string>
#include <map>

class Chatbot {
public:
    Chatbot() {
        responses = {
            {"hello", "Hi there! How can I help you?"},
            {"how are you", "I'm just a chatbot, but I'm here to assist you."}, //add your responses here as shown here
            {"bye", "Goodbye! Have a great day!"}
            // Add more responses here
        };
    }

    std::string getResponse(const std::string& input) {
        std::string lowerInput = toLower(input);
        
        if (responses.find(lowerInput) != responses.end()) {
            return responses[lowerInput];
        } else {
            return "I'm sorry, I don't understand.";
        }
    }

private:
    std::map<std::string, std::string> responses;

    std::string toLower(const std::string& str) {
        std::string lowerStr = str;
        for (char& c : lowerStr) {
            c = std::tolower(c);
        }
        return lowerStr;
    }
};

int main() {
    Chatbot chatbot;

    std::cout << "Chatbot: Hi! How can I assist you today?" << std::endl;

    while (true) {
        std::string userMessage;
        std::cout << "You: ";
        std::getline(std::cin, userMessage);

        if (userMessage == "bye") {
            std::cout << "Chatbot: Goodbye! Have a great day!" << std::endl;
            break;
        }

        std::string response = chatbot.getResponse(userMessage);
        std::cout << "Chatbot: " << response << std::endl;
    }

    return 0;
}