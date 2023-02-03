#!/bin/bash




printf "\r copying"
rm build/Elegoo.zip &> /dev/null
printf "\r copying."
rm -r build/elegoo/* &> /dev/null
printf "\r copying.."
printf "\r copying..."
sudo chown -R manuel build/elegoo/ &> /dev/null
printf "\r copying...."
cp -r -a docs  build/elegoo/ &> /dev/null
printf "\r copying....."
cp -r -a examples build/elegoo/ &> /dev/null
printf "\r copying......"
cp -r -a src build/elegoo/ &> /dev/null
printf "\r copying......."
cp AUTHORS build/elegoo/ &> /dev/null
printf "\r copying........"
cp keywords.txt build/elegoo/ &> /dev/null
printf "\r copying........."
cp library.properties build/elegoo/ &> /dev/null
printf "\r copying.........."
cp README.md build/elegoo/ &> /dev/null
printf "\r copying..........."
cp LICENSE build/elegoo/ &> /dev/null
printf "\r copying............"
rm build/elegoo/docs/ELEGOO* &> /dev/null
printf "\r copying............."
rm build/elegoo/docs/README.md &> /dev/null
printf "\r copying.............."
rm build/elegoo/README.md &> /dev/null
printf "\r copying..............."
cp build/assets/README.md build/elegoo/ &> /dev/null 
printf "\r copying................"
cp -r -a src/Elegoo.h  build/elegoo/src &> /dev/null
printf "\r copying................."
cp -r -a src/Elegoo.cpp build/elegoo/src &> /dev/null
printf "\r copying..................\n"

printf "\r building"
cd build || exit &> /dev/null
printf "\r building."
zip -r elegoo Elegoo &> /dev/null
printf "\r building.."
cd .. &> /dev/null
printf "\r building..."
arduino-cli lib install --zip-path build/Elegoo.zip &> /dev/null
printf "\r building...."
cd build || exit
printf "\r building....."
cp -r elegoo ~/Arduino/libraries/
printf "\r building......\n"

if ! command -v arduino-cli &> /dev/null
then
    printf "arduino-cli: could not be found \n !!!Please install it!!! \n Use 'sudo snap install arduino-cli'"
    exit
fi

printf " Done!\n"

