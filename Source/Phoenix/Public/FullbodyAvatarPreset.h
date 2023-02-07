#pragma once
#include "CoreMinimal.h"
#include "FullbodyAvatarPreset.generated.h"

USTRUCT(BlueprintType)
struct FFullbodyAvatarPreset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    PHOENIX_API FFullbodyAvatarPreset();
};

