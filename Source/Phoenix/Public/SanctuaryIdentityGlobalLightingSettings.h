#pragma once
#include "CoreMinimal.h"
#include "SanctuaryIdentityGlobalLightingSettings.generated.h"

class UGlobalLightingBlendable;

USTRUCT(BlueprintType)
struct FSanctuaryIdentityGlobalLightingSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGlobalLightingBlendable* GlobalLightingBlendable;
    
    PHOENIX_API FSanctuaryIdentityGlobalLightingSettings();
};

