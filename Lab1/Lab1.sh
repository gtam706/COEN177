# Name: Gautam Samudrala
# Date: September 23rd 2022
# Title: Lab1 – Unix/Linux Commands and Basic Shell Programming 
# Description: This program calculates the area of circle and rectangle
#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "gautamsamudrala" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi
response="Yes"
while [ $response != "No" ]
do
        echo "Calculate area of Rectangle or Circle?"
        read option
        if [ $option = "Rectangle" ];
        then
            echo "Enter height of rectangle: "
            read height
            echo "Enter width of rectangle: "
            read width
            area=`expr $height \* $width`
            echo "The area of the rectangle is $area"
        elif [ $option = "Circle" ];
        then
            echo "Enter radius of Circle"
            read radius
            echo "The area of the circle is $area"
            echo "3.14 * $radius * $radius" | bc
        else
            echo "Invalid Response"
        fi
        echo "Would you like to repeat for another shape [Yes/No]?"
        read response
done