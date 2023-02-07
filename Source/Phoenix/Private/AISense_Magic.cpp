#include "AISense_Magic.h"

class AActor;
class UObject;

void UAISense_Magic::ReportMagicEvent(UObject* WorldContextObject, FVector MagicLocation, float Power, AActor* Instigator, float MaxRange, FName Tag) {
}

UAISense_Magic::UAISense_Magic() {
    this->SpeedOfMagicFeelSq = 0.00f;
}

