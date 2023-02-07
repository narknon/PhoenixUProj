#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimatedLightsClusterSettings.generated.h"

UCLASS(Blueprintable)
class ANIMATEDLIGHTS_API UAnimatedLightsClusterSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TickEveryFrameDistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowTickDistanceMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowTickRateSeconds;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxTickEveryFrameDistanceMeters;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxSlowTickDistanceMeters;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InverseRange;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxInverseRange;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlowTickInverseRange;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoScale;
    
    UAnimatedLightsClusterSettings();
    UFUNCTION(BlueprintCallable)
    void SetRange(float NewTickEveryFrameDistanceMeters, float NewSlowTickDistanceMeters);
    
};

