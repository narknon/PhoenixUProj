#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateBoolMap.h"
#include "LightComponentStateCastShadows.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateCastShadows : public ULightComponentStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastShadows;
    
    ULightComponentStateCastShadows();
};

