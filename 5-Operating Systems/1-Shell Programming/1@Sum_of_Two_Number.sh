#!/bin/sh
echo "Enter the value of a: "
read a
echo "Enter the value of b: "
read b
val=`$a + $b`
echo "a+b=$val"
val=$((a - b))
echo "a-b=$val"
val=$((a * b))
echo "a*b=$val"
val=$((a / b))
echo "a/b=$val"
