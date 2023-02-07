#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_IKPoseFixup.generated.h"

class USceneAction_IKPoseFixup;

UCLASS(Blueprintable)
class USceneActionState_IKPoseFixup : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneAction_IKPoseFixup* IKPoseFixupDefinition;
    
    USceneActionState_IKPoseFixup();
};

