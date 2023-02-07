#pragma once
#include "CoreMinimal.h"
#include "SkinFXEffectTypeOverrideEntry.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXEffectTypeOverrideEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> ActorClassPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TypeOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowSubclasses;
    
    FSkinFXEffectTypeOverrideEntry();
};

