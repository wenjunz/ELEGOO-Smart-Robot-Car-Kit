#!/bin/bash




printf "\r copying"
rm build/Car.zip &> /dev/null
printf "\r copying."
rm -f -r build/Car/
printf "\r copying.."
mkdir build/Car/ &> /dev/null
printf "\r copying..."
sudo chown -R manuel build/Car/ &> /dev/null
printf "\r copying...."
cp -r -a docs  build/Car/ &> /dev/null
printf "\r copying....."
cp -r -a examples build/Car/ &> /dev/null
printf "\r copying......"
cp -r -a src build/Car/ &> /dev/null
printf "\r copying......."
cp AUTHORS build/Car/ &> /dev/null
printf "\r copying........"
cp keywords.txt build/Car/ &> /dev/null
printf "\r copying........."
cp library.properties build/Car/ &> /dev/null
printf "\r copying.........."
cp README.md build/Car/ &> /dev/null
printf "\r copying..........."
cp LICENSE build/Car/ &> /dev/null
printf "\r copying............"
rm build/Car/docs/ELEGOO* &> /dev/null
printf "\r copying............."
rm build/Car/docs/README.md &> /dev/null
printf "\r copying.............."
rm build/Car/README.md &> /dev/null
printf "\r copying..............."
cp build/assets/README.md build/Car/ &> /dev/null 
printf "\r copying................\n"

cd build || exit &> /dev/null
zip Car Car/* &> /dev/null
cd .. &> /dev/null


printf "\r building"


printf "\r building."
arduino-cli lib install --zip-path build/Car.zip &> /dev/null
printf "\r building.."

cd build || exit
printf "\r building..."
cp -r Car ~/Arduino/libraries/
printf "\r building....\n"

if ! command -v arduino-cli &> /dev/null
then
    printf "arduino-cli: could not be found \n !!!Please install it!!! \n Use sudo snap install arduino-cli"
    exit
fi

printf " Done!\n"

