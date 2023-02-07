#pragma once
#include "CoreMinimal.h"
#include "AnimRequestProvider.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_AnimCurves.generated.h"

class UPoseSampler_AnimCurves;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_AnimCurves : public USceneRigObjectActionState, public IAnimRequestProvider {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPoseSampler_AnimCurves* PoseSampler;
    
public:
    USceneActionState_AnimCurves();
    
    // Fix for true pure virtual functions not being implemented
};

