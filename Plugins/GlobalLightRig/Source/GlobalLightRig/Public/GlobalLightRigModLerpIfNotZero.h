#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModLerpBinary.h"
#include "GlobalLightRigModLerpIfNotZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpIfNotZero : public UGlobalLightRigModLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    UGlobalLightRigModLerpIfNotZero();
};

