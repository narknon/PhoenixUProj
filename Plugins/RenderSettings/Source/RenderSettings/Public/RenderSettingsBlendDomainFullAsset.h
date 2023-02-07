#pragma once
#include "CoreMinimal.h"
#include "BlendDomain.h"
#include "RenderSettingsBlendDomainAsset.h"
#include "RenderSettingsBlendDomainFullAsset.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsBlendDomainFullAsset : public URenderSettingsBlendDomainAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    URenderSettingsBlendDomainFullAsset();
};

