#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "DirectPostProcessingEval.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FDirectPostProcessingEval {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    FDirectPostProcessingEval();
};

