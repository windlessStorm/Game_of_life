#ifndef LIFE_H
#def LIFE_H

class Grid {
    bool grid[GRIDSIZE][GRIDSIZE], stable;
    int generation;
    public:
        Grid();
        void printFrame();
        void nextFrame();
        void play();
        bool isExtinct();
        bool isStable();
};

#endif
