# OSC

OSC (Open Sound Control) is a networking protocol intended for low-latency delivery. 

- ​	**Latency** - time interval between stimulation and response

OSC can send and receive messages, up to 1KB each.

Best for sending several parameters through different applications or through networked computers.

## Protocols

**UDP vs TCP**

TCP is a connection-oriented protocol and UDP is a connection-less protocol. 

TCP establishes a connection between a sender and receiver before data can be set, UDP does not. 

TCP --> More Reliable  | UDP --> Faster*

​	*There is still a slight delay with messages because the OSC receiver is on the secondary thread.

With UDP, no 'handshake' is required, so no guaranteed delivery and no error checking.

## Addresses

An address is the name of the command or parameter, and the syntax resembles URL

For example, OSC addresses from TouchOSC look like:

- /1/push1
- /2/toggle2

For the argument, OSC takes:

- integer
- string
- boolean
- float

## OSC & Openframeworks

For integrating OSC into your Openframeworks project, you can use the core addon, ofxOsc.