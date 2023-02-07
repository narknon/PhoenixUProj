#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateFloatMap.h"
#include "LightComponentStateContactShadowLength.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateContactShadowLength : public ULightComponentStateFloatMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ContactShadowLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInWorldSpace;
    
    ULightComponentStateContactShadowLength();
};

