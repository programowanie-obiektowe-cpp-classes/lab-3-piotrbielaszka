#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0;
    
    Stocznia     stocznia{};
    unsigned int ilosc_zaglowcow = 0;
    while (stocznia.getTotalCap() < towar) {
        Statek* s = stocznia();
        s->transportuj();
        if (dynamic_cast< Zaglowiec* >(s) != nullptr)
            ilosc_zaglowcow++;
        delete s;
    }
    return ilosc_zaglowcow;
}