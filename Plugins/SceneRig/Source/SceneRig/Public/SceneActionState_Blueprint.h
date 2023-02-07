#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_Blueprint.generated.h"

class USceneAction_Blueprint;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Blueprint : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USceneAction_Blueprint* BlueprintInstance;
    
public:
    USceneActionState_Blueprint();
};

