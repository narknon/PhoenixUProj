#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "MinimapBase.generated.h"

class UMapIconInstance;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMiniMapParameters;
class UTexture2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapBase : public UUserWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InSearchAreaState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinYElevationDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinYElevationDistHogwarts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxXElevationDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinYElevationDistSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxXElevationDistSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElevationBuffer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ElevationBufferSquared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DefaultIconColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor DefaultDiscoveredColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMiniMapParameters* MiniMapParameters;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MapVirtualTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MapRegularVirtualTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* MapNoFlyVirtualTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* MapRenderTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureRenderTarget2D* MapRenderTargetNoFly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* MaterialDynamic;
    
public:
    UMinimapBase();
    UFUNCTION(BlueprintCallable)
    void ShowOutline(UMapIconInstance* Icon);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowMap(bool Visibile);
    
    UFUNCTION(BlueprintCallable)
    void SetSize(float Size);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerPositionTextureSpaceEvent(FVector2D pPlayerLocation);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPlayerPositionEvent(FVector pPlayerLocation);
    
    UFUNCTION(BlueprintCallable)
    void SetPlayerPosition(FVector pPlayerPosition);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetPathPulseVisibility(float PulseVisibility);
    
    UFUNCTION(BlueprintCallable)
    void SetPathPulseSpeed(float Speed);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetOpacity(float Alpha);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetMiniMapSize(float Size, float ZoomTime);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetMaterialTexture(const FString& TextureParameter, UTexture2D* Texture);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMapOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    void SetIntrusionColor(FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void SetIconDistanceScale(float IconDistanceScale);
    
    UFUNCTION(BlueprintCallable)
    void SetColorByName(const FString& ParameterName, FLinearColor Color);
    
    UFUNCTION(BlueprintCallable)
    void PulseCircleIcon(UMapIconInstance* Icon);
    
    UFUNCTION(BlueprintCallable)
    void OverrideLevelBounds(FVector2D TopLeft, FVector2D BottomRight);
    
    UFUNCTION(BlueprintCallable)
    bool IsPointInBounds(FVector2D Point, FVector2D TL, FVector2D BR);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetWorldToTextureScale();
    
    UFUNCTION(BlueprintCallable)
    void GetVisibleBoundsInPixels(FVector2D& TL, FVector2D& BR);
    
    UFUNCTION(BlueprintCallable)
    void GetVisibleBounds(FVector2D& TL, FVector2D& BR);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetTopLeftPadded();
    
    UFUNCTION(BlueprintCallable)
    FVector GetPlayerLocation();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetOnScreenTextureArea();
    
    UFUNCTION(BlueprintCallable)
    float GetMiniMapZoomSize();
    
    UFUNCTION(BlueprintCallable)
    float GetMiniMapSize();
    
    UFUNCTION(BlueprintCallable)
    float GetMiniMapInitialSize();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetMapToTextureRatio();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetMapMultiplier();
    
    UFUNCTION(BlueprintCallable)
    void GetBoundsForTextureSpaceSubSection(FVector WorldPosition, FVector2D& TL, FVector2D& BR, float& AvgMultiplier);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetBottomRightPadded();
    
    UFUNCTION(BlueprintCallable)
    void FadeInMissionIcon(UMapIconInstance* Icon);
    
    UFUNCTION(BlueprintCallable)
    void FadeInCircleIcon(UMapIconInstance* Icon);
    
    UFUNCTION(BlueprintCallable)
    FVector2D ConvertFromWorldSpaceToTextureSpaceSubSection(FVector WorldPosition);
    
    UFUNCTION(BlueprintCallable)
    void CalculateScale();
    
};

