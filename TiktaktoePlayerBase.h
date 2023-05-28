#ifndef __TiktaktoePlayerBase__h__
#define __TiktaktoePlayerBase__h__

class TiktaktoePlayerBase{
    public:
        TiktaktoePlayerBase( );

        virtual ~TiktaktoePlayerBase( ) = default;

        bool getWon();
        bool setWon(bool won);
        virtual char getSymbol();

        virtual void configure(
                unsigned int size,
                unsigned char symbol
                );

        virtual void play(
                unsigned int& x,
                unsigned int& y,
                unsigned int& z
                );

        virtual void report(
                const unsigned char& c
                );

    protected:
        unsigned int size;

        unsigned char symbol;

        bool won{false};
}; 

#endif //  __TiktaktoePlayerBase__h__