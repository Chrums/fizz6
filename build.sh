#!/bin/bash

while getopts ":i:" opt; do
    case $opt in
        i)
            CMAKE_INSTALL_PREFIX=$OPTARG
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            exit 1
            ;;
        :)
            echo "Option -$OPTARG requires an argument." >&2
            exit 1
            ;;
    esac
done

if [ -z $CMAKE_INSTALL_PREFIX ]
then
    CMAKE_INSTALL_PREFIX=/home/ubuntu/environment/build
fi

if [ ! -z $CMAKE_INSTALL_PREFIX ]
then
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=$CMAKE_INSTALL_PREFIX ..
    make install
    ./bin/strife
fi