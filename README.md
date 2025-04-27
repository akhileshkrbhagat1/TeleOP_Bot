TeleOP_Bot (tele operation bot)
===============================

This project allows control of a robot using MQTT and a simple web interface. The robot can move forward, backward, left, right, or stop based on the commands sent through the web interface. The robot is connected to the internet via WiFi, and movement commands are sent using MQTT messaging.

Components Used
---------------

*   **ESP8266/ESP32**: Used to control the robot via GPIO pins.
    
*   **MQTT Broker**: The robot subscribes to an MQTT topic to receive movement commands.
    
*   **Web Interface**: A simple web page that sends commands to the robot via MQTT.
    

Features
--------

*   Move the robot forward, backward, left, right, or stop using buttons in the web interface.
    
*   Control the robot through MQTT using the topic robot/movementplayer3.
    
*   Compatible with both **ESP8266** and **ESP32** boards.
    

Circuit Setup
-------------

### Motor Pin Connections

#### ESP8266 Pin Configuration:

*   **M11** = GPIO2
    
*   **M12** = GPIO12
    
*   **M21** = GPIO13
    
*   **M22** = GPIO15
    

#### ESP32 Pin Configuration:

*   **M11** = GPIO23
    
*   **M12** = GPIO22
    
*   **M21** = GPIO21
    
*   **M22** = GPIO19
    

Connect the motors to the respective pins as shown above to control movement.

Installation
------------

### 1\. Set up the Arduino IDE

To use this project, you need the **Arduino IDE** installed. Follow these steps to install the required libraries:

1.  **Install ESP8266/ESP32 board package**:
    
    *   Go to File > Preferences > Additional Boards Manager URLs and add the following URLs:
        
        *   For ESP8266: http://arduino.esp8266.com/stable/package\_esp8266com\_index.json
            
        *   For ESP32: https://dl.espressif.com/dl/package\_esp32\_index.json
            
2.  **Install libraries**:
    
    *   Go to Sketch > Include Library > Manage Libraries.
        
    *   Install PubSubClient for MQTT communication.
        

### 2\. Configure the ESP8266/ESP32 Code

Edit the following parameters in the code:

*   **WiFi SSID and Password**: Set your WiFi credentials.
    
*   **MQTT Broker**: Set the broker's address (test.mosquitto.org is used in this example).
    

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML`   const char* ssid = "your-wifi-ssid";  const char* password = "your-password";  const char* mqtt_server = "test.mosquitto.org";   `

### 3\. Upload Code to the ESP8266/ESP32

Upload the code to your ESP8266 or ESP32 using the Arduino IDE.

### 4\. Web Interface

A simple HTML web page is used to control the robot. The page communicates with the MQTT broker to send commands to the robot.

Plain textANTLR4BashCC#CSSCoffeeScriptCMakeDartDjangoDockerEJSErlangGitGoGraphQLGroovyHTMLJavaJavaScriptJSONJSXKotlinLaTeXLessLuaMakefileMarkdownMATLABMarkupObjective-CPerlPHPPowerShell.propertiesProtocol BuffersPythonRRubySass (Sass)Sass (Scss)SchemeSQLShellSwiftSVGTSXTypeScriptWebAssemblyYAMLXML            `Robot Control            </div><div class="slate-code_line">        body {</div><div class="slate-code_line">            font-family: Arial, sans-serif;</div><div class="slate-code_line">            text-align: center;</div><div class="slate-code_line">            padding: 20px;</div><div class="slate-code_line">        }</div><div class="slate-code_line">        button {</div><div class="slate-code_line">            margin: 10px;</div><div class="slate-code_line">            padding: 15px;</div><div class="slate-code_line">            font-size: 18px;</div><div class="slate-code_line">            cursor: pointer;</div><div class="slate-code_line">        }</div><div class="slate-code_line">            Robot Control =============      Forward      Backward      Left      Right      Stop      </div><div class="slate-code_line">        // Connect to the MQTT broker</div><div class="slate-code_line">        const client = mqtt.connect(&#x27;wss://test.mosquitto.org:8081&#x27;);</div><div class="slate-code_line"></div><div class="slate-code_line">        // Define the MQTT topic to which we will publish</div><div class="slate-code_line">        const topic = &#x27;robot/movementplayer3&#x27;;</div><div class="slate-code_line"></div><div class="slate-code_line">        // Handle the MQTT connection</div><div class="slate-code_line">        client.on(&#x27;connect&#x27;, function () {</div><div class="slate-code_line">            console.log(&#x27;Connected to MQTT broker&#x27;);</div><div class="slate-code_line">        });</div><div class="slate-code_line"></div><div class="slate-code_line">        // Send a command to the bot</div><div class="slate-code_line">        function sendCommand(command) {</div><div class="slate-code_line">            console.log(&#x27;Sending command:&#x27;, command);</div><div class="slate-code_line">            client.publish(topic, command); // Publish the command to the topic</div><div class="slate-code_line">        }</div><div class="slate-code_line">`    

### 5\. Testing

*   Connect your robot to WiFi.
    
*   Open the web interface in any browser.
    
*   Use the buttons to control the robot's movement.
    

Troubleshooting
---------------

*   **WiFi Connection Issues**: Ensure that the correct WiFi credentials are set and that the ESP8266/ESP32 is in range of the network.
    
*   **MQTT Connection Issues**: Ensure the broker is available. If using a local broker, change the broker address in the code.
    
*   **GPIO Pin Issues**: Ensure the correct GPIO pins are set for motor control.
    

License
-------

This project is open-source and available under the MIT License.
