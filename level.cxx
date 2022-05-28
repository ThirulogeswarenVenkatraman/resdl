#include "include/level.h"
#include "include/tinyxml2.h"
#include "include/TextureManager.h"
#include "include/game.h"

using namespace tinyxml2;

Level::Level(std::string filename) 
{
    loadMap(filename);
}
 
void Level::loadMap(std::string filename) {

    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    
    XMLElement* mapNode = doc.FirstChildElement("map");

    mapNode->QueryIntAttribute("width", &this->columns);
    mapNode->QueryIntAttribute("height", &this->rows);
    
    mapNode->QueryIntAttribute("tilewidth", &this->tilewidth);
    mapNode->QueryIntAttribute("tileheight", &this->tileheight);

    XMLElement* tileset = mapNode->FirstChildElement("tileset");
    if(tileset != NULL) {
        while(tileset) {
            srcname = (std::string)tileset->Attribute("name");
            std::string imgsrc = "assets/" + (std::string)tileset->FirstChildElement("image")->Attribute("source");
            tileset->FirstChildElement("image")->QueryIntAttribute("width", &tilesetwidth);
            tileset->FirstChildElement("image")->QueryIntAttribute("height", &tilesetheight);

            TextureManager::getInstance()->LoadTileSet(imgsrc, srcname, game::getInstance()->getRenderer());
            int GID;
            tileset->QueryIntAttribute("firstgid", &GID);
            for( int i = 0; i < (tilesetheight/tileheight); i++) { 
                for ( int j = 0; j < (tilesetwidth/tilewidth); j++) {
                    m_tiles[GID] = (tile){ srcname, j, i};
                    GID++;
                }
            }
            // points to the next tileset if any
            tileset = tileset->NextSiblingElement("tileset");
        }
    }
    
    // getting Layer 
    XMLElement* layer = mapNode->FirstChildElement("layer");
    if(layer != NULL) {
        while(layer) {
            XMLElement* data = layer->FirstChildElement("data");
            if(data != NULL) {
                while(data) {
                    XMLElement* tile = data->FirstChildElement("tile");
                    if(tile != NULL) {
                        while(tile) {

                            int GID = 0;
                            tile->QueryIntAttribute("gid", &GID);
                            gid.push_back(GID);

                            tile = tile->NextSiblingElement("tile");
                        }
                    }
                    data = data->NextSiblingElement("data");
                }
            }
            // points to next layer if any
            layer = layer->NextSiblingElement("layer");
        }
    }
    
}

void Level::drawLevel() {
    int inx = 0;
    for ( int i = 0; i < rows; i++) {
        for( int j = 0; j < columns; j++) {
            int ID = gid.at(inx);
            if(ID) {
                TextureManager::getInstance()->DrawTile(m_tiles.at(ID).srcname, j, i, tilewidth, tileheight, 
                m_tiles.at(ID).x_offset, m_tiles.at(ID).y_offset, game::getInstance()->getRenderer());
            }inx++;
        }
    }
}

void Level::freeLevel() {
    TextureManager::getInstance()->freeTileSet(srcname);
}