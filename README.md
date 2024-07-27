geofetch
an open-source GNU/Linux tool to detect and prints out information about your public ip and geological location onto the terminal geofetch uses api.ipify.org and retrieves the information


dependencies:
g++ compiler
libcurl4-openssl-dev
install using `sudo apt-get install libcurl4-openssl-dev`

then run `make`

then `./geofetch.exe`

output:
```go

Public IP Address: xxx.xxx.xxx.xxx
Location Information: {
  "ip": "xxx.xxx.xxx.xxx",
  "hostname": "your_hostname",
  "city": "your_city",
  "region": "your_state",
  "country": "your_country_code",
  "loc": "your_location",
  "org": "ISP_organization",
  "postal": "postal_code",
  "timezone": "timezone",
  "readme": "https://ipinfo.io/missingauth"
}
```

Enjoy.
