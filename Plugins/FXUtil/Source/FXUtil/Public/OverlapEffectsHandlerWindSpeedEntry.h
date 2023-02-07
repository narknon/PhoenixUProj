#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EWindSpeedOverlapEffectsMode.h"
#include "OverlapEffectsHandlerWindSpeedEntry.generated.h"

class UOverlapEffectsHandlerEffect;

USTRUCT(BlueprintType)
struct FXUTIL_API FOverlapEffectsHandlerWindSpeedEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ClothingTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D StartEndSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindSpeedOverlapEffectsMode Mode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> StartEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> EndEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopProcessingWithClothingMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseStartEndSpeedMS;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHasStartedEffects;
    
    FOverlapEffectsHandlerWindSpeedEntry();
};

