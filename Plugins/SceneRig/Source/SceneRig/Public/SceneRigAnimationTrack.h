#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "SceneRigAnimationTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable, MinimalAPI)
class USceneRigAnimationTrack : public UMovieSceneNameableTrack {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> AnimationSections;
    
public:
    USceneRigAnimationTrack();
};

