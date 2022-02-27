#!/bin/bash

archi=$(uname -a)
cpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=$(grep "processor" /proc/cpuinfo | wc -l)
mem_total=$(free -m | grep ^Mem | awk '{print $2}')
mem_used=$(free -m | grep ^Mem | awk '{print $3}')
percent_mem_used=$(echo "${mem_used} ${mem_total}" | awk '{printf "%.2f", $1 / $2 * 100}')
disk_total=$(df -P | grep -v ^Filesystem | awk '{sum += $2} END {printf "%.0f", sum / 1024 / 1024}')
disk_used=$(df -P | grep -v ^Filesystem | awk '{sum += $3} END {printf "%.0f", sum / 1024}')
percent_disk_used=$(df -P | grep -v ^Filesystem | awk '{used += $3} {total+= $2} END {printf "%d", used / total * 100}')
cpu_load=$(top -b -n1 | grep ^%Cpu | awk '{print 100 - $8}')
last_boot=$(who -b | awk '{printf "%s %s", $3, $4}')
lvm_count=$(lsblk | grep lvm | wc -l)
lvm_check=$(if [ ${lvm_count} -eq 0 ] ; then echo "no"; else echo "yes"; fi)
tcp_connections=$(ss -t | grep ESTAB | wc -l)
user_count=$(users | wc -w)
ip_addr=$(hostname -I | awk '{print $1}')
mac_addr=$(ip addr | grep link/ether | awk '{print $2}')
sudo_commands=$(grep sudo /var/log/auth.log | grep COMMAND | wc -l)
wall "	#Architecture : ${archi}
	#CPU physical : ${cpu}
	#vCPU : ${vcpu}
	#Memory Usage : ${mem_used}/${mem_total}MB (${percent_mem_used}%)
	#Disk Usage : ${disk_used}/${disk_total}GB (${percent_disk_used}%)
	#CPU load : ${cpu_load}%
	#Last boot : ${last_boot}
	#LVM use : ${lvm_check}
	#Connections TCP : ${tcp_connections} ESTABLISHED
	#User log : ${user_count}
	#Network : IP ${ip_addr} (${mac_addr})
	#Sudo : ${sudo_commands} cmd"
