#pragma once
#include "CoreMinimal.h"
#include "BlendDomainLegacy.h"
#include "BlendDomain.generated.h"

class URenderSettingsCustomBlendDomain;

USTRUCT(BlueprintType)
struct FBlendDomain : public FBlendDomainLegacy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<URenderSettingsCustomBlendDomain*> CustomBlends;
    
    RENDERSETTINGS_API FBlendDomain();
};

