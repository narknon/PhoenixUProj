#pragma once
#include "CoreMinimal.h"
#include "Perception/AISense.h"
#include "UObject/NoExportTypes.h"
#include "AIMagicEvent.h"
#include "AISense_Magic.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, Config=Game)
class UAISense_Magic : public UAISense {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIMagicEvent> MagicEvents;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedOfMagicFeelSq;
    
public:
    UAISense_Magic();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void ReportMagicEvent(UObject* WorldContextObject, FVector MagicLocation, float Power, AActor* Instigator, float MaxRange, FName Tag);
    
};

