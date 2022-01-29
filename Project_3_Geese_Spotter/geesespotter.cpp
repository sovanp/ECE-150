#include "geesespotter_lib.h"

char * createBoard(std::size_t xdim, std::size_t ydim) {
    char * new_board = new char[xdim * ydim];
    for (int i = 0; i < (xdim * ydim); i++) {
        new_board[i] = 0;
    }
    return new_board;
}

//For one field
void computeNeighborsHelper(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    int counter = 0;
    //board[yloc * xdim + xloc] will go one full row, then the xloc will take as far as you need

    //Check if field has a goose in this field
    if((board[yloc * xdim + xloc] & valueMask()) == 0X09) {
        //Ignore it
        return;
    }
    //Check 8 surrounding fields
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            //checking if neighbour is inside field
            if (((yloc + j) >= 0) && ((yloc + j) < ydim) && ((xloc + 1) >= 0) && ((xloc + i) < xdim)) {
                //j goes from -1 to 1 and i goes from -1 to 1
                if ((board[(yloc + j) * xdim + xloc + i] & valueMask()) == 0X09) {
                    counter++;
                }
            }
        }
    }
    board[yloc * xdim + xloc] += counter;
}

void computeNeighbors(char * board, std::size_t xdim, std::size_t ydim) {
    //formulas to show location using 1d array
    // yloc = index / xdim
    // xloc = index % xdim

    //Go through each field and call helper function
    for (int index = 0; index < (xdim * ydim); index++) {
        computeNeighborsHelper(board, xdim, ydim, index%xdim, index/xdim);
    }
}

void hideBoard(char * board, std::size_t xdim, std::size_t ydim) {
    for (int i = 0; i < (xdim * ydim); i++) {
        //Hide all bits
        board[i] |= hiddenBit();
    }
}

void cleanBoard(char * board) {
    delete[] board;
    board = nullptr;
}

void printBoard(char * board, std::size_t xdim, std::size_t ydim) {
    //Calculate the location of field on the board
    int location_index = 0;
    for (int i = 0; i < xdim; i++) {
        for (int j = 0; j < ydim; j++) {
            if ((board[location_index] & markedBit()) == markedBit()) {
                std::cout << "M";
            }
                //Check if the bit stored at field is hidden
            else if ((board[location_index] & hiddenBit()) == hiddenBit()) {
                std::cout << "*";
            }
            else {
                //Typecast to int
                std::cout << board[location_index] + '0'; //valueMask not necessary
            }
            location_index++;
        }
        std::cout << std::endl;
    }
//    std::cout << std::endl;

    //hiddenBit() ---> 0x20 = 0010 0000     markedBit() ---> 0x10 = 0001 0000
    // location binary: 0010 0001           location binary: 0011 0001
    // hiddenBit():     0010 0000           markedBit():     0001 0001
    // ==========================           ==========================
    // &                0010 0000           &                0001 0000
}

int reveal(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    int reveal_x, reveal_y;

    //Check if field is marked
    if ((board[yloc * xdim + xloc] & markedBit()) == markedBit()) {
        return 1;
    }

        //Check if field is already revealed
    else if ((board[yloc * xdim + xloc] & hiddenBit()) == 0) {
        return 2;
    }

        //If field contains goose, reveal fields then return 9
    else if ((board[yloc * xdim + xloc] & valueMask()) == 0X09) {
        board[reveal_y * xdim + reveal_x] = (board[reveal_y * xdim + reveal_x] & valueMask());
        return 9;
    }

        //Case where adjacency value is 0
    else if ((board[yloc * xdim + xloc] & hiddenBit()) == 0) {
        if ((board[yloc * xdim + xloc] & valueMask()) == 0) {
            //Scan all 9 spaces around the xloc and yloc
            for (reveal_y = (yloc - 1); reveal_y <= (yloc + 1); reveal_y++) {
                for (reveal_x = (xloc - 1); reveal_x <= (xloc + 1); reveal_x++) {
                    //Check if field is still on the board
                    if ((reveal_x < xdim) && (reveal_y < ydim) && (reveal_x >= 0) && (reveal_y >= 0)) {
                        //Check if board is marked, if marked leave alone, if not continue
                        if ((board[reveal_y * xdim + reveal_x] & markedBit()) == 0) {
                            //Statement to actually reveal space on the board
                            board[reveal_y * xdim + reveal_x] = (board[reveal_y * xdim + reveal_x] & valueMask());
                        }
                    }
                }
            }
        }
        return 0;
    }
}

int mark(char * board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    int index_location = (yloc * xdim) + xloc;

    if ((board[index_location] & markedBit()) != markedBit()) {
        board[index_location] |= markedBit();
        return 0;
    }
        //Checking if field is hidden or not
    else if ((board[index_location] & hiddenBit()) != hiddenBit()) {
        return 2;
    }
}

bool isGameWon(char * board, std::size_t xdim, std::size_t ydim) {
//    int index = 0;
//    for (int i = 0; i < xdim; i++) {
//        for (int j = 0; j < ydim; j++) {
//            //if field does not contain goose and is not revealed, then false;
//            if (((board[index] & valueMask()) != 9) && ((board[index] & hiddenBit()) == 0)) {
//                return false;
//            }
//            else {
//                //Game is won
//                return true;
//            }
//        }
//    }
    return false;
}