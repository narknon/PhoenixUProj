#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateBoolMap.h"
#include "LightComponentStateCastTranslucentShadows.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULightComponentStateCastTranslucentShadows : public ULightComponentStateBoolMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCastTranslucentShadows;
    
    ULightComponentStateCastTranslucentShadows();
};

