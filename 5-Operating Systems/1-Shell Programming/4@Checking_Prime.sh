#!/bin/bash
echo "Enter the number: "
read a
if [ $((a % 2)) -eq 0 ]; then
    echo "Not Prime"
else
    i=3
    while [ $((i * i)) -le $a ]; do
        if [ $((a % i)) -eq 0 ]; then
            echo "Not Prime"
            break
        fi
        i=$(expr $i + 2)
    done
    if [ $((i * i)) -gt $a ]; then
        echo "Prime"
    fi
fi
