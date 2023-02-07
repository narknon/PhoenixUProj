#pragma once
#include "CoreMinimal.h"
#include "IMovieScenePlaybackClient.h"
#include "SceneRigActionState.h"
#include "SceneRigBakeSequence.h"
#include "SceneActionState_Sequence.generated.h"

class AActor;
class ULevelSequencePlayer;
class UMovieSceneBindingOverrides;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Sequence : public USceneRigActionState/*, public ISceneRigBakeSequence, public IMovieScenePlaybackClient*/ {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelSequencePlayer* SequencePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMovieSceneBindingOverrides* BindingOverrides;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> PossessedActors;
    
    USceneActionState_Sequence();
    
    // Fix for true pure virtual functions not being implemented
};

