#ifndef __RandomTiktaktoePlayer__h__
#define __RandomTiktaktoePlayer__h__

#include "TiktaktoePlayerBase.h"
#include <vector>
#include <utility>

class RandomTiktaktoePlayer
        : public TiktaktoePlayerBase
{
    public:
        RandomTiktaktoePlayer();
        virtual ~RandomTiktaktoePlayer() = default;
        virtual void play(unsigned int& x,
                          unsigned int& y,
                          unsigned int& z
                          )override;

        virtual void configure(
                unsigned int size,
                unsigned char symbol
        ) override;

        unsigned long long _idx(
                unsigned int &x,
                unsigned int &y,
                unsigned int &z
        ) const;
    protected:
    std::vector<char> options;
};

#endif