for i in {1..20}
do
./hw1.out < ./tests/$i.in > ./tests/my_$i.out
diff ./tests/$i.out ./tests/my_$i.out &> /dev/null
if [ $? -ne 0 ]; then
	echo "[FAILED] - Test $i"
else
	echo "[OK]  - Test $i"
fi
done
