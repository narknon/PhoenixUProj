#include "AISense_GameEvent.h"

class AActor;
class UObject;

void UAISense_GameEvent::ReportGameEvent(UObject* WorldContextObject, FGameplayTagContainer TagContainer, FVector Location, EGameEvent_Intensity Intensity, float Duration, float Range, float Falloff, AActor* Instigator, bool bTrackBackToInstigator, AActor* Target, FName Name) {
}

UAISense_GameEvent::UAISense_GameEvent() {
}

