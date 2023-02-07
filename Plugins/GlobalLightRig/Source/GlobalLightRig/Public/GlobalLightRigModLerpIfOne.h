#pragma once
#include "CoreMinimal.h"
#include "GlobalLightRigModLerpBinary.h"
#include "GlobalLightRigModLerpIfOne.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightRigModLerpIfOne : public UGlobalLightRigModLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    UGlobalLightRigModLerpIfOne();
};

