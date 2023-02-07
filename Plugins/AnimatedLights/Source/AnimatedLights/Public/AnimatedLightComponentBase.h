#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightClusterComponentAuto.h"
#include "AnimatedLightComponentBase.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightComponentBase : public UAnimatedLightClusterComponentAuto {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bDeepScanChildren: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 RandomizeStartOffset: 1;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Time;
    
public:
    UAnimatedLightComponentBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void IsAnimatedLightEnabled(bool& bIsEnabled) const;
    
    UFUNCTION(BlueprintCallable)
    void EnableAnimatedLight(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void DisableAnimatedLight();
    
};

