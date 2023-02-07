#pragma once
#include "CoreMinimal.h"
#include "Evaluation/MovieSceneEvalTemplate.h"
#include "SceneRigDialogTrackTemplateData.h"
#include "SceneRigDialogTrackTemplate.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigDialogTrackTemplate : public FMovieSceneEvalTemplate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigDialogTrackTemplateData TemplateData;
    
    SCENERIG_API FSceneRigDialogTrackTemplate();
};

