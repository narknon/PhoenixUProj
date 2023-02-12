#pragma once
#include "CoreMinimal.h"
#include "AkAcousticSurface.generated.h"

USTRUCT(BlueprintType)
struct FAkAcousticSurface {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Occlusion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    AKAUDIO_API FAkAcousticSurface();
};

