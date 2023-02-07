#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesRemapLevelName.generated.h"

USTRUCT(BlueprintType)
struct LERPVOLUMES_API FLerpVolumesRemapLevelName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString InLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString OutLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExactMatch;
    
    FLerpVolumesRemapLevelName();
};

