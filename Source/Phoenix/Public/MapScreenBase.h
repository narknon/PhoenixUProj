#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InputCoreTypes.h"
#include "UMGConsolidatedAxisInputData.h"
#include "EMapScreenMouseButtonID.h"
#include "EMapTypes.h"
#include "EMapZoomTypes.h"
#include "ERegionType.h"
#include "LegendItemData.h"
#include "MapScreenMouseButton.h"
#include "MapToolTipData.h"
#include "TabPageWidget.h"
#include "MapScreenBase.generated.h"

class AActor;
class AMapPawn;
class UCanvasPanel;
class UFastTravelList;
class UMapBase;
class UMapIcon;
class UMapRegionInfoWidget;
class UMapSubSystem;
class UPhoenixTextBlock;
class UToolTipPopoutWidget;
class UUIManager;
class UUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class UMapScreenBase : public UTabPageWidget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UToolTipPopoutWidget* ToolTipPopup2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapRegionInfoWidget* RegionInfoPopup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPhoenixTextBlock* DebugRegion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapPawn* MapPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFastTravelList* FastTravelList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* IconContainer;
    
    UMapScreenBase();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ZoomOutReleased_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ZoomOutPressed_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ZoomInReleased_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ZoomInPressed_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WayPointUnset_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void WayPointSet_Event();
    
    UFUNCTION(BlueprintCallable)
    void UnregisterBButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TierChanged_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowOverlandMissionsAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowHogwartsMissionsAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowHogsmeadeMissionsAvailable();
    
    UFUNCTION(BlueprintCallable)
    void ShowFastTravelList();
    
    UFUNCTION(BlueprintCallable)
    void SetZoomType(EMapZoomTypes::Type ZoomType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetTipLegend_Event(const FText& NewLegend);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetPath();
    
    UFUNCTION(BlueprintCallable)
    void SetMouseDelta(FVector2D Delta);
    
    UFUNCTION(BlueprintCallable)
    void SetMapType(EMapTypes::Type MapType);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLocationName_Event(const FString& PrimarayLocationName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLevelName_Event(const FString& LevelName);
    
    UFUNCTION(BlueprintCallable)
    void SetLegendStrings(TArray<FLegendItemData>& LegendStrings);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetLegend(const TArray<FLegendItemData>& LegendStrings);
    
    UFUNCTION(BlueprintCallable)
    void SetIsFilterShowing(bool ShowFilter);
    
    UFUNCTION(BlueprintCallable)
    void SetIconContainerSize();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCoverVisibilityAlpha_Event(float Alpha);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetCoverVisibility_Event(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetCoverVisibility(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void SetCoverAlpha(float Alpha);
    
    UFUNCTION(BlueprintCallable)
    bool ScreenHandleInput(FKey Input);
    
    UFUNCTION(BlueprintCallable)
    void RightMouseButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void RightMouseButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    void RegisterBButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RegionInfoUpdated_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RegionHovered_Event(ERegionType MapRegion, int32 RegionIndex, UUserWidget* IconWidget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayIconBurst_Event(AActor* NiagaraActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlayFanfare_Event(UMapIcon* Icon);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdateToolTip_Event(FMapToolTipData ToolTipData);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnhovered_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnHovered_Event(FMapToolTipData ToolTipData);
    
    UFUNCTION(BlueprintCallable)
    bool MouseTimeGreaterThanClick(TEnumAsByte<EMapScreenMouseButtonID> buttonID);
    
    UFUNCTION(BlueprintCallable)
    void MiddleMouseButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void MiddleMouseButtonPressed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MapStop_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MapStart_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MapMove_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MapChanged_Event();
    
    UFUNCTION(BlueprintCallable)
    void LockMapInput(bool Lock);
    
    UFUNCTION(BlueprintCallable)
    void LeftMouseButtonReleased();
    
    UFUNCTION(BlueprintCallable)
    void LeftMouseButtonPressed();
    
    UFUNCTION(BlueprintCallable)
    bool IsMouseButtonAClick(TEnumAsByte<EMapScreenMouseButtonID> buttonID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFastTravelListVisible();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsAnyTutorialActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void IconShown_Event(UMapIcon* iconHidden);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void IconHidden_Event(UMapIcon* iconHidden);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HitMapBounds_Event();
    
    UFUNCTION(BlueprintCallable)
    void HideFastTravelList();
    
    UFUNCTION(BlueprintCallable)
    float GetZoomInputDelta();
    
    UFUNCTION(BlueprintCallable)
    float GetZoomFactor();
    
    UFUNCTION(BlueprintCallable)
    UUIManager* GetUIManager();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapZoomTypes::Type> GetTier();
    
    UFUNCTION(BlueprintCallable)
    float GetPressedButtonTime(TEnumAsByte<EMapScreenMouseButtonID> buttonID);
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetMovementDelta();
    
    UFUNCTION(BlueprintCallable)
    FVector2D GetMouseDelta();
    
    UFUNCTION(BlueprintCallable)
    FMapScreenMouseButton GetMouseButtonInput(TEnumAsByte<EMapScreenMouseButtonID> buttonID);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapTypes::Type> GetMapType();
    
    UFUNCTION(BlueprintCallable)
    UMapSubSystem* GetMapSubSystem();
    
    UFUNCTION(BlueprintCallable)
    UMapBase* GetMapBase();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsMouseInScreen();
    
    UFUNCTION(BlueprintCallable)
    bool GetIsFilterShowing();
    
    UFUNCTION(BlueprintCallable)
    FUMGConsolidatedAxisInputData GetInputAxisData();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitMapScreen_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableOverlandButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableHogwartsButton();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DisableHogsmeadeButton();
    
    UFUNCTION(BlueprintCallable)
    void ClearMouseButtons();
    
    UFUNCTION(BlueprintCallable)
    void ClearMouseButton(EMapScreenMouseButtonID buttonID);
    
};

