#include "spie.cpp"
using namespace std;

int main() {
    SPIE_Game game; //removed () #2 compiler
    game.print_rules(cout);
    game.print_winning_numbers(cout); // added cout argument #3 compiler

    int score = 5;
    char choice = 'p';

    while (choice != 'e') { // added brackets around switch #4 compiler
        choice = game.get_player_choice(cout, cin);

        switch (choice) {
            case 's':
                game.scramble(cout);
                break;
            case 'i':
                game.print_rules(cout);
                break;
            case 'p':
                cout << "Your score is " << score << endl;
                game.print_winning_numbers(cout);
                int dice_roll = game.roll_dice();
                cout << "Your dice roll is: " << dice_roll << endl;
                if (dice_roll == 2 || dice_roll == 12) {
                    game.add_winning_number();
                    cout << "You added a winning number!" << endl;
                    game.print_winning_numbers(cout);
                }
                if (game.matches_winning_number(dice_roll)) {
                    cout << "You won this round!" << endl;
                    score += 5;
                } else {
                    cout << "You lost this round!" << endl;
                    --score;
                    if (score == 0) {
                        choice = 'e';
                    }
                }
                cout << "Your new score is " << score << endl;

        }
    }

    if (score == 0) {
        cout << "You lost the game!" << endl;
    } // added ending bracket to if statement #6 compiler
    else {
        cout << "Play again soon!" << endl;
    }

} // added ending bracket to main #5 compiler

