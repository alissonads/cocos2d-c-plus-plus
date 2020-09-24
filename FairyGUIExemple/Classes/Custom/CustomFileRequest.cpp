#include "CustomFileRequest.h"
#include "FileRequestListener.h"
#include "network/HttpClient.h"
#include "network/HttpResponse.h"
#include "external/json/document.h"
#include "external/json/rapidjson.h"
#include "external/json/writer.h"
#include "external/json/reader.h"
#include "external/json/stringbuffer.h"

USING_NS_CC;

using namespace network;

CustomFileRequest::CustomFileRequest() :
                    request(new (std::nothrow) HttpRequest())

{}

CustomFileRequest::~CustomFileRequest()
{
    if (request)
    {
        //delete request;
        //request = nullptr;
    }

    listeners.clear();
}

 HttpRequest* CustomFileRequest::getRequest() const
 {
     return request;
 }

CustomFileRequest &CustomFileRequest::addFileRequestListener(FileRequestListener *listener)
{
    listeners.push_back(listener);
    return (*this);
}

CustomFileRequest &CustomFileRequest::setUrl(const std::string &url)
{
    request->setUrl(url);
    return (*this);
}

CustomFileRequest &CustomFileRequest::setRequestType(HttpRequest::Type type)
{
    request->setRequestType(type);
    return (*this);
}

void CustomFileRequest::dispatch()
{
    request->setResponseCallback([this](HttpClient* sender, HttpResponse* response) {
        if (response->isSucceed())
        {
            auto buffer = response->getResponseDataString();

            rapidjson::Document document;
            document.Parse(buffer);

            for (auto listener : this->listeners)
            {
                listener->update(document);
            }
        }
    });

    HttpClient::getInstance()->sendImmediate(request);
    request->release();
}

void CustomFileRequest::dispatch(const std::string &url)
{
    request->setUrl(url);
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback([this](HttpClient* sender, HttpResponse* response) {
        if (response->isSucceed())
        {
            auto buffer = response->getResponseDataString();

            rapidjson::Document document;
            document.Parse(buffer);

            int size = listeners.size();

            for(int i = 0; i < size; i++)
            {
                listeners[i]->update(document);
            }
        }
    });

    HttpClient::getInstance()->sendImmediate(request);
    request->release();
}
