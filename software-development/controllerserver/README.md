# Controller Command Server Over Ethernet

This program is designed to run on the raspberry pi and send and receive commands as needed to the controller software on the raspberry pi. 

The only argument to this program is the port to use. The default port is port 80. 
-p sets the port value. 
-s sets the secret

The secret is used to make sure that any important control api commands are not sent by invalid users. Setting the secret empty confirms all against all provided secrets as valid. 