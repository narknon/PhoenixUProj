#pragma once
#include "CoreMinimal.h"
#include "ESkinFXLocatorListPositionalSourceType.h"
#include "SkinFXBoneProperty.h"
#include "SkinFXSocketProperty.h"
#include "SkinFXUIParameters.h"
#include "SkinFXLocatorListPositionalSource.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXLocatorListPositionalSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXBoneProperty Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXSocketProperty Socket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXLocatorListPositionalSourceType Source;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXUIParameters ExtraParameters;
    
    FSkinFXLocatorListPositionalSource();
};

