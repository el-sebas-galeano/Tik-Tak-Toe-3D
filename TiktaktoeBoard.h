#ifndef __TiktaktoeBoard__h__
#define __TiktaktoeBoard__h__

#include <ostream>
#include <vector>

class TiktaktoePlayerBase;

class TiktaktoeBoard{
    public:
        TiktaktoeBoard(unsigned int size);
        virtual ~TiktaktoeBoard() = default;

        void setPlayers(TiktaktoePlayerBase* playerX, TiktaktoePlayerBase* playerO);

        bool have_won() const;
        bool have_lose() const;

        unsigned char click();
        void step(TiktaktoePlayerBase* player);

        const unsigned int& getSize();

    private:
        void toStream(std::ostream& out) const;
        unsigned long long _idx(
            unsigned int& x, unsigned int& y, unsigned int& z 
        ) const;

    protected:
        std::vector <unsigned char> boxes;
        bool tie {false};
        unsigned int size;

        TiktaktoePlayerBase* playerX;
        TiktaktoePlayerBase* playerO;

    public:
        friend std::ostream& operator<<(std::ostream& o, const TiktaktoeBoard& b){
            b.toStream(o);
            return (o);
        }
};

#endif // __TiktaktoeBoard__h__