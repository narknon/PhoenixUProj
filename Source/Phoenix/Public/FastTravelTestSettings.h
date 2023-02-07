#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FastTravelTestEntry.h"
#include "FastTravelTestSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UFastTravelTestSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FFastTravelTestEntry> FastTravelTests;
    
    UFastTravelTestSettings();
};

