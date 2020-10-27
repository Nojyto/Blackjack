#include <time.h>
#include <algorithm>
#include <vector>

std::vector<int> deck;

void generateDeck()
{
    for(int i = 0; i < 6; i++)
        for(int suit = 0; suit < 4; suit++)
            for(int value = 1; value <= 13; value++)
                value <= 11 ? deck.push_back(value) : deck.push_back(10);

    srand(time(NULL));
    for(unsigned int i = deck.size() - 1; i > 0; i--)
        std::swap(deck[i], deck[rand() % (i + 1)]);
}

void hit(int &points){
    if(deck.back() == 1 && deck.back() + 11 <= 21) points += 11;
    else points += deck.back();
    deck.pop_back();
}

void printScreen(int playerPoints, int computerPoints)
{
    system("cls");
    printf("Dealer's hand: %u\n", computerPoints);
    printf("Player's hand: %u\n", playerPoints);
}

int main()
{
    generateDeck();

    int playerPoints, computerPoints;

    computerPoints = deck.back();
    deck.pop_back();
    playerPoints = deck.back();
    deck.pop_back();
    computerPoints = deck.back();
    deck.pop_back();

    while(true){
        char isHit;
        printScreen(playerPoints, computerPoints);

        if(playerPoints == 21){
            printf("You win!\n");
            break;
        }else if(playerPoints > 21){
            printf("You lose!\n");
            break;
        }

        printf("Hit or stand? ");
        scanf(" %c", &isHit);

        if(isHit != 'H' && isHit != 'h'){
            while(computerPoints < 17)
                hit(computerPoints);

            if(computerPoints > playerPoints && computerPoints <= 21){
                printScreen(playerPoints, computerPoints);
                printf("You lose.\n");
                break;
            }else{
                printScreen(playerPoints, computerPoints);
                printf("You win!\n");
                break;
            }
        }else
            hit(playerPoints);
    }
}
