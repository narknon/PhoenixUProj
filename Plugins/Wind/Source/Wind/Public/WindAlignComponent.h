#pragma once
#include "CoreMinimal.h"
#include "WindSourceComponentBase.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=WindSourceComponentBase -FallbackName=WindSourceComponentBase
#include "WindAlignComponent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class WIND_API UWindAlignComponent : public UWindSourceComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Outdoors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Strength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float SpeedMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TransitionDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    bool bBidirectional;
    
    UWindAlignComponent();
    UFUNCTION(BlueprintCallable)
    void SetTransitionDistance(float InTransitionDistance);
    
    UFUNCTION(BlueprintCallable)
    void SetStrength(float InNewStrength);
    
    UFUNCTION(BlueprintCallable)
    void SetSpeedMod(float InNewSpeed);
    
    UFUNCTION(BlueprintCallable)
    void SetPriority(float InNewPriority);
    
    UFUNCTION(BlueprintCallable)
    void SetOutdoors(float InNewOutdoors);
    
    UFUNCTION(BlueprintCallable)
    void SetBidirectional(bool bInNewBidirectional);
    
};

