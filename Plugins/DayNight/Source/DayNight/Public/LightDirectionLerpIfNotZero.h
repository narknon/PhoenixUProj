#pragma once
#include "CoreMinimal.h"
#include "LightDirectionLerpBinary.h"
#include "LightDirectionLerpIfNotZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpIfNotZero : public ULightDirectionLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    ULightDirectionLerpIfNotZero();
};

