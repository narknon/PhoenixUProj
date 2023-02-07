#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateBoolMap.h"
#include "LightComponentStateVisibility.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateVisibility : public ULightComponentStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bVisible;
    
    ULightComponentStateVisibility();
};

