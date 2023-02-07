#pragma once
#include "CoreMinimal.h"
#include "LightComponentStateData.h"
#include "LightComponentStateDataBoolMap.generated.h"

class ULightComponent;

UCLASS(Blueprintable, NonTransient)
class ULightComponentStateDataBoolMap : public ULightComponentStateData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<ULightComponent>, bool> BoolMap;
    
    ULightComponentStateDataBoolMap();
};

