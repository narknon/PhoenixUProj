#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_StencilFX.generated.h"

UCLASS(Blueprintable)
class USceneActionState_StencilFX : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName StartedFX;
    
    USceneActionState_StencilFX();
};

