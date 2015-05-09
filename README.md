# capsense-applications
Experiments with capsense - any metal as touch sensor

-------------
The capacitiveSensor library turns two or more Arduino pins into a capacitive sensor, which can sense the electrical capacitance of the human body. All the sensor setup requires is a medium to high value resistor and a piece of wire and a small (to large) piece of aluminum foil on the end. At its most sensitive, the sensor will start to sense a hand or body inches away from the sensor.

 - [Arduino wiki on capsense](http://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense)
 - [Capsense library download](https://github.com/arduino-libraries/CapacitiveSensor/zipball/master)

# My Experiments

### 1. [Switch board](./switch board/)
Created a switchboard for room using Aluminium foil.

#####Check this on **You<span style="color:white;background: rgb(196,26,30);padding: 2px 3px;margin:1px;border-radius: 3px">Tube</span>**

<a href="http://www.youtube.com/watch?feature=player_embedded&v=qxaaouVgP8c" target="_blank"><img src="http://img.youtube.com/vi/qxaaouVgP8c/0.jpg" alt="Capsense room switch" width="500"  border="10" /></a>

`DESC:` A simple application of capsense is to create touch based switch boards. The concept is really simple, we keep tracking the time it takes to fully charge the thus formed capacitor (metal ~ Aluminium Foil in this case).
