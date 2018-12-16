if [ "$#" -ne 2 ]; then
    echo "Error"
fi

num=10
s=0
while [ $num -lt 20 ]
do
if [ $((num%2)) != "0" ]
then
echo $num
((s+= num))
fi
(( num++ ))
done
echo $s
for entry in "$search_dir"/* "$work_dir"/*
do
  if [ -f "$entry" ];then
    echo "$entry"
  fi
done

echo "Enter Two numbers : "
read a 
read b 
  
echo "Enter Choice :"
read ch 
  
case $ch in
  +)echo $((a + b)) 
  ;; 
  -)echo $((a - b))  
  ;; 
  '*')echo $((a * b)) 
  ;; 
  /)echo $((a / b)) 
  ;;
  *) echo "Error";
esac