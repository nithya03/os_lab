//Shell program to check the given number is even or odd.
echo "Enter the Number" 
read n 
r=`expr $n % 2` 
if [ $r -eq 0 ] 
then 
echo "$n is Even number" 
else 
echo "$n is Odd number" 
fi
