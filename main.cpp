//
//  main.cpp
//  sudoku
//
//  alexandria pawlik
//  1 june 2017
//  programming b final
//

#include <iostream>
#include <string>  //for arrays
#include <algorithm>  //for random shuffle
#include <locale>  //for toupper
#include <cstdlib>  //for random
#include <ctime>  //for randomization

using namespace std;  //standard

////////////////////////////////////////////////////////////////////////////////////

/*
    0  1  2  - 3  4  5  - 6  7  8
    9  10 11 - 12 13 14 - 15 16 17
    18 19 20 - 21 22 23 - 24 25 26
    -- -- -- - -- -- -- - -- -- --
    27 28 29 - 30 31 32 - 33 34 35
    36 37 38 - 39 40 41 - 42 43 44
    45 46 47 - 48 49 50 - 51 52 53
    -- -- -- - -- -- -- - -- -- --
    54 55 56 - 57 58 59 - 60 61 62
    63 64 65 - 66 67 68 - 69 70 71
    72 73 74 - 75 76 77 - 78 79 80
 */

////////////////////////////////////////////////////////////////////////////////////

void printGrid(char toPrint[]){

    cout << "A| " << toPrint[0] << " " << toPrint[1] << " " << toPrint[2] << " | "
        << toPrint[3] << " " << toPrint[4] << " " << toPrint[5] << " | "
        << toPrint[6] << " " << toPrint[7] << " " << toPrint[8] << endl;
    cout << "B| " << toPrint[9] << " " << toPrint[10] << " " << toPrint[11] << " | "
        << toPrint[12] << " " << toPrint[13] << " " << toPrint[14] << " | "
        << toPrint[15] << " " << toPrint[16] << " " << toPrint[17] << endl;
    cout << "C| " << toPrint[18] << " " << toPrint[19] << " " << toPrint[20] << " | "
        << toPrint[21] << " " << toPrint[22] << " " << toPrint[23] << " | "
        << toPrint[24] << " " << toPrint[25] << " " << toPrint[26] << endl;
    cout << " |-------|-------|-------" << endl;
    cout << "D| " << toPrint[27] << " " << toPrint[28] << " " << toPrint[29] << " | "
        << toPrint[30] << " " << toPrint[31] << " " << toPrint[32] << " | "
        << toPrint[33] << " " << toPrint[34] << " " << toPrint[35] << endl;
    cout << "E| " << toPrint[36] << " " << toPrint[37] << " " << toPrint[38] << " | "
        << toPrint[39] << " " << toPrint[40] << " " << toPrint[41] << " | "
        << toPrint[42] << " " << toPrint[43] << " " << toPrint[44] << endl;
    cout << "F| " << toPrint[45] << " " << toPrint[46] << " " << toPrint[47] << " | "
        << toPrint[48] << " " << toPrint[49] << " " << toPrint[50] << " | "
        << toPrint[51] << " " << toPrint[52] << " " << toPrint[53] << endl;
    cout << " |-------|-------|-------" << endl;
    cout << "G| " << toPrint[54] << " " << toPrint[55] << " " << toPrint[56] << " | "
        << toPrint[57] << " " << toPrint[58] << " " << toPrint[59] << " | "
        << toPrint[60] << " " << toPrint[61] << " " << toPrint[62] << endl;
    cout << "H| " << toPrint[63] << " " << toPrint[64] << " " << toPrint[65] << " | "
        << toPrint[66] << " " << toPrint[67] << " " << toPrint[68] << " | "
        << toPrint[69] << " " << toPrint[70] << " " << toPrint[71] << endl;
    cout << "I| " << toPrint[72] << " " << toPrint[73] << " " << toPrint[74] << " | "
        << toPrint[75] << " " << toPrint[76] << " " << toPrint[77] << " | "
        << toPrint[78] << " " << toPrint[79] << " " << toPrint[80] << endl;
    cout << "   ----------------------" << endl << "   1 2 3   4 5 6   7 8 9" << endl << endl;

}//close printGrid

////////////////////////////////////////////////////////////////////////////////////

int dificultate(void){
    int dif;
 //rules section
    cout << "************************************************************************" << endl;
    cout << "Time to do some sudoku!" << endl;
    cout << "Just a few rules." << endl << endl;
    cout << "1. Cell rows are represented by letters. Cell columns are represented by numbers." << endl;
    cout << "2. Dots denote empty spaces." << endl;
    cout << "3. Given values cannot be edited." << endl;
    cout << "4. Hit Control+C to quit."<< endl;
    cout << "5. There are three difficulties. 1 is easiest, 3 is hardest." << endl << endl;
    cout << "Choose a difficulty: ";
    cin >> dif;
    return dif;
}

