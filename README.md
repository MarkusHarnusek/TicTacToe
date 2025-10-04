# Tic Tac Toe

This is a simple tic tac toe game for c. It features a two player mode with custom player names as well as a algorithmic oponent for the singleplayer.

## How to run it

If you are on linux compile it using the following command `gcc TicTacToe.c -std=c17 -o TicTacToe` and then run it using `./TicTacToe`

## Requirements

- **`gcc`**: The gcc compiler is necessary for compiling the project for the system specific hardware. For apt install it by first updating the package list with `sudo apt update` and then install it by using `sudo apt install gcc`
- **File being executable**: In order to run the project the file needs to have the executable permission for the current user / group. Check this by checking the permission bits when using `ls -al` and change it if necessary using `chmod -x <file-name>`
