#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "AvaDialogueTrackSectionData.h"
#include "AvaDialogueTrackSection.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class UAvaDialogueTrackSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvaDialogueTrackSectionData SectionData;
    
    UAvaDialogueTrackSection();
};

