#!/bin/bash

rm build/Car.zip
rm -f -r build/Car/
mkdir build/
mkdir build/Car/
sudo chown -R manuel build/Car/
cp -r -a docs  build/Car/
cp -r -a examples build/Car/
cp -r -a src build/Car/
cp AUTHORS build/Car/
cp keywords.txt build/Car/
cp library.properties build/Car/
cp README.md build/Car/
rm build/Car/docs/ELEGOO*

cd build
zip Car Car/*
cd ..

if ! command -v arduino-cli &> /dev/null
then
    echo "arduino-cli: could not be found \n !!!Please install it!!! \n Use sudo snap install arduino-cli"
    exit
fi

arduino-cli lib install --zip-path build/Car.zip

cd build
cp -r Car ~/Arduino/libraries/
