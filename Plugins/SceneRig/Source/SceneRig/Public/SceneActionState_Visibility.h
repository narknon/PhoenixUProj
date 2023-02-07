#pragma once
#include "CoreMinimal.h"
#include "SceneRigBakeSequence.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_Visibility.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Visibility : public USceneRigObjectActionState, public ISceneRigBakeSequence {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PreviouslyHidden;
    
public:
    USceneActionState_Visibility();
    
    // Fix for true pure virtual functions not being implemented
};

