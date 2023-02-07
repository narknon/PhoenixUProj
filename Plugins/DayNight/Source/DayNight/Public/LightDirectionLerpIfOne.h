#pragma once
#include "CoreMinimal.h"
#include "LightDirectionLerpBinary.h"
#include "LightDirectionLerpIfOne.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpIfOne : public ULightDirectionLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    ULightDirectionLerpIfOne();
};

