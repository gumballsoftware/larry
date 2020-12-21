#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

CURL *curl;


struct _URLs {
    std::string JWT;
    std::string baseURL = "http://192.168.0.197:8080";
    std::string _thingPath = "/things/";
    std::string _colorPath = "/properties/color";
    std::map<std::string,std::string> idsByName;

    void addThing(std::string name, std::string id) {
        idsByName[name] = id;
    }

    bool hasName(std::string name) {
        std::map<std::string, std::string>::iterator it = idsByName.find(name);
        return it != idsByName.end();
    }

    std::string thingsPath() {
        return baseURL + _thingPath;
    }

    std::string thingPath(std::string name) {
        std::map<std::string, std::string>::iterator it = idsByName.find(name);
        return _thingPath + it->second;
    }

    std::string colorPath(std::string name) {
        return baseURL + thingPath(name) + _colorPath;
    }
} URLs;

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

std::string getJSON(std::string path, std::string token)
{
    curl = curl_easy_init();

    CURLcode res;
    std::string readBuffer;
    std::string auth = "Authorization: Bearer " + token;

    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Expect: ");
        headers = curl_slist_append(headers, auth.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, (path).c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
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
    URLs.JWT = j1["jwt"];
}

void processThing(auto o) {

}

void getThings() {
  std::string thingJSON = getJSON(URLs.thingsPath(), URLs.JWT);
    auto j1 = json::parse(thingJSON);
    if (j1.is_array()) {
        for (int i=0; i<j1.size(); i++) {
            processThing(j1[i]);
        }
    }
    std::cout << thingJSON << std::endl;
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
    getThings();
    /*
    json colorJ;
    colorJ["color"] = color;
    std::string body = colorJ.dump();
    std::string baseURL = "http://192.168.0.197:8080";
    std::string path = "/things/zb-84182600000b039a/properties/color";
    return putJSON(body, baseURL, path, JWT);
     */
}
