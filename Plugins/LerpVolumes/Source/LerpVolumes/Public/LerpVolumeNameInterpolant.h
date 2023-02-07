#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeTagInterpolantBase.h"
#include "LerpVolumeNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeNameInterpolant : public ULerpVolumeTagInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
    ULerpVolumeNameInterpolant();
};

