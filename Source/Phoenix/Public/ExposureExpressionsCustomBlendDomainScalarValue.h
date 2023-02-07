#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsBlendDomainScalarValue.h"
#include "ExposureExpressionsCustomBlendDomainScalarValue.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UExposureExpressionsCustomBlendDomainScalarValue : public UExposureExpressionsBlendDomainScalarValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* BlendDomain;
    
    UExposureExpressionsCustomBlendDomainScalarValue();
};

