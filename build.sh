#!/bin/bash




printf "\r copying"
rm build/Elegoo.zip &> /dev/null
printf "\r copying."
rm -f -r build/Elegoo/
printf "\r copying.."
mkdir build/Elegoo/ &> /dev/null
printf "\r copying..."
sudo chown -R manuel build/Elegoo/ &> /dev/null
printf "\r copying...."
cp -r -a docs  build/Elegoo/ &> /dev/null
printf "\r copying....."
cp -r -a examples build/Elegoo/ &> /dev/null
printf "\r copying......"
cp -r -a src build/Elegoo/ &> /dev/null
printf "\r copying......."
cp AUTHORS build/Elegoo/ &> /dev/null
printf "\r copying........"
cp keywords.txt build/Elegoo/ &> /dev/null
printf "\r copying........."
cp library.properties build/Elegoo/ &> /dev/null
printf "\r copying.........."
cp README.md build/Elegoo/ &> /dev/null
printf "\r copying..........."
cp LICENSE build/Elegoo/ &> /dev/null
printf "\r copying............"
rm build/Elegoo/docs/ELEGOO* &> /dev/null
printf "\r copying............."
rm build/Elegoo/docs/README.md &> /dev/null
printf "\r copying.............."
rm build/Elegoo/README.md &> /dev/null
printf "\r copying..............."
cp build/assets/README.md build/Elegoo/ &> /dev/null 
printf "\r copying................"
cp -r -a src/Elegoo.h  build/Elegoo/src &> /dev/null
printf "\r copying................."
cp -r -a src/Elegoo.cpp build/Elegoo/src &> /dev/null
printf "\r copying..................\n"

printf "\r building"
cd build || exit &> /dev/null
printf "\r building."
zip -r Elegoo Elegoo &> /dev/null
printf "\r building.."
cd .. &> /dev/null
printf "\r building..."
arduino-cli lib install --zip-path build/Elegoo.zip &> /dev/null
printf "\r building...."
cd build || exit
printf "\r building....."
cp -r Elegoo ~/Arduino/libraries/
printf "\r building......\n"

if ! command -v arduino-cli &> /dev/null
then
    printf "arduino-cli: could not be found \n !!!Please install it!!! \n Use sudo snap install arduino-cli"
    exit
fi

printf " Done!\n"

