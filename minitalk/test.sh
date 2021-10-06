#!/bin/bash

test_text=$(cat longtext.txt)

echo "input server PID"

read server_pid

./client ${server_pid} "${test_text}"
