#ifndef __CUSTOM_FILE_REQUEST_H__
#define __CUSTOM_FILE_REQUEST_H__

#include "cocos2d.h"
#include "network/HttpRequest.h"
#include <string>
#include <vector>

class FileRequestListener;

class CustomFileRequest
{
private:
    cocos2d::network::HttpRequest *request;
    std::vector<FileRequestListener*> listeners;

public:
    CustomFileRequest();
    ~CustomFileRequest();

    cocos2d::network::HttpRequest* getRequest() const;

    CustomFileRequest &addFileRequestListener(FileRequestListener *listener);

    CustomFileRequest &setUrl(const std::string &url);

    CustomFileRequest &setRequestType(cocos2d::network::HttpRequest::Type type);

    void toSend();

    void toSend(const std::string &url);

};

#endif//__CUSTOM_FILE_REQUEST_H__