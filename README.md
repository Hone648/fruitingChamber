# C++ Mushroom Cultivation Chamber

> Customized microcontroller code designed to meticulously regulate and supervise the environmental parameters within a mushroom cultivation chamber. This intelligent software employs a variety of sensors to continuously monitor and maintain factors such as temperature, humidity, and air circulation, ensuring the ideal conditions for healthy mushroom growth.
>> This software is tailored for the Arduino Uno microcontroller platform and ensures precise environmental regulation vital for optimal mushroom growth. It features an optional OLED screen, providing users with real-time data monitoring for a user-friendly and intuitive cultivation experience.

# Installation
---

1. **Download the Arduino IDE:**
    
    [Arduino Software Download Page](https://www.arduino.cc/en/software)
    
    Choose the version appropriate for your operating system (Windows, 
macOS, or Linux). There might be two versions available: one from the Microsoft Store (for Windows) and one from the website. Either one should work, but the website version is more common.
    
2. **Install the Arduino IDE:**

    * For **Windows**:
      * If you downloaded the installer from the website, run the installer and follow the installation wizard.
      * If you downloaded it from the Microsoft Store, simply install it like any other app.
    * For **macOS**:
      * Open the downloaded `.dmg` file.
      * Drag the Arduino application to the Applications folder.
    * For **Linux**:
      * Extract the downloaded archive to a location of your choice.
      * Navigate to the extracted directory and run the `install.sh` script.

3. **Launch the Arduino IDE:**
    
    Once the installation is complete, you can launch the Arduino IDE from your applications menu (on Windows or macOS) or by running the arduino command in your terminal (on Linux).

4. **Navigate to the Library Manager:**
    * In the Arduino IDE, go to the "Sketch" menu.
    * Select "Include Library" > "Manage Libraries...".
 
5. **Search for the Library:**
    * Adafruit-MCP23017-Arduino-Library:
      * Type "Adafruit MCP23017" in the search bar.
      * Click "Install" when you find the "Adafruit-MCP23017-Arduino-Library."

    * Adafruit SSD1306 Library:
      * Type "Adafruit SSD1306" in the search bar.
      * Click "Install" when you find the "Adafruit SSD1306" library.

    * DS1302 by Rafa Couto:
      * Type "DS1302" in the search bar.
      *Look for the "DS1302" library by Rafa Couto and click "Install."
    * Adafruit Unified Sensor:
      * Type "Adafruit Unified Sensor" in the search bar.
      * Click "Install" when you find the "Adafruit Unified Sensor" library.
    * DHT sensor library:
      * Type "DHT sensor" in the search bar.
      * Look for the "DHT sensor library" and click "Install."

    That's it! You have successfully installed all the required libraries.

    ```cpp
    #include <SPI.h>                // For MCP23017 library
    #include <Adafruit_SSD1306.h>   // For SSD1306 OLED library
    #include <Adafruit_Sensor.h>    // For Adafruit Sensor library
    #include <DS1302.h>             // For DS1302 library by Rafa Couto
    #include <Adafruit_Sensor.h>    // For Adafruit Unified Sensor library
    #include <DHT.h>                // For DHT sensor library
6. **Move the `.ino` file in this repository to the Arduino folder:**
    * Create a folder called fruitingChamber in the Documents > Arduino folder.
    * Copy the `fruitingChamber.ino` to this new folder.

7.  **Load our Sketch:**
    * In the Arduino IDE, locate and click on the "File" menu at the top-left corner of the window.
    * Choose "Open..." (for Windows and Linux) or "Open File..." (for macOS).
    * Select the fruitingChamber folder and then select the `fruitingChamber.ino` file.

8. **Initial Configuration:**

    You might need to configure the IDE to recognize your Arduino board. To do this:
    * Go to the "Tools" menu. 
    * Select "Board" and choose your specific Arduino model (e.g., Arduino Uno).
    * Under the "Port" menu, select the serial port your Arduino is connected to (if it's not automatically detected).

9. **Verify and Compile Your Sketch:**
    Click the checkmark icon (✓) or go to "Sketch" > "Verify/Compile" to check your code for errors. The IDE will compile the code, and if there are no errors, you will see "Done compiling" at the bottom of the window.

10. **Upload Your Sketch:**
    * Click the right arrow icon (→) or go to "Sketch" > "Upload" to upload your sketch to the Arduino board.
    * During the upload process, you'll see the status messages in the black console at the bottom of the Arduino IDE window.

11. **Upload Completion:**
    
    Once the upload is successful, you'll see "Done uploading" in the status console.

Your code should now be running on the Arduino board. The board will execute the code, and you can observe the results.
