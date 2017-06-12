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

