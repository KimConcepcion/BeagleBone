# BeagleBone
Code Composer Studio from Texas Instruments features a compiler for the pru's on Beaglebone:
http://processors.wiki.ti.com/index.php/Download_CCS

## Tools
I have created my own tools for starting and stopping the prus on the Beaglebone. However, they are only campatible if you are using the PRU's with the Remote Processor Messaging (RPMsg). If you are using e.g. the uio driver, then you can use the pru api, which is available at:
https://github.com/beagleboard/am335x_pru_package

## Very nice book about how to use the PRU's on Beaglebone:
https://github.com/MarkAYoder/PRUCookbook 
