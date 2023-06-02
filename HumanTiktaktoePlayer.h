#ifndef __HumanTiktaktoePlayer__h__
#define __HumanTiktaktoePlayer__h__

#include "TiktaktoePlayerBase.h"
#include <vector>

class HumanTiktaktoePlayer
        : public TiktaktoePlayerBase
        {
    public:
    HumanTiktaktoePlayer();
    virtual ~HumanTiktaktoePlayer() = default;
    virtual void play(unsigned int& x,
                      unsigned int& y,
                      unsigned int& z,
                      std::vector <unsigned char> boxes
                      )
                      override;

    private:
        bool verify(char* entry);
};

#endif
