#include "MenuScene.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
#include "network/HttpResponse.h"
#include "external/json/document.h"
#include "external/json/rapidjson.h"
#include "external/json/writer.h"
#include "external/json/reader.h"
#include "external/json/stringbuffer.h"
#include "Custom/CustomFileRequest.h"
#include <vector>

USING_NS_CC;
USING_NS_FGUI;

using namespace network;

MenuScene::MenuScene() : SceneBase(),
            request(nullptr)
{}

MenuScene::~MenuScene()
{
    if (request)
    {
        delete request;
        request = nullptr;
    }
}

void MenuScene::close()
{
    view->getChild("close")->addClickListener([](EventContext*) {
        Director::getInstance()->end();
    });
}

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

void MenuScene::config()
{
    UIPackage::addPackage("images/Menu");
    view = UIPackage::createObject("Menu", "main")->as<GComponent>();
    groot->addChild(view);

    request = new CustomFileRequest();
    request->addFileRequestListener(this)
           .dispatch("https://api.kondzilla.opalastudios.com/api/fetch?version=4");

    close();
}

void MenuScene::update(rapidjson::Document &document)
{

}