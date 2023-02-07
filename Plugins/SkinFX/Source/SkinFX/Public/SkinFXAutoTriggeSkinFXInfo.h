#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SkinFXAutoTriggeSkinFXInfo.generated.h"

class ASkinFXDefinition;

USTRUCT(BlueprintType)
struct FSkinFXAutoTriggeSkinFXInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    SKINFX_API FSkinFXAutoTriggeSkinFXInfo();
};

