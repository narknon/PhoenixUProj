#pragma once
#include "CoreMinimal.h"
#include "ELastFrameExposureValue.h"
#include "RenderSettingsCustomBlendDomainNoPreCompute.h"
#include "RenderSettingsCustomBlendDomainLastFrameExposureRange.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API URenderSettingsCustomBlendDomainLastFrameExposureRange : public URenderSettingsCustomBlendDomainNoPreCompute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LowExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HighExposure;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELastFrameExposureValue ExposureValue;
    
    URenderSettingsCustomBlendDomainLastFrameExposureRange();
};

