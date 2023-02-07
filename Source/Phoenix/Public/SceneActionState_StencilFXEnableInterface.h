#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "StencilManagerEnableInterface.h"
#include "SceneActionState_StencilFXEnableInterface.generated.h"

UCLASS(Blueprintable)
class USceneActionState_StencilFXEnableInterface : public USceneRigObjectActionState, public IStencilManagerEnableInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bInsideInterval;
    
    USceneActionState_StencilFXEnableInterface();
    
    // Fix for true pure virtual functions not being implemented
};

