#!/bin/bash
. ./summ

echo "введите x"
read x
echo "введите y"
read y

echo "$x + $y = $(summ $x $y)"

awk '{
total = 0
i = 1
i1 = 0
while ($i != null)
{
total += $i
i++
i1++
}
avg = total / i1
print "Average: ", avg
}' path
