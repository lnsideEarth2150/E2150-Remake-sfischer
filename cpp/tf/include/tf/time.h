#ifndef TIME_H
#define TIME_H

// Ben�tigt unter Windows "winmm.lib"

#include <stdint.h>

/// Gibt die Laufzeit des PCs in Millisekunden zur�ck
uint32_t MilliSecs();

/**
* Erstellt einen Timer mit einer bestimmten Tickrate in Millisekunden
* @return Den Timer oder -1, falls er nicht erstellt werden konnte
*/
void* CreateTimer(int ms);

/// Wartet so lange bis der Timer einen "Tick" ausl�st
void WaitTimer(void* hTimer);

/// Gibt einen Timer wieder frei
void FreeTimer(void* hTimer);

/// Pausiert die Ausf�hrung um die angegebene Anzahl an Millisekunden
void Delay(uint32_t ms);


/**
* Funktionen f�r sehr genaue Zeitmessungen (Nanosekunden Bereich)
*/

/// Bereitet System auf Messungen vor / Pr�ft ob Messungen m�glich sind
/// Systemspezifisch (erzeugt keine Laufzeitkosten)
bool InitHighResolutionTimer();

/// Gibt den aktuellen Timer Wert zur�ck
void HighResolutionTime(uint64_t* target);

/// Berechnet den Unterschied zwischen 2 Zeitangaben, R�ckgabe in Sekunden (Flie�komma)
double HighResolutionDiffSec(uint64_t first, uint64_t second);

/// Berechnet den Unterschied zwischen 2 Zeitangaben, R�ckgabe in Nanosekunden
uint64_t HighResolutionDiffNanoSec(uint64_t first, uint64_t second);


#endif // TIME_H
