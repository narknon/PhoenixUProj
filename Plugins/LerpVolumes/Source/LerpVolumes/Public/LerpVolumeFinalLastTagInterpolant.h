#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalTagInterpolant.h"
#include "LerpVolumesTagName.h"
#include "LerpVolumeFinalLastTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalLastTagInterpolant : public ULerpVolumeFinalTagInterpolant {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesTagName SourceInterpolant;
    
    ULerpVolumeFinalLastTagInterpolant();
};

