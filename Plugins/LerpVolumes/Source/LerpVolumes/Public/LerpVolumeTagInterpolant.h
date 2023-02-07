#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeTagInterpolantBase.h"
#include "LerpVolumeTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeTagInterpolant : public ULerpVolumeTagInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Value;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CachedNameValue;
    
public:
    ULerpVolumeTagInterpolant();
};

