#pragma once
#include "CoreMinimal.h"
#include "SkyStateOverride.h"
#include "SkyStateOverrideHideMoon.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class DAYNIGHT_API USkyStateOverrideHideMoon : public USkyStateOverride {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    USkyStateOverrideHideMoon();
};

