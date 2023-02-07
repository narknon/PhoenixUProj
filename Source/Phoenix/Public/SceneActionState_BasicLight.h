#pragma once
#include "CoreMinimal.h"
#include "SceneRigActionState.h"
#include "SceneActionState_BasicLight.generated.h"

class ULocalLightComponent;

UCLASS(Blueprintable)
class USceneActionState_BasicLight : public USceneRigActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    ULocalLightComponent* Light;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSetTransform;
    
    USceneActionState_BasicLight();
};