int dificultateaJocului(int userDiff){
    int diff;
    //convert difficulty
    switch (userDiff){
        case 1:
            diff = 48;  //about 40 givens
            cout << endl;
            return diff;
            break;
        case 2:
            diff = 30;  //about 26 givens
            cout << endl;
            return diff;
            break;
        case 3:
            diff = 20;  //about 17 givens
            cout << endl;
            return diff;
            break;
        default:
            cout << "Invalid character. Default difficulty is easy." << endl;
            diff = 48;
            return diff;
            break;
    }//close switch userDiff

}

int main(){



    //declare constant difficulty integer
    int diff;
    int userDiff = dificultate();
    diff = dificultateaJocului(userDiff);
    //prompt difficulty


    //convert difficulty
//    switch (userDiff){
//        case 1:
//            diff = 48;  //about 40 givens
//            cout << endl;
//            break;
//        case 2:
//            diff = 30;  //about 26 givens
//            cout << endl;
//            break;
//        case 3:
//            diff = 20;  //about 17 givens
//            cout << endl;
//            break;
//        default:
//            cout << "Invalid character. Default difficulty is easy." << endl;
//            diff = 48;
//            break;
//    }//close switch userDiff

    //lets play
    cout << "Let's play!" << endl << endl;

    //declare loop vars
    int stop = 1;  //1 = false
    char p;

    //randomize system
    srand((unsigned)time(NULL));  //seed random

    ////////////////////////////////////////////////////////////////////////////////////

    while(stop == 1){//loops game for user

        //declare
        char user[81];  //user answers, filled with * to start
        char current[81];  //to accept address of array from randomPuzzle

        //fill user
        for (int b = 0; b < 81; b++){
            user[b] = '.';
        }//close for

        ////////////////////////////////////////////////////////////////////////////////////

        //individual puzzle is generated
        //declare
        char puzzle[81] = {'.'};  //dummy generation variable

        //declare solution
        char master[81] = {'b','d','h','c','i','e','g','a','f','e','g','a','f','b','h','c','d','i','i','c','f','g','d','a','e','h','b','f','h','b','e','c','i','a','g','d','c','e','i','a','g','d','f','b','h','g','a','d','h','f','b','i','e','c','h','f','c','d','a','g','b','i','e','a','i','e','b','h','f','d','c','g','d','b','g','i','e','c','h','f','a'};
        //letters can represent any numbers

        //randomize base
        char base[9] = {'1','2','3','4','5','6','7','8','9'}; //values to assign in number order regardless of value
        random_shuffle(&base[0], &base[8]);

        //reassign
        for (int x = 0; x < 81; ++x){
            switch (master[x]){  //a is always the first term in base array, etc
                case 'a':
                    puzzle[x] = base[0];
                    break;
                case 'b':
                    puzzle[x] = base[1];
                    break;
                case 'c':
                    puzzle[x] = base[2];
                    break;
                case 'd':
                    puzzle[x] = base[3];
                    break;
                case 'e':
                    puzzle[x] = base[4];
                    break;
                case 'f':
                    puzzle[x] = base[5];
                    break;
                case 'g':
                    puzzle[x] = base[6];
                    break;
                case 'h':
                    puzzle[x] = base[7];
                    break;
                case 'i':
                    puzzle[x] = base[8];
                    break;
            }//close case master[x]
        }//close for

        //current[] = puzzle[]
        for (int h = 0; h < 81; h++){
            current[h] = puzzle[h];
        }//close for

        //printGrid(current);

        ////////////////////////////////////////////////////////////////////////////////////

        //set up user puzzle, seed random givens
        int seed[diff];
        for (int i = 0; i < diff; i++){
            seed[i] = rand() % 81;
        }//close for

        //display seeds
        for (int g = 0; g < diff; g++){
            user[seed[g]] = current[seed[g]];
        }//close for

        //print new puzzle
        printGrid(user);

        ///////////////////////////////////////////////////////////////////////////////////

        //all values in array are non-zero
        //condition is false, continue to ask for more guesses
        //condition is true, game is over, do one final check to current[]

        //continue condition
        int zeroes = 0;  //assume zeroes
        int oneZero = 1;  //assume no zeroes
        int countWrong = 0;  //counter for incorrect answers

        //declare game variables
        int xVal, newX, newY;  //x coordinate number, new converted to 0-8
        char yVal;  //y coordinate number
        int cell;  //coordinate math to find array index
        char userGuess;  //new value to be checked before inputted into puzzle image

        //loop user prompt
        while (zeroes == 0){

            //declare
            int okVal = 1, okayVal = 1; //1 false; ok x, okay y

            //while user row is unacceptable, prompt
            while (okVal == 1){//false

                xVal = 0;

                //get user input
                cout << "Choose a column to change (1-9): ";
                cin >> xVal;

                //check if accepted values
                if ((xVal == 1) or (xVal == 2) or (xVal == 3) or (xVal == 4) or (xVal == 5) or
                (xVal == 6) or (xVal == 7) or (xVal == 8) or (xVal == 9)){
                    okVal = 0;  //true
                }//close if
                else {
                    cin.clear();
                    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid column." << endl;
                }//close else

            }//close x while

            //while user row is unacceptable, prompt
            while (okayVal == 1){//false

                yVal = '0';

                //get user input
                cout << "Choose a row to change (a-i): ";
                cin >> yVal;

                //convert yVal for simplicity
                yVal = toupper(yVal);

                //check if accepted values
                if ((yVal == 'A') or (yVal == 'B') or (yVal == 'C') or (yVal == 'D') or (yVal == 'E')
                or (yVal == 'F') or (yVal == 'G') or (yVal == 'H') or (yVal == 'I')){
                    okayVal = 0;  //true
                }//close if
                else {
                    cin.clear();
                    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid row." << endl;
                }//close else

            }//close y while

            //convert coordinates
            newX = xVal - 1;  //to match array base 0
            switch (yVal){
                case 'A':
                    newY = 0;
                    break;
                case 'B':
                    newY = 1;
                    break;
                case 'C':
                    newY = 2;
                    break;
                case 'D':
                    newY = 3;
                    break;
                case 'E':
                    newY = 4;
                    break;
                case 'F':
                    newY = 5;
                    break;
                case 'G':
                    newY = 6;
                    break;
                case 'H':
                    newY = 7;
                    break;
                case 'I':
                    newY = 8;
                    break;
            }//close case yVal

            //find cell array # with matrix multiplication
            cell = (9 * newY) + newX;

            //prompt user for answer
            cout << "New value: ";
            cin >> userGuess;

            //check guess
            if (userGuess == current[cell]){
                cout << "Correct!" << endl << endl;
                user[cell] = current[cell];
                printGrid(user);  //filled in grid, prompt loops again
            }//close if
            else{
                cout << "Incorrect!" << endl << endl;  //no edit to grid, prompt loops again
                countWrong++;
                cin.clear();
            }//close else

            //check chars
            oneZero = 1;
            for (int v = 0; v < 81; v++){

                if (user[v] == '.'){
                    oneZero = 0;  //zero still present, true

                }//close if

            }//close for

            //exit zero while loop if array has no zeroes
            if (oneZero == 1){

                zeroes = 1;

            }//close if

        }//close zero while

        ////////////////////////////////////////////////////////////////////////////////////

        //declare final check
        int finalAnswer = 0; //assume all right

        //final check for correct answers
        for (int u = 0; u < 81; u++){
            if (user[u] != current[u]){
                finalAnswer = 1;  //answer is not correct if one cell is wrong
            }//close if
        }//close for

        if (finalAnswer == 1){
            cout << "Error. Puzzle is incorrect." << endl;
        }//close if
        else if (finalAnswer == 0){
            cout << "************************************************************************" << endl;
            cout << "Congratulations! You have completed this puzzle with only "
                << countWrong << " wrong guesses." << endl;
        }//close else if
//convert difficulty
    switch (userDiff){
        case 1:
            diff = 48;  //about 40 givens
            cout << endl;
            break;
        case 2:
            diff = 30;  //about 26 givens
            cout << endl;
            break;
        case 3:
            diff = 20;  //about 17 givens
            cout << endl;
            break;
        default:
            cout << "Invalid character. Default difficulty is easy." << endl;
            diff = 48;
            break;
    }//close switch userDiff
        //ask to play again
        cout << "Would you like to play again? (y/n): ";
        cin >> p;
        cout << "************************************************************************" << endl;


        //convert p
        p = toupper(p);

        if (p == 'N'){
            stop = 0;
        }//close if

    }//close while

    ////////////////////////////////////////////////////////////////////////////////////

    return 0;

}//close main



























