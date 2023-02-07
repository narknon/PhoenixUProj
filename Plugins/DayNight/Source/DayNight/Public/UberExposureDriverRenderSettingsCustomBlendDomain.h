#pragma once
#include "CoreMinimal.h"
#include "UberExposureDriver.h"
#include "UberExposureDriverRenderSettingsCustomBlendDomain.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UUberExposureDriverRenderSettingsCustomBlendDomain : public UUberExposureDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* domain;
    
    UUberExposureDriverRenderSettingsCustomBlendDomain();
};

