#! /bin/bash

## Path variables - Make project generic:
src_file=$(readlink -f ${BASH_SOURCE[0]})
src_loc=$(dirname $src_file)
cd $src_loc/
cd ../
proj_name=${PWD##*/}
cd $src_loc/

# Clean the auto_generated folder:
echo "Cleaning the auto_generated and debug folder"
rm $src_loc/../build/_auto_generated/*

echo $src_loc
