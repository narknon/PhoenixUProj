#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableInterface.h"
#include "SceneRigActionState.h"
#include "SceneActionState_GlobalLightRigBlendable.generated.h"

UCLASS(Blueprintable)
class USceneActionState_GlobalLightRigBlendable : public USceneRigActionState, public IGlobalLightingBlendableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentBlend;
    
    USceneActionState_GlobalLightRigBlendable();
    
    // Fix for true pure virtual functions not being implemented
};

