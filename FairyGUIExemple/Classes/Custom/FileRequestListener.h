#ifndef __FILE_REQUEST_LISTENER_H__
#define __FILE_REQUEST_LISTENER_H__

#include "external/json/document.h"

class FileRequestListener
{
public:
    virtual ~FileRequestListener() {}

    virtual void update(rapidjson::Document &document) = 0;
};

#endif//__FILE_REQUEST_LISTENER_H__