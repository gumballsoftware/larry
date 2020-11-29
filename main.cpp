#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

CURL *curl;
std::string JWT;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string postJSON(std::string body, std::string base, std::string path)
{
    curl = curl_easy_init();
    CURLcode res;
    std::string readBuffer;

    if(curl) {
        struct curl_slist *headers = NULL;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Expect: ");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_URL, (base+path).c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.length());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

int putJSON(std::string body, std::string base, std::string path, std::string token)
{
    curl = curl_easy_init();

    CURLcode res;
    std::string readBuffer;
    std::string auth = "Authorization: Bearer " + token;

    if(curl) {
        struct curl_slist *headers = NULL;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Expect: ");
        headers = curl_slist_append(headers, auth.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_URL, (base+path).c_str());

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return 0;
}

void login(std::string name, std::string pwd) {
    json login;
    login["email"] = name;
    login["password"] = pwd;
    std::string body = login.dump();
    std::string jwt = postJSON(body,
                               "http://192.168.0.197:8080",
                               "/login/");
    auto j1 = json::parse(jwt);
    JWT = j1["jwt"];
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Usage: larry username password color"  << std::endl;
        return -1;
    }
    std::string userName = argv[1];
    std::string userPass = argv[2];
    std::string color = argv[3];
    login(userName, userPass);
    json colorJ;
    colorJ["color"] = color;
    std::string body = colorJ.dump();
    std::string baseURL = "http://192.168.0.197:8080";
    std::string path = "/things/zb-84182600000b039a/properties/color";
    return putJSON(body, baseURL, path, JWT);
}
