#! /bin/bash

## Path variables - Make project generic:
src_file=$(readlink -f ${BASH_SOURCE[0]})
src_loc=$(dirname $src_file)
cd $src_loc/
cd ../
proj_name=${PWD##*/}
binary=$src_loc/../Debug/$proj_name
cd $src_loc/

# Check if directory already exists:
echo "############ Starting Transfering of file ############"
if ssh debian@192.168.7.2 mkdir /home/debian/$proj_name/ ; then
	echo "Succesfully created the folder"
else
	echo "No need to create the folder, it already exists :-)"
fi

# Transfer binary to Beaglebone and set file permissions:
scp $binary debian@192.168.7.2:~/$proj_name
ssh debian@192.168.7.2 chmod 755 /home/debian/$proj_name/$proj_name
echo "############ File transferred to Beaglebone with executable permissions ###########"
