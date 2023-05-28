#ifndef __TiktaktoeBoard__h__
#define __TiktaktoeBoard__h__

#include <ostream>
#include <vector>
#include "TiktaktoePlayerBase.h"

class TiktaktoeBoard{
    public:
        TiktaktoeBoard(
                unsigned int size
                );

        virtual ~TiktaktoeBoard() = default;

        void setPlayers(
                TiktaktoePlayerBase* playerX,
                TiktaktoePlayerBase* playerO
                );

        TiktaktoePlayerBase* getPlayerX();
        TiktaktoePlayerBase* getPlayerO();
        unsigned long long getCheck();
        void setCheck(long long check);

        bool have_won() const;

        bool have_tie();

        unsigned char click(
                unsigned int x,
                unsigned int y,
                unsigned int z,
                char symbol
                );

        void step(
                TiktaktoePlayerBase& tiktaktoePlayerBase
                );

        const unsigned int& getSize();
    private:
        bool verify(
                unsigned int x,
                unsigned int y,
                unsigned int z,
                char symbol
        );
        void toStream(
                std::ostream& out
                ) const;

        unsigned long long _idx(
            unsigned int& x,
            unsigned int& y,
            unsigned int& z
        ) const;

    protected:
        std::vector <unsigned char> boxes;

        bool tie {false};

        unsigned int size;

        unsigned long long check = 0;

        TiktaktoePlayerBase* playerX;

        TiktaktoePlayerBase* playerO;

    public:
        friend std::ostream& operator<<(
                std::ostream& o,
                const TiktaktoeBoard& b
                ){
                    b.toStream(o);
                    return (o);
                }
};

#endif // __TiktaktoeBoard__h__