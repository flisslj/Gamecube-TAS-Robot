#! /bin/bash

#base=/home/pi/workspace/temp

mkfifo fifo0 fifo1

controller="/home/pi/workspace/Gamecube-TAS-Robot/controller-dev/src/controller 1 /home/pi/workspace/temp"
server="/home/pi/workspace/Gamecube-TAS-Robot/software-development/controllerserver/controllerserver"
#echo server commands created

$controller < fifo0 | $server > fifo0
#mkfifo fifo0 fifo1
#$server > fifo0 < fifo1 &
#$controller < fifo0 > fifo1

#pipexec -- [ A /home/pi/workspace/Gamecube-TAS-Robot/software-development/controllerserver/controllerserver -p 8080 ] [ B /home/pi/workspace/Gamecube-TAS-Robot/controller-dev/src/controller 1 /home/pi/workspace/temp ] "{A:1>B:0}" "{B:1>A:0}"

#pipexec -- "[A /home/pi/workspace/Gamecube-TAS-Robot/software-development/controllerserver/controllerserver -p 8080 ]" "[B /home/pi/workspace/Gamecube-TAS-Robot/controller-dev/src/controller 1 /home/pi/workspace/temp | tee ~/controller.sh ]" "{A:1>B:0}" "{B:1>A:0}"


#/home/pi/workspace/Gamecube-TAS-Robot/software-development/controllerserver/controllerserver -p 8080 > fifo0 <fifo1 &
#/home/pi/workspace/Gamecube-TAS-Robot/software-development/controllerserver/controllerserver -p 8080 > fifo0 <fifo1 &
