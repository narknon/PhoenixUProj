#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayBucket.h"
#include "HighContrastGameplayBucketPrimitiveState.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct ACCESSIBILITYSETTINGS_API FHighContrastGameplayBucketPrimitiveState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastGameplayBucket Bucket;
    
    FHighContrastGameplayBucketPrimitiveState();
};

