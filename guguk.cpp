#include <iostream>
#include <string>
#include <vector>
#include "json.hpp"
#include <curl/curl.h>

using json = nlohmann::json;
using namespace std;

class MessageQueue {
private:
    vector<string> messages;
public:
    void enqueue(string message) {
        messages.push_back(message);
    }

    string dequeue() {
        if (messages.empty()) {
            return "";
        } else {
            string message = messages[0];
            messages.erase(messages.begin());
            return message;
        }
    }

    bool isEmpty() {
        return messages.empty();
    }
};

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string getResponse(string input, string apiKey) {
    string model = "text-davinci-003";
    string apiKeyHeader = "Authorization: Bearer " + apiKey;

    // format data yang akan dikirim dengan JSON
    json data = {
        {"model", model},
        {"prompt", input},
        {"temperature", 0.7},
        {"max_tokens", 256},
        {"top_p", 1},
        {"frequency_penalty", 0},
        {"presence_penalty", 0}
    };
    string jsonData = data.dump();

    // inisialisasi library curl
    string responseBuffer;
    CURL* curl = curl_easy_init();
    if (!curl) {
        return "ERROR INIT";
    }

    // set header untuk request
    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, apiKeyHeader.c_str());

    // set option untuk request
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/completions");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonData.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

    // jalankan request
    CURLcode res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        return "ERROR NOT OK";
    }

    // cleanup library curl
    curl_easy_cleanup(curl);

    // parsing hasil response dari OpenAI API
    json responseJson = json::parse(responseBuffer);
    string text = responseJson["choices"][0]["text"];

    return text;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    string apiKey = "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";
    MessageQueue queue;

    cout << "Selamat Datang di Guguk ChatBot!" << endl;
    cout << "Build with ♡ by Ahmad Ansori and TEAM" << endl << endl;

    while (true) {
        cout << "Anda: ";
        string input;
        getline(cin, input);

        if (!input.empty()) {
            queue.enqueue(input);
        }

        if (!queue.isEmpty()) {
            string message = queue.dequeue();
            cout << "Guguk: " << getResponse(message, apiKey) << endl << endl;
        }
    }

    return 0;
}
