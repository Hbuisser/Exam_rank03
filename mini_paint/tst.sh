gcc -Wall -Wextra -Werror -lm main.c -o original

echo ""
echo "TEST - <ex_1>"
./original ./test/ex_1
echo ""
echo "TEST - <ex_2>"
./original ./test/ex_2
echo ""
echo "TEST - <NULL>"
./original
echo ""
echo "TEST - <Error file>"
./original ./test/ex

rm original