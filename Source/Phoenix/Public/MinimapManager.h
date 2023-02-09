#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EMiniMapLevels.h"
#include "EMiniMapSizeOption.h"
#include "HUDElementGroup.h"
#include "MiniMapSaveDataBlob.h"
#include "MinimapManager.generated.h"

class AActor;
class APawn;
class APlayerController;
class UCanvasPanel;
class UImage;
class UMapIconList;
class UMapIconMeshRenderWidget;
class UMapSubSystem;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UMinimapBase;
class UMinimapDungeon;
class UMinimapHogsmeade;
class UMinimapHogwarts;
class UMinimapOverland;
class UMinimapSanctuary;
class UMinimapTents;
class UMinimapTutorial;
class UObject;
class USharedMinimapData;
class UTexture2D;
class UTextureUtil;
class UWidget;

UCLASS(Blueprintable, EditInlineNew)
class UMinimapManager : public UHUDElementGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* MaskedIconContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* UnmaskedIconContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* FadeCircle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USharedMinimapData* SharedMinimapData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IconRange1Arrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IconRange2Arrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IconRange3Arrow;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMiniMapSaveDataBlob MiniMapSaveDataBlob;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FString, UMapIconMeshRenderWidget*> IconInstanceRenderWidgets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTextureUtil* IntrusionBlitter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* IntrusionTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* IntrusionFXActor;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* IconClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* IconRenderWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetPulseMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetGlowMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetSimpleMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderWidgetPathMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* IconRenderAreaBeaconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* MinimapWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* PlayerPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* PrevPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APlayerController* PlayerController;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMinimapBase*> MiniMaps;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapBase* ActiveMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapOverland* OverlandMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapHogwarts* HogwartsMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapHogsmeade* HogsmeadeMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapDungeon* DungeonMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapTutorial* TutorialMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapSanctuary* SanctuaryMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapTents* TentsMiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapBase* FadingOutMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMinimapBase* FadingInMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MiniMapVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWidget*> MapWidgetsToRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWidget*> PlayerWidgetsToRotate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimapCamRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MiniMapPlayerRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> UpdatePath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PathMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PathMaterialDynamic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* PathImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapIconList*> MapIconListArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapIconList* PathIconList;
    
