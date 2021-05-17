gcc -Wall -Wextra -Werror main.c -o original

echo ""
echo "TEST - <ex_1>"
./original ./test/ex_1
echo ""
echo "TEST - <ex_2>"
./original ./test/ex_2
echo ""
echo "TEST - <ex_3>"
./original ./test/ex_3
echo ""
echo "TEST - <ex_4>"
./original ./test/ex_4
echo ""
echo "TEST - <NULL>"
./original
echo ""
echo "TEST - <Error file>"
./original ./test/ex

rm nooriginal
rm original