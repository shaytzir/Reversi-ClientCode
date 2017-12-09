//
// Shay Tzirin
// ID: 315314930
// Yuval Hoch
// ID: 204468474
//

#include <gtest/gtest.h>
#include "../include/ReversiRules.h"
#include "../include/HumanP.h"
#include "../include/Console.h"

namespace {
    class Test_ReversiRules: public testing::Test {
    public:
        Test_ReversiRules(): rules(new HumanP('X'), new HumanP('O'), new Console()){};

    protected:
        ReversiRules rules;

    };
}
/**
 * checking game is over when the board is full or both of players
 * have no more moves
 */
TEST_F(Test_ReversiRules, isGameOver) {
//at the start of the game, it cant be over - there are two cells of each player
EXPECT_FALSE(rules.gameover());

Board b = new Board(8,8,'X','O');
for (int i = 0 ; i < b.getWidth(); i++) {
for (int j = 0; j < b.getHeight(); j++) {
rules.setPlayerDisk(i,j);
}
}
EXPECT_TRUE(rules.gameover());

}
/**
 * checks all of the following inputs are not valid for an option
 */
TEST_F(Test_ReversiRules, InvalidOptionToChoose)  {
EXPECT_FALSE(rules.thisIsAOption("1.1"));
EXPECT_FALSE(rules.thisIsAOption("0,0"));
EXPECT_FALSE(rules.thisIsAOption("-1,0"));
EXPECT_FALSE(rules.thisIsAOption("2.5,7"));
EXPECT_FALSE(rules.thisIsAOption("a,b"));
EXPECT_FALSE(rules.thisIsAOption("2,5,6"));
}



