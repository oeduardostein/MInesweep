#ifndef BOMBA_HPP_INCLUDED
#define BOMBA_HPP_INCLUDED

#include "Offset.hpp"

class Bomba
{
    public:
        Bomba();
        Bomba(Offset offset);
        Bomba(int x, int y);
        Offset getOffset();
        bool operator ==(Bomba bomba);
        bool operator !=(Bomba bomba);
    protected:
        Offset offset;
};

#endif // BOMBA_HPP_INCLUDED
