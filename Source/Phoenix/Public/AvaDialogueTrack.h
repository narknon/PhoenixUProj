#pragma once
#include "CoreMinimal.h"
#include "MovieSceneNameableTrack.h"
#include "MovieSceneObjectBindingID.h"
#include "AvaDialogueTrack.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class PHOENIX_API UAvaDialogueTrack : public UMovieSceneNameableTrack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMovieSceneObjectBindingID> EventReceivers;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMovieSceneSection*> Sections;
    
public:
    UAvaDialogueTrack();
};

