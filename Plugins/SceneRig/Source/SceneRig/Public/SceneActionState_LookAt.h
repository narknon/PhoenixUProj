#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_LookAt.generated.h"

class UAimEyesData;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_LookAt : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAimEyesData* PrevIdleAimEyes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAimEyesData* PrevSpeakingAimEyes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAimEyesData* PrevListeningAimEyes;
    
public:
    USceneActionState_LookAt();
};

