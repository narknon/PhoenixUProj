#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "AvaDialogueTrackTemplateData.h"
#include "AvaDialogueTrackTemplate.generated.h"

USTRUCT(BlueprintType)
struct FAvaDialogueTrackTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAvaDialogueTrackTemplateData TemplateData;
    
    PHOENIX_API FAvaDialogueTrackTemplate();
};

