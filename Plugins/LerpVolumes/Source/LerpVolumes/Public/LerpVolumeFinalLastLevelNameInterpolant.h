#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalTagInterpolant.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeFinalLastLevelNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalLastLevelNameInterpolant : public ULerpVolumeFinalTagInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName LevelNameInterpolant;
    
    ULerpVolumeFinalLastLevelNameInterpolant();
};

