#!/bin/bash
echo "Enter the first string: "
read s1
echo "Enter the second string: "
read s2
echo "Concatenated string: "
s1+=$s2
echo $s1
