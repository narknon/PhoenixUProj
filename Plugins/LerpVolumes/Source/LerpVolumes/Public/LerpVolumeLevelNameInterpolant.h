#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeLevelNameInterpolantBase.h"
#include "LerpVolumesLevelName.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeLevelNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeLevelNameInterpolant : public ULerpVolumeLevelNameInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesLevelName LevelName;
    
    ULerpVolumeLevelNameInterpolant();
};

