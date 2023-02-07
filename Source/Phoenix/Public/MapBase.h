#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EBeaconType.h"
#include "EMapFadeState.h"
#include "EMapLocTypes.h"
#include "EMapTypes.h"
#include "EMapZoomTypes.h"
#include "MapIconEntry.h"
#include "MapLevelData.h"
#include "MapBase.generated.h"

class AMapPawn;
class APlayerController;
class UBeaconInfo;
class UDebugTextPanel;
class UMapCameraParameters;
class UMapFX;
class UMapIcon;
class UMapIconMeshRenderWidget;
class UMapMovementComponent;
class UMapScreenBase;
class UMaterialInstanceDynamic;
class UPopupScreen;
class UTexture2D;
class UWorldSupportWorld;

UCLASS(Blueprintable)
class UMapBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HogwartsDotIconScale;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FString, UMapIconMeshRenderWidget*> IconInstanceRenderWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapFX* ClosestFastTravelFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* ClosestFastTravelIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapIconEntry> RegionDotIconList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MapIconWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapScreenBase* BaseMapWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MapBPWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MapIconBPClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MapSpriteIconBPClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldSupportWorld* MapWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapLevelData> LevelsToLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* PlayerMarkerIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PlayerMarkerMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebugTextPanel* DebugTextPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WayMarkerScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* hoverIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* LastHoverIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIcon* LastHoverIconUnhover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapMovementComponent* MovementComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapPawn* MapPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIcon*> StackIcons;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomFadeStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ZoomFadeEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFrameCountToCover;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapAnalogControllerMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSnapDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapCameraParameters* CameraParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapCameraParameters* DebugCameraParameters;
    
    UMapBase();
    UFUNCTION(BlueprintCallable)
    bool TutorialDisablesMapBehavior_Blueprint(TEnumAsByte<EMapLocTypes::Type> MapBehavior);
    
protected:
    UFUNCTION(BlueprintCallable)
    void TrackHoveredMission();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetTurnOffFogCheck(bool pTurnOffFogCheck);
    
    UFUNCTION(BlueprintCallable)
    void SetLastHoveredIcon(UMapIcon* lastIcon);
    
    UFUNCTION(BlueprintCallable)
    void SetKnowledgeCardActive(bool pKnowledgeCardActive);
    
    UFUNCTION(BlueprintCallable)
    void SetHoveredIcon(UMapIcon* NewHoverIcon);
    
    UFUNCTION(BlueprintCallable)
    void SetCoverDisplayed(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetCoverAlpha(float Alpha);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ReturnCursorToPlayerLocation();
    
public:
    UFUNCTION(BlueprintCallable)
    void PlaceWayMarkerClick();
    
    UFUNCTION(BlueprintCallable)
    void PlaceWayMarkerBP();
    
    UFUNCTION(BlueprintCallable)
    void OnWaitPopupDismissed(UPopupScreen* Popup, int32 ConfirmationResult);
    
    UFUNCTION(BlueprintCallable)
    void OnMenuClosedStartFastTravel();
    
    UFUNCTION(BlueprintCallable)
    float IsWaitAvailable();
    
    UFUNCTION(BlueprintCallable)
    bool IsMissionByBeacon(UBeaconInfo* BeaconInfo);
    
    UFUNCTION(BlueprintCallable)
    static bool IsMissionBeaconNoArea(EBeaconType BeaconType);
    
    UFUNCTION(BlueprintCallable)
    static bool IsMissionBeacon(EBeaconType BeaconType);
    
private:
    UFUNCTION(BlueprintCallable)
    void InputReadyCallback();
    
    UFUNCTION(BlueprintCallable)
    void IconOutlineTextureCallback(UTexture2D* Texture, UObject* Param);
    
    UFUNCTION(BlueprintCallable)
    void IconInstanceTextureCallback(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    void GoToPreviousMap();
    
    UFUNCTION(BlueprintCallable)
    void GoToNextMap();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapZoomTypes::Type> GetZoomTypeBP();
    
    UFUNCTION(BlueprintCallable)
    float GetZoomFactor();
    
    UFUNCTION(BlueprintCallable)
    FName GetWorldName();
    
    UFUNCTION(BlueprintCallable)
    bool GetTurnOffFogCheck();
    
    UFUNCTION(BlueprintCallable)
    UWorldSupportWorld* GetMapWorld();
    
    UFUNCTION(BlueprintCallable)
    UMapScreenBase* GetMapWidget();
    
    UFUNCTION(BlueprintCallable)
    bool GetMapVisible();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapTypes::Type> GetMapType();
    
    UFUNCTION(BlueprintCallable)
    float GetMapScale();
    
private:
    UFUNCTION(BlueprintCallable)
    bool GetMapReadyCalled();
    
public:
    UFUNCTION(BlueprintCallable)
    APlayerController* GetMapPlayerController();
    
    UFUNCTION(BlueprintCallable)
    FName GetMapName();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapFadeState> GetMapFadeState();
    
    UFUNCTION(BlueprintCallable)
    UMapIcon* GetLastHoveredIcon();
    
    UFUNCTION(BlueprintCallable)
    bool GetKnowledgeCardActive();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsMouseDragging();
    
    UFUNCTION(BlueprintCallable)
    bool GetHoveredState();
    
    UFUNCTION(BlueprintCallable)
    UMapIcon* GetHoveredIcon();
    
    UFUNCTION(BlueprintCallable)
    bool GetCameraLerpInProgress();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanGoToMissionLogFromIcon(const UMapIcon* MapIcon) const;
    
    UFUNCTION(BlueprintCallable)
    void AdvanceTime();
    
};

