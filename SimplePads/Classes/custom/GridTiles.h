#ifndef __GRID_TILES_H__
#define __GRID_TILES_H__

#include "cocos2d.h"
#include <vector>
#include <string>

class GridTiles
{
private:
    std::vector<std::string> images;
    int *map;
    int lines, columns;
    cocos2d::Vec2 iniPos;
    cocos2d::Vec2 offset;
    cocos2d::Size sizeTiles;
    cocos2d::Vec2 point;
    bool uniqueImage;

public:
    GridTiles();
    ~GridTiles();

    GridTiles &addImage(const std::string &path);
    GridTiles &addImages(std::initializer_list<std::string> list);
    GridTiles &removeImages(const std::string &path);
    GridTiles &setImages(const std::vector<std::string> &images);
    GridTiles &setRenderingMap(int *map, const int lines, const int columns);
    GridTiles &setInitPos(const cocos2d::Vec2 &iniPos);
    GridTiles &setOffset(const cocos2d::Vec2 &offset);
    GridTiles &setSizeTiles(const cocos2d::Vec2 &sizeTiles);
    GridTiles &setUniqueImage(const std::string &path);
    GridTiles &setAnchorPoint(const cocos2d::Vec2 &point);
    void apply(cocos2d::Scene &scene);
};

#endif//__GRID_TILES_H__