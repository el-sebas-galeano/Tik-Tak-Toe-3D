#ifndef __RandomTiktaktoePlayer__h__
#define __RandomTiktaktoePlayer__h__

#include "TiktaktoePlayerBase.h"

class RandomTiktaktoePlayer
        : public TiktaktoePlayerBase
{
    public:
        RandomTiktaktoePlayer();
        virtual ~RandomTiktaktoePlayer() = default;
};

#endif