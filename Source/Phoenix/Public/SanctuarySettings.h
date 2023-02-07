#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SanctuarySettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class USanctuarySettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HousekeepingSimulationStepIntervalSec;
    
    USanctuarySettings();
};

