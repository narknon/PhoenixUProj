#pragma once
#include "CoreMinimal.h"
#include "Perception/AISense.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "EGameEvent_Intensity.h"
#include "AISense_GameEvent.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class UAISense_GameEvent : public UAISense {
    GENERATED_BODY()
public:
    UAISense_GameEvent();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ReportGameEvent(UObject* WorldContextObject, FGameplayTagContainer TagContainer, FVector Location, EGameEvent_Intensity Intensity, float Duration, float Range, float Falloff, AActor* Instigator, bool bTrackBackToInstigator, AActor* Target, FName Name);
    
};

