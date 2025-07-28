#!/bin/bash
 
server_start() {
echo "LYD ist an!:)"
screen -d -m -L -S LYD ./lydserver
} 
 
server_stop() {
killall lydserver
echo "LYD aus"
} 
 
server_restart() {
server_stop
sleep 1
server_start
}
case "$1" in
'start')
server_start
;;
'stop')
server_stop
;;
'restart')
server_restart
;;
*)
echo "--> $0 start|stop|restart"
echo "nö"
esac
