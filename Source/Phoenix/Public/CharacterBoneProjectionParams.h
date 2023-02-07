#pragma once
#include "CoreMinimal.h"
#include "CharacterBoneProjectionParams.generated.h"

USTRUCT(BlueprintType)
struct FCharacterBoneProjectionParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FrameStagger;
    
    PHOENIX_API FCharacterBoneProjectionParams();
};

