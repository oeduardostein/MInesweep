#include "Bomba.hpp"

Bomba::Bomba()
{
    offset = Offset();
}

Bomba::Bomba(Offset offset)
{
    this->offset = offset;
}

Bomba::Bomba(int x, int y)
{
    offset = Offset(x, y);
}

Offset Bomba::getOffset()
{
    return offset;
}

bool Bomba::operator ==(Bomba bomba)
{
    return (offset == bomba.offset);
}

bool Bomba::operator !=(Bomba bomba)
{
    return (offset != bomba.offset);
}