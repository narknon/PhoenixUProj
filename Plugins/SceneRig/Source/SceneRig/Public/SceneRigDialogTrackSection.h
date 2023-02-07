#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "SceneRigDialogTrackSectionData.h"
#include "SceneRigDialogTrackSection.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class USceneRigDialogTrackSection : public UMovieSceneSection {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigDialogTrackSectionData SectionData;
    
    USceneRigDialogTrackSection();
};

