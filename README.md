# powerNotifier
powerNotifier is a simple solution for being acknowledged when power is back to your home.
Project is developed based on ESP8266 microcontroller and telegram chat-bot.

Features:
1. ESP basically connects to the Wi-Fi network once the power is up.
2. It sends message "Power on" every 15 minutes.
3. Could be turned on and off by sending corresponding command in telegram bot chat.

Hardware:
This project was created for ESP01 and Arduino Uno as a programmator. But the project could be done with any ESP modification.

How to setup:
1. Create a bot with 2 commands /turn_on and /turn_off. Write down Bot's token
2. Find out your telegram ID with IDBot
3. Make correcponding changes into an arduino code and upload it to the ESP. Please note that you need special setup for ESP and FastBot library for this project.
4. Connect a power supply to ESP when the power is off and it's done.
5. (Optional) Could be tested with phone hotspot to check it's behaviour.

For feedback and\or additional info feel free to reach me via https://www.linkedin.com/in/olratushnyi/
