#ifndef IENTITYEVENTRECEIVER_H_INCLUDED
#define IENTITYEVENTRECEIVER_H_INCLUDED

#include "Util/ReferenceCounter.h"

class Entity;

/**
* Interface Klasse um auf Events von Entitys direkt
* reagieren zu k�nnen.
*/
class IEntityEventReceiver : ReferenceCounter {
	public:
		IEntityEventReceiver();
		virtual ~IEntityEventReceiver();

		/// Wird ausgel�st, wenn das Entity Schaden nimmt.
		virtual void OnTakeDamage(const Entity& entity) = 0;

		/// Wird ausgel�st, wenn das Entity zerst�rt werden soll.
		virtual void OnDestroy(const Entity& entity) = 0;

		/// Wird ausgel�st, wenn das Entity eine bewegung abschlie�t (Ziel erreicht).
		virtual void OnFinishMove(const Entity& entity) = 0;

};


#endif // IENTITYEVENTRECEIVER_H_INCLUDED
