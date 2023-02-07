#pragma once
#include "CoreMinimal.h"
#include "AdjustedValueBoolean.h"
#include "AdjustedValueFloat.h"
#include "DirectionalLightShadowsRelative.generated.h"

USTRUCT(BlueprintType)
struct GLOBALLIGHTRIG_API FDirectionalLightShadowsRelative {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ShadowResolutionScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ShadowBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ShadowSlopeBias;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ShadowSharpen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ContactShadowLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueFloat ContactShadowLengthWorldSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueBoolean bContactShadowLengthInWS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueBoolean bCastVolumetricShadow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAdjustedValueBoolean bCastTranslucentShadows;
    
    FDirectionalLightShadowsRelative();
};

