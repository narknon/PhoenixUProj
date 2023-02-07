#pragma once
#include "CoreMinimal.h"
#include "WandLinkStage.generated.h"

class UWandLinkUIMiniGame;

USTRUCT(BlueprintType)
struct FWandLinkStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWandLinkUIMiniGame* WandLinkUIMiniGame;
    
    PHOENIX_API FWandLinkStage();
};

