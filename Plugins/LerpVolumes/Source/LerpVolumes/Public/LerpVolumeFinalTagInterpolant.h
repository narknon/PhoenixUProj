#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalInterpolant.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeFinalTagInterpolant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalTagInterpolant : public ULerpVolumeFinalInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName Name;
    
    ULerpVolumeFinalTagInterpolant();
};

