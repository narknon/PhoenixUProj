#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsCustomBlendDomainName.h"
#include "ExposureExpressionsBlendDomainScalarValue.h"
#include "ExposureExpressionsPreComputedBlendDomainNamedScalarValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UExposureExpressionsPreComputedBlendDomainNamedScalarValue : public UExposureExpressionsBlendDomainScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRenderSettingsCustomBlendDomainName BlendDomain;
    
    UExposureExpressionsPreComputedBlendDomainNamedScalarValue();
};

