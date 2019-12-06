#include "Subjekt.h"


Subjekt::Subjekt(void)
{
}
void Subjekt::anmelden(Beobachter * b)
{
	beobachter.push_back(b);

}
void Subjekt::abmelden(Beobachter * b)
{
	beobachter.remove(b);
}
void Subjekt::benachrichtige(void)
{
	list<Beobachter *>::iterator it;
	for (it = beobachter.begin(); it != beobachter.end(); it++)
	{
        (*it)->aktualisiere(this);
	}
}
Subjekt::~Subjekt(void)
{
}
