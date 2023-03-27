#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - check initial stack"){
   Player p1("Alice");
   Player p2("Bob");
   Game game(p1,p2);
   CHECK(p1.stacksize() == 26);
   CHECK(p2.stacksize() == 26);
   CHECK(p1.stacksize() - p2.stacksize() == 0);

}

TEST_CASE("Test 2 - After playTurn"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playTurn();
    CHECK(p1.stacksize() < 26);
    CHECK(p2.stacksize() < 26);
}

TEST_CASE("Test 3 - Play All stack size"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    CHECK_THROWS(game.playTurn());
}

TEST_CASE("Test 4 - Play All cardes taken"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    game.playAll();
    CHECK(p1.cardesTaken() + p2.cardesTaken() == 52);
 }

 TEST_CASE("Test 5 - Constructor"){
    Player p1("Alice");
    Player p2("Bob");
    CHECK_NOTHROW(Game(p1,p1));
 }

 TEST_CASE("Test 6 - playTurn with empty hand"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for(int i = 0; i < 52; i++){
        game.playTurn();
    }
    CHECK_NOTHROW(game.playTurn());
 }

 TEST_CASE("Test 7 - playAll with winner "){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for(int i = 0; i < 26; i++){
        game.playTurn();
    }
    game.playAll();
    CHECK_NOTHROW(game.printWiner());
 }

 TEST_CASE("Test 8 - printLastTurn"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("Test 9 - printLog"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printLog());
}

TEST_CASE("Test 10 - printStats"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.printStats());
}

TEST_CASE("Test 11 - No cards?"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playTurn());
}

TEST_CASE("Test 12 - check if game ends after 5 rounds"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);
    for(int i = 0; i < 5; i++)
        game.playTurn();
    CHECK_NOTHROW(game.playTurn());
    CHECK(p1.stacksize() < 22);
    CHECK(p2.stacksize() < 22);
}

TEST_CASE("Test 13 - game options"){
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1,p2);

    CHECK_NOTHROW(game.playAll());
    CHECK_NOTHROW(game.printWiner());

}
    



