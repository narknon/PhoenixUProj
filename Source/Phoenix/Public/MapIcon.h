#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "EBeaconType.h"
#include "EMapFadeState.h"
#include "EMapIconState.h"
#include "EMapToolTipTypes.h"
#include "HoverDataEvent.h"
#include "MapIcon.generated.h"

class AMapFilterRegion;
class UBeaconInfo;
class UMapIconInstance;
class UMapIconWidget;
class UTexture2D;

UCLASS(Blueprintable)
class UMapIcon : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBeaconInfo* BeaconInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapIconWidget* NameWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapFilterRegion* FilterRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* FilterRegionTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Texture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMapToolTipTypes IconType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHoverDataEvent EventData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIconInstance* IconInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIconInstance* IconInstanceBadge;
    
    UMapIcon();
    UFUNCTION(BlueprintCallable)
    void StopAnimationAndChain(EMapIconState NextState);
    
    UFUNCTION(BlueprintCallable)
    void StopAnimation();
    
    UFUNCTION(BlueprintCallable)
    void SetTargetScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void SetTargetColor(FLinearColor pTargetColor);
    
    UFUNCTION(BlueprintCallable)
    void SetState(EMapIconState IconState, bool SaveState);
    
    UFUNCTION(BlueprintCallable)
    void SetStartingScale(float Scale);
    
    UFUNCTION(BlueprintCallable)
    void SetScale(float ScaleIn);
    
    UFUNCTION(BlueprintCallable)
    void SetIconVisibility(bool pVisbility);
    
    UFUNCTION(BlueprintCallable)
    void SetIconPriority(int32 Priority);
    
    UFUNCTION(BlueprintCallable)
    void SetIconFlags(int32 flags);
    
    UFUNCTION(BlueprintCallable)
    void SetIconBadgeVisibility(bool pVisbility);
    
    UFUNCTION(BlueprintCallable)
    void SetColor(FLinearColor ColorIn);
    
    UFUNCTION(BlueprintCallable)
    void SetBadgeName(const FString& pBadgeName);
    
    UFUNCTION(BlueprintCallable)
    bool IsStopping();
    
    UFUNCTION(BlueprintCallable)
    bool IsBadgeStopping();
    
    UFUNCTION(BlueprintCallable)
    float GetTargetScale();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapIconState> GetState();
    
    UFUNCTION(BlueprintCallable)
    float GetStartingScale();
    
    UFUNCTION(BlueprintCallable)
    int32 GetIconPriority();
    
    UFUNCTION(BlueprintCallable)
    int32 GetIconFlags();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapFadeState> GetFadeState();
    
    UFUNCTION(BlueprintCallable)
    FVector GetBeaconWorldPosition();
    
    UFUNCTION(BlueprintCallable)
    EBeaconType GetBeaconType();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconName();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconIcon();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconFastTravelLocationID();
    
    UFUNCTION(BlueprintCallable)
    FString GetBeaconDescShort();
    
    UFUNCTION(BlueprintCallable)
    void ExcludeIconFromStackedFade(bool pExcludeFromStackedFade);
    
};

