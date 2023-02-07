#pragma once
#include "CoreMinimal.h"
#include "AkSurfacePoly.generated.h"

class UAkAcousticTexture;

USTRUCT(BlueprintType)
struct FAkSurfacePoly {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAcousticTexture* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Occlusion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EnableSurface;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SurfaceArea;
    
public:
    AKAUDIO_API FAkSurfacePoly();
};

