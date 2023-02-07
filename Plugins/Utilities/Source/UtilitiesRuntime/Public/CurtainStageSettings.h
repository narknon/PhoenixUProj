#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CurtainStageEntry.h"
#include "CurtainStageSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class UCurtainStageSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCurtainStageEntry> CurtainStages;
    
    UCurtainStageSettings();
};

