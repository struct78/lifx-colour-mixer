void connectToLifx() {
  IPAddress myIp = WiFi.localIP();
  lifx.begin(myIp, LIFX_IP_ADDRESS, LIFX_MAC_ADDRESS);
  lifx.setFlags(0, 0, 1);
}
