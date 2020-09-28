#ifndef __FILE_REQUEST_LISTENER_H__
#define __FILE_REQUEST_LISTENER_H__

#include "external/json/document.h"
#include <vector>

class FileRequestListener
{
public:
    virtual ~FileRequestListener() {}

    virtual void applyData(const std::vector<char> &buffer) = 0;
};

#endif//__FILE_REQUEST_LISTENER_H__