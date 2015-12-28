make re -C ..
echo "\n\033[93m1blk :\n\033[92m"
./PcsGen.py 1 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m5blk :\n\033[92m"
./PcsGen.py 5 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m9blk :\n\033[92m"
./PcsGen.py 9 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m13blk :\n\033[92m"
./PcsGen.py 13 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m17blk :\n\033[92m"
./PcsGen.py 17 > yo
time ./../fillit yo
rm yo
echo "\n\033[93m21blk :\n\033[92m"
./PcsGen.py 21 > yo
time ./../fillit yo
rm yo
echo "\n"
make fclean -C ..
