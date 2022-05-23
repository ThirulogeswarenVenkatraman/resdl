#ifndef LEVEL
#define LEVEL

#include <string>
#include <iostream>
#include <vector>
#include <map>

typedef struct {
	int x_offset;
	int y_offset;
} tile;

class Level {
    std::string srcname;
    std::vector<int> gid;
    std::map<int, tile> m_tiles;

    int columns; 
    int rows;
    int tilewidth; int tileheight;
    int tilesetwidth; int tilesetheight;

    void loadMap(std::string filename);
public:
    Level(std::string filename);
    void drawLevel();
    void freeLevel();
};

#endif
