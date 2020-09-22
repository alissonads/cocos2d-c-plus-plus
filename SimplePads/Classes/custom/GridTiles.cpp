#include "GridTiles.h"

USING_NS_CC;

GridTiles::GridTiles() :
            images(), map(nullptr),
            lines(0), columns(0),
            iniPos(Vec2::ZERO), 
            offset(Vec2::ZERO),
            sizeTiles(Size()),
            point(Vec2(0.5f, 0.5f)),
            uniqueImage(false)
{
}

GridTiles::~GridTiles()
{
    images.clear();
}

GridTiles &GridTiles::addImage(const std::string &path)
{
    images.push_back(path);

    return (*this);
}

GridTiles &GridTiles::addImages(std::initializer_list<std::string> list)
{
    images = list;

    return (*this);
}

GridTiles &GridTiles::removeImages(const std::string &path)
{
    int i = 0;
    int size = images.size();

    for (i = 0; i < size; i++)
    {
        if (images[i] == path)
            break;
    }

    images.erase(images.begin() + i);

    return (*this);
}

GridTiles &GridTiles::setImages(const std::vector<std::string> &images)
{
    this->images = images;

    return (*this);
}

GridTiles &GridTiles::setRenderingMap(int *map, const int lines, const int columns)
{
    this->map = map;
    this->lines = lines;
    this->columns = columns;

    return (*this);
}

GridTiles &GridTiles::setInitPos(const cocos2d::Vec2 &iniPos)
{
    this->iniPos = iniPos;

    return (*this);
}

GridTiles &GridTiles::setOffset(const cocos2d::Vec2 &offset)
{
    this->offset = offset;

    return (*this);
}

GridTiles &GridTiles::setSizeTiles(const cocos2d::Vec2 &sizeTiles)
{
    this->sizeTiles = sizeTiles;

    return (*this);
}

GridTiles &GridTiles::setUniqueImage(const std::string &path)
{
    images.push_back(path);
    uniqueImage = true;

    return (*this);
}

GridTiles &GridTiles::setAnchorPoint(const cocos2d::Vec2 &point)
{
    this->point = point;

    return (*this);
}

void GridTiles::apply(cocos2d::Scene &scene)
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
        {

            Sprite *sprite = nullptr;

            if (uniqueImage)
                sprite = Sprite::create(images[0]);
            else
                sprite = Sprite::create(images[map[(i * columns) + j]]);

            sprite->setAnchorPoint(point);
            sprite->setPosition(iniPos.x + (sizeTiles.width + offset.x)*j, 
                                iniPos.y - (sizeTiles.height + offset.y)*i);
            scene.addChild(sprite);
        }
}