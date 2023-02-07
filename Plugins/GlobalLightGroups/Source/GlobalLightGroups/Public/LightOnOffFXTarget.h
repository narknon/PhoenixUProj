#pragma once
#include "CoreMinimal.h"
#include "LightOnOffFXTarget.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct FLightOnOffFXTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnOff;
    
    GLOBALLIGHTGROUPS_API FLightOnOffFXTarget();
};

