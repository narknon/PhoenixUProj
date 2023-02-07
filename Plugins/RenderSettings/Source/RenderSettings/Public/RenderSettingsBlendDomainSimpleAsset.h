#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsBlendDomainAsset.h"
#include "SimpleBlendDomain.h"
#include "RenderSettingsBlendDomainSimpleAsset.generated.h"

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsBlendDomainSimpleAsset : public URenderSettingsBlendDomainAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleBlendDomain BlendDomain;
    
    URenderSettingsBlendDomainSimpleAsset();
};