public:
    UMinimapManager();
    UFUNCTION(BlueprintCallable)
    void UnrevealMiniMapInternal();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UnrevealMiniMapEvent(bool InstantIntro);
    
    UFUNCTION(BlueprintCallable)
    void UnrevealMiniMap(bool InstantIntro, bool ForceUnreveal, bool fromHUD);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TurnOnCloudyMiniMapEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TurnOnCloudyMiniMapDarkEvent();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TurnOffCloudyMiniMapEvent();
    
    UFUNCTION(BlueprintCallable)
    void SwitchToPlayerPawn();
    
    UFUNCTION(BlueprintCallable)
    void SwitchToHoverdronePawn(APawn* HoverPawn);
    
    UFUNCTION(BlueprintCallable)
    void Shutdown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowPathLayerEvent(bool Enable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ShowMiniMapEvent(bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void ShowMiniMap(bool Enable);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetVisibleOpacityMiniMapEvent(bool Visible, float Opacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetOpacityQucikMiniMapEvent(float Opacity, float MapOpacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetOpacityMiniMapEvent(float Opacity);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapWidgetSize(FVector2D Size);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapSize(float Size, float ZoomTime);
    
    UFUNCTION(BlueprintCallable)
    void SetMiniMapLevel(EMiniMapLevels::Type LevelType, bool hideCurrentMap, bool ShowMap, bool LoadNavMesh, bool AllowMiniMapReveal);
    
    UFUNCTION(BlueprintCallable)
    void SetLockMiniMapReveal(bool pLockMiniMapReveal);
    
    UFUNCTION(BlueprintCallable)
    void SetIsDroneMap(bool pIsDroneMap);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetIntrusionAlertOnBP(bool Enable);
    
public:
    UFUNCTION(BlueprintCallable)
    void SetIntrusionAlertOn(bool pIntrusionAlertOn);
    
    UFUNCTION(BlueprintCallable)
    void SetInTentTransition(bool pInTentTransition);
    
    UFUNCTION(BlueprintCallable)
    void SanctuarySetHubUnlock(const FString& NameOfUnlock);
    
    UFUNCTION(BlueprintCallable)
    void RevealMiniMapInternalTents();
    
    UFUNCTION(BlueprintCallable)
    void RevealMiniMapInternal();
    
    UFUNCTION(BlueprintCallable)
    void RevealMiniMapInstantInternal();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RevealMiniMapEvent(bool InstantIntro);
    
    UFUNCTION(BlueprintCallable)
    void RevealMiniMap(bool InstantIntro, bool fromHUD);
    
    UFUNCTION(BlueprintCallable)
    void RemoveIntrusionArea(AActor* IntrusionActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuickFadeOutMinimapEvent();
    
    UFUNCTION(BlueprintCallable)
    void QuickFadeOutMinimap();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void QuickFadeInMinimapEvent();
    
    UFUNCTION(BlueprintCallable)
    void QuickFadeInMinimap();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MinimapScaleChanged(EMiniMapSizeOption MiniMapSize);
    
    UFUNCTION(BlueprintCallable)
    bool IsParentHoverDrone();
    
    UFUNCTION(BlueprintCallable)
    void IconTextureCallback(UTexture2D* Texture, UObject* Param);
    
private:
    UFUNCTION(BlueprintCallable)
    void HoverdroneToggleMinimap(bool bShowMiniMap);
    
protected:
    UFUNCTION(BlueprintCallable)
    void HandlePlayerAndMapRotation();
    
    UFUNCTION(BlueprintCallable)
    void HandleMapRotation();
    
public:
    UFUNCTION(BlueprintCallable)
    UMinimapTutorial* GetTutorialMiniMap();
    
    UFUNCTION(BlueprintCallable)
    UMinimapTents* GetTentsMiniMap();
    
    UFUNCTION(BlueprintCallable)
    UMinimapSanctuary* GetSanctuaryMiniMap();
    
    UFUNCTION(BlueprintCallable)
    UMinimapOverland* GetOverlandMiniMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetMiniMapVisibility();
    
    UFUNCTION(BlueprintCallable)
    float GetMiniMapSize();
    
protected:
    UFUNCTION(BlueprintCallable)
    UMapSubSystem* GetMapSubsytem();
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetIsDroneMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetIntrusionAlertOn();
    
    UFUNCTION(BlueprintCallable)
    bool GetInTentTransition();
    
    UFUNCTION(BlueprintCallable)
    UMinimapHogwarts* GetHogwartsMiniMap();
    
    UFUNCTION(BlueprintCallable)
    UMinimapHogsmeade* GetHogsmeadeMiniMap();
    
    UFUNCTION(BlueprintCallable)
    UMinimapDungeon* GetDungeonMiniMap();
    
    UFUNCTION(BlueprintCallable)
    bool GetAreIntrusionAreasActive();
    
    UFUNCTION(BlueprintCallable)
    UMinimapBase* GetActiveMiniMap();
    
protected:
    UFUNCTION(BlueprintCallable)
    UMinimapBase* FindMapByName(const FString& MapName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DoMapTransitionStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DoMapTransitionEnd();
    
public:
    /*UFUNCTION(BlueprintCallable)
    void BeginPlay();
    
    UFUNCTION(BlueprintCallable)
    void BeginDestroy();*/
    
protected:
    UFUNCTION(BlueprintCallable)
    void AddMiniMap(UMinimapBase* pMiniMapbase);
    
public:
    UFUNCTION(BlueprintCallable)
    void AddIntrusionArea(AActor* IntrusionActor);
    
};

