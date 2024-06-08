//
// Created by pawel on 08.06.2024.
//

#ifndef SCORETRACKER_SCORETRACKER_H
#define SCORETRACKER_SCORETRACKER_H

#include "API.h"
#include "fstream"

class ScoreTracker {
private:
    static int destroyedBricks;
    static int balBounces;
    static int lostBalls;
    static int wins;
public:
   // ScoreTracker();
    static void brickDestroyed();
    static void ballBounced();
    static void ballLost();
    static void gameWon();
    static int getDestroyedBricks();
    static int getBalBounces();
    static int getLostBalls();
    static int getWins();
    static void reset();
    static void saveToFile(const std::string& filename);
};



#endif //SCORETRACKER_SCORETRACKER_H
