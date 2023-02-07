#pragma once
#include "CoreMinimal.h"
#include "FCharacterBoneProjectionMotionType.h"
#include "CharacterBoneProjectionMotion.generated.h"

USTRUCT(BlueprintType)
struct FCharacterBoneProjectionMotion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterBoneProjectionMotionType MotionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RotationSpeedDegreesPerSecond;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TranslationPeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxExtent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrawlingSpeed;
    
    PHOENIX_API FCharacterBoneProjectionMotion();
};

