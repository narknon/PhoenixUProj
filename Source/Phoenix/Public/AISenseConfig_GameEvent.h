#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseConfig.h"
#include "Templates/SubclassOf.h"
#include "AISenseConfig_GameEvent.generated.h"

class UAISense_GameEvent;
class UPlayer_FootfallDataAsset;

UCLASS(Blueprintable, EditInlineNew)
class UAISenseConfig_GameEvent : public UAISenseConfig {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, NoClear, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAISense_GameEvent> Implementation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPlayer_FootfallDataAsset* FootfallDataAsset;
    
    UAISenseConfig_GameEvent();
};

