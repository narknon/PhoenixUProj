#pragma once
#include "CoreMinimal.h"
#include "LightDirectionLerpControl.h"
#include "LightDirectionLerpBinary.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightDirectionLerpBinary : public ULightDirectionLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvert;
    
    ULightDirectionLerpBinary();
};

