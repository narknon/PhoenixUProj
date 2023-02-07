#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LightComponentStateData.generated.h"

class ULightComponentState;

UCLASS(Abstract, Blueprintable, Transient)
class ULightComponentStateData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightComponentState* State;
    
    ULightComponentStateData();
};

