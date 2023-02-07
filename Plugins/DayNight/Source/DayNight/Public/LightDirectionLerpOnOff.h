#pragma once
#include "CoreMinimal.h"
#include "LightDirectionLerpBinary.h"
#include "LightDirectionLerpOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpOnOff : public ULightDirectionLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cutoff;
    
    ULightDirectionLerpOnOff();
};

