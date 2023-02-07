#pragma once
#include "CoreMinimal.h"
#include "StagePreviewDriverContext.generated.h"

class USceneRigStageParameterBlock;

USTRUCT(BlueprintType)
struct SCENERIG_API FStagePreviewDriverContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneRigStageParameterBlock* StageParameters;
    
    FStagePreviewDriverContext();
};

