#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigAnimationParams.h"
#include "SceneRigAnimationSectionTemplateParameters.generated.h"

USTRUCT(BlueprintType)
struct FSceneRigAnimationSectionTemplateParameters : public FSceneRigAnimationParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFrameNumber SectionStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFrameNumber SectionEndTime;
    
    SCENERIG_API FSceneRigAnimationSectionTemplateParameters();
};

