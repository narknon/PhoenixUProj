#pragma once
#include "CoreMinimal.h"
#include "SkinFXEffectDefinition.generated.h"

class ASkinFXDefinition;

USTRUCT(BlueprintType)
struct FSkinFXEffectDefinition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* Blueprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASkinFXDefinition* Effect;
    
    SKINFX_API FSkinFXEffectDefinition();
};

