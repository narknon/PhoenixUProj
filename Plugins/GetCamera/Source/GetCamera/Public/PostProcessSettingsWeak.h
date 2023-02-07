#pragma once
#include "CoreMinimal.h"
#include "Engine/Scene.h"
#include "PostProcessSettingsObjects.h"
#include "PostProcessSettingsWeak.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessSettingsWeak {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettings PostProcessSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPostProcessSettingsObjects PostProcessSettingsObjects;
    
    GETCAMERA_API FPostProcessSettingsWeak();
};

