//geofetch --> an open-source GNU/Linux tool to detect and prints out information about
//your public ip and geological location onto the terminal
//geofetch uses api.ipify.org and retrieves the information
//Developed by msb 2024
#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string get_ip_address() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

std::string get_location_info(const std::string& ip) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;
    std::string url = "https://ipinfo.io/" + ip + "/json";

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

int main() {
    std::string ip = get_ip_address();
    if (ip.empty()) {
        std::cerr << "Failed to get public IP address" << std::endl;
        return 1;
    }

    std::cout << "Public IP Address: " << ip << std::endl;

    std::string location_info = get_location_info(ip);
    if (location_info.empty()) {
        std::cerr << "Failed to get location information" << std::endl;
        return 1;
    }

    std::cout << "Location Information: " << location_info << std::endl;

    return 0;
}

