# hackforthesea16
Consolidated lessons learned and docs from the Hack for the Sea hackathon in Gloucester, MA 2016.  
For more info on Hack for the Sea: http://hackforthesea.com/

## Project
Our goal was to experiment with data collection from low-cost sensors that citizen scientists could easily deploy and monitor.
The sensors had to be easy to program and troubleshoot and we needed to get data from the oceans up to the cloud.

## Challenges
Making waterproof enclosures out of trash is very difficult.  See the wiki for more lessons learned on our DIY waterproofing.

## Process:

1 - Citizen scientist builds low cost circuit with sensing capabilities.  They enclose the circuit in a waterproof container and float system.  The upper float contains another board capable of sending data via wifi, bluetooth, or radio so that it doesn’t need to be opened to retrieve data.
 
2 - Electronics in submerged container collect data on:
- Temperature
- Light levels (turbidity)
- Sound/noise (traffic)
- Acceleration (tides, traffic)
 
3 - Data is sent to above water floating station via I2C connection.  There is a cable tether between the units.  We found that communicating through the water is unreliable and we’d want to tether to the station anyways (needed to be retrievable), so hard wiring the data connection made sense.
 
4 - The first version of the floating station featured a Particle Core.  It received data from the submerged sensor board (Adafruit’s Circuit Playground Classic).  The code running on the Core can be found here: https://github.com/quentinms/hackforthesea
 
5 - Server integration (didn't finish during hackathon)
 
6 - Data analysis (also didn't finish)  
Since integration didn’t happen fast enough, our data scientist used another data set and analyzed some things.  Our AR expert also played with another data set and set up augmented reality graphs and floating whales using the Google Tango

## DIY Waterproof Containers

### Design Challenges:
- Needed to be clear or have windows to allow light sensing
- Board should be rigidly held in container so accelerometer readings are consistent
- Container should be a non-insulative as possible to get temp data, or allow a thermal probe
 
### How to Design Good Containers:
This guide is a good start for properly designing waterproof containers: https://www.fictiv.com/blog/posts/nothing-gets-in-waterproof-enclosure-design-101-and-ip68
 
### Working with What You Have:
In a hackathon weekend, we weren’t going to get new injection molded waterproof cases, so we tried various containers, hot glue, and plumber’s tape.
 
#### Things that didn’t work:
- Plumber’s tape pouch
- Talenti Gelato container
- Peanut butter jar
 
#### Things that showed promise:
- Mason jars
 
#### Lessons Learned:
- You can seal one wire through one hole.  Twisted pair or bundled wires allow water between them, even if the outside is well sealed
 
#### Things to try next:
- Design a waterproof case
- Using IP68 rated cable glands for wiring out of the Mason jar
- How small do these go?
- Using another form of communication so that 2 wire SPI communication cable isn’t needed

### Testing Waterproof Containers
 
#### Method:
1. Draw a smiley face on a piece of notebook paper with washable marker
2. Put the piece of paper in the container
3. Submerge the container, looking for bubbles.  Shake the container in the water.  Sink it to the final depth that the container should “hover” at when held by the float.  
4. Remove from water.  Check for water in the container.  Check the drawing for signs of bleeding.  Check the paper for dampness or wet spots.
 
Although this definitely wasn’t IP68 level testing, it was pretty effective in determining which containers could hold a board (temporarily) without damage.

### Sensor Board
We used the Adafruit’s Circuit Playground (2017 update - now the “Classic edition), a $20 development board for schools that can be programmed via the Arduino IDE and the Circuit Playground Libraries.  It is well-documented on the Adafruit site.  While wiring up the sensors individually could reduce the cost of the project, having everything on one board was convenient and fast.  
 
#### Sensors included:
- Light
- Sound (microphone)
- Capacitive touch - could be used to determine salinity
- 3 axis accelerometer
 
#### Other features:
- 10 programmable NeoPixels (color changing LEDs)
- PWM
- TX/RX pins
- Buzzer
- Programmable switches
Sensor - Particle Communication
	The Circuit Playground printed readings 
 
### Particle - Cloud Communication
TBD

### Alternatives to the Particle Core
When I tried to rebuild the project to write up the documents, I had trouble “claiming” the Particle Core.  I had a couple of other Wi-Fi and Bluetooth enabled boards around, so I played around with some of the other options. I didn’t have the resources to explore all of these options, but here are my initial thoughts.
 
#### LoRa
- This probably wouldn’t work from sinker to float, see here: https://www.thethingsnetwork.org/forum/t/underwater-range-of-lora/599/4
- But it could be a good communication strategy from float back to home or data collection station
 
#### Adafruit Bluefruit Feather
- This was wicked easy to get set up and communicating with my phone
- Has accelerometer
- If you were doing a floating sensor within bluetooth range of your phone, this could be a good option
- Having a data logging option would be better though, because it’s streaming data.  It would be better to collect a lot of data and then download a big chunk all at once when in range of phone
 
#### Adalogger Feather
- Has a SD card for data collection.  This is nice, because it could collect a lot unsupervised.  But it would mean container must be openable
 
#### Adafruit WIFI Feather
- Feather with WIFI
 
#### Adafruit GPS Shield
- This is compatible with Feather M0 - I got this working really quickly, and having GPS and acceleration data along might be interesting.  I’m curious if you can stack the GPS shield and Adalogger.  Probably, haven’t tried it.
 
#### Pi Zero with WiFi (Released after Hackathon)
 
#### Tethered Sensors
- Long cable back to land-based data collection system
