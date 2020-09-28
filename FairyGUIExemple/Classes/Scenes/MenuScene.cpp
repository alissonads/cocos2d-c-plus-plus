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
#include "Custom/ItemListBuilder.h"
#include "Custom/EspecialistLoader.h"

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

void MenuScene::addCompentList(const std::string &imageUrl,
                               const std::string &musicName,
                               const std::string &artistName)
{
    auto list = view->getChild("list")->as<GList>();
    auto obj = UIPackage::createObject("Menu", "item_list")->as<GComponent>();

    auto loader = obj->getChild("loader")->as<GLoader>();
    loader->setAutoSize(false);
    loader->setURL(imageUrl);
    loader->setScale(0.35f, 0.35f);
    
    auto text = obj->getChild("musicName");
    text->setText(musicName);

    text = obj->getChild("artistName");
    text->setText(artistName);

    obj->addClickListener([text](EventContext* context){
        log("Kit %s", text->getText().data());
    });

    list->addChild(obj);
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

    UIObjectFactory::setLoaderExtension([](){
        return EspecialistLoader::create();
    });

    request = new CustomFileRequest();
    request->addFileRequestListener(this)
           .toSend("https://api.kondzilla.opalastudios.com/api/fetch?version=4");

    close();
}

void MenuScene::applyData(const std::vector<char> &buffer)
{
    rapidjson::Document document;
    document.Parse(const_cast<char*>(buffer.data()));
    
    if(document.HasMember("kits") && document["kits"].IsArray())
    {
        auto arr = document["kits"].GetArray();
        auto itr = arr.Begin();
        //auto obj = itr->GetObject();

        for (auto itr = arr.Begin(); itr != arr.end(); ++itr)
        {
            auto obj = itr->GetObject();

            addCompentList(obj["imageUrl"].GetString(), 
                           obj["musicName"].GetString(), 
                           obj["authorName"].GetString());
        }
    }
}