#pragma once
#include "CoreMinimal.h"
#include "TimeRigState.h"
#include "SceneRigState.generated.h"

class ULevelSequencePlayer;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigState : public UTimeRigState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* SequencePlayer;
    
    USceneRigState();
};

