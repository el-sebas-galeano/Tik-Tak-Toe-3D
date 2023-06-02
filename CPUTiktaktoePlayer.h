#ifndef __CPUTiktaktoePlayer__h__
#define __CPUTiktaktoePlayer__h__

#include "TiktaktoePlayerBase.h"
#include <vector>

class CPUTiktaktoePlayer
        : public TiktaktoePlayerBase
{
public:
    CPUTiktaktoePlayer();
    virtual ~CPUTiktaktoePlayer() = default;
};

#endif