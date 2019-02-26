# BeagleBone
The purpose of this repository is to gather a place for me to collect my work related to the Beaglebone Black board.
I hope to also use this repository to note stuff down, when my memory tends to free up a little too much from time to time...

## Tools
* Code Composer Studio is a nice IDE from Texas Instruments, which also happens to feature a compiler for the pru's on Beaglebone:
[ http://processors.wiki.ti.com/index.php/Download_CCS ]

* I have created my own tools for working with the the prus on the Beaglebone. For instance, I have created two bash scripts for starting and stopping the prus. However, they are only campatible if you are using the PRU's with the Remote Processor Messaging framework (RPMsg). If you are using the uio driver, then you can use the pru api, which is available at:
https://github.com/beagleboard/am335x_pru_package

* PSFTP - Client for file transfer sessions between Beaglebone and pc:
https://the.earth.li/~sgtatham/putty/latest/w64/psftp.exe

## References
* Very good book about how to use the PRU's on Beaglebone by Mark A. Yoder:
https://github.com/MarkAYoder/PRUCookbook/blob/master/docs/book.pdf
* Very informant and understandable article about how to run C programs on the prus:
http://www.righto.com/2016/09/how-to-run-c-programs-on-beaglebones.html

## Quotes
* Software and cathedrals are much the same – first we build them, then we pray.
