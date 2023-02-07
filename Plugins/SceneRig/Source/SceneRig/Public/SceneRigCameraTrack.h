#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "SceneRigCameraTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigCameraTrack : public UMovieSceneNameableTrack {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    USceneRigCameraTrack();
};

