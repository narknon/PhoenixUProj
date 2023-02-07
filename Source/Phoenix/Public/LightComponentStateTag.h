#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateBoolMap.h"
#include "LightComponentStateTag.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateTag : public ULightComponentStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
    ULightComponentStateTag();
};

