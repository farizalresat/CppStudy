#include <iostream>

using std::cout;
using std::left;
using std::right;

#include <iomanip>

using std::setw;

#include <cstdlib> // rand and srand
#include <ctime> // prototype for time

// prototype
void shuffle( int [][13]);
void deal( const int [][13], const char *[], const char *[]);

int main()
{
    // initialize suit array
    const char *suit[4] = {"Heart","Diamonds","Clubs","Spades"};

    // initialize face array
    const char *face[13] = {"Ace","Deuce","Three","Four","Five","Six","Seven",
                            "Eight","Nine","Ten","Jack","Queen","King"};

    //intialize deck array
    int deck[4][13] = {0};

    srand(time(0)); // seed random-number generator

    shuffle(deck);
    deal(deck,face,suit);

    return 0;
}

void shuffle(int wDeck[][13])
{
    int row;
    int column;

    // for each 53 cards, choose slot of deck randomly
    for (int card = 1; card <= 52; card++){

        // choose new random location until unoccupied slot found
        do {
            row = rand() % 4;
            column = rand() % 13;
            } while( wDeck[row][column] != 0); // end do
 
        // Place card number in chosen slot of deck
        wDeck[row][column] = card;
    
    } // end for
}

void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
    // for each of the 52 cards
    for (int card = 1; card <=52; card++)

        // loop through rows of wDeck
        for (int row = 0; row <=3; row++)

            // Loop through columns of wDeck for current row
            for (int column = 0; column <= 12; column++)
            {
                if(wDeck[row][column] == card){
                    cout << setw(5) << right 
                    << wFace[column] << " of " 
                    << setw(8) << left << wSuit[row] 
                    << (card%2 == 0? '\n':'\t');
                } // end if
                
            }
}