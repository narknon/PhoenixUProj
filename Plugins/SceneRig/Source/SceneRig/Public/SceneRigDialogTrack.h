#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "MovieSceneObjectBindingID.h"
#include "SceneRigDialogTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigDialogTrack : public UMovieSceneNameableTrack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    USceneRigDialogTrack();
};

