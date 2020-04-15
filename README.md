# LIFX Colour Mixer

This project is a physical colour mixer I created for my kids LIFX bulb.

## credentials.h

This file is where information about your local network and LIFX bulb is stored. Simply rename `credentials.h.example` to `credentials.h` and update the values.

```
#define WIFI_SSID "WIFI_NAME" <-- Your WIFI SSD
#define WIFI_PASS "WIFI_PASSWORD" <-- Your WIFI password
#define LIFX_MAC_ADDRESS "LIFX_MAC_ADDRESS" <-- Find this by logging on to your WIFI router
#define LIFX_IP_ADDRESS "LIFX_IP_ADDRESS" <-- Find this by logging on to your WIFI router
```

TODO:
- Fritzing diagram
- Retrieve Mac and IP address automatically