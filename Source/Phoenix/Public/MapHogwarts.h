#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EMapZoomTypes.h"
#include "HogwartsRegion.h"
#include "MapBase.h"
#include "Templates/SubclassOf.h"
#include "MapHogwarts.generated.h"

class AActor;
class AMapHogwartsCamera;
class AMapLocationActor;
class APhoenixPathActor;
class ATargetPoint;
class UHogwartsMapScreen;
class UMapPath;
class UMaterialInstanceDynamic;
class UObject;
class UTexture2D;
class UWorld;

UCLASS(Blueprintable)
class UMapHogwarts : public UMapBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugPathHelper;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APhoenixPathActor*> MapPathActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Road50Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Road100Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Road200Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor RoadUnknownColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RegionHoverOverAlpha;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> RegisteredMarkupActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PathDynamicMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapHogwartsCamera* StartCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMapHogwartsCamera* CurrentCamera;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMapLocationActor*> OtherObjectsToDarken;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ATargetPoint*> TargetPointActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMapPath*> OverlandMapPaths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FHogwartsRegion> Regions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> MissionsForThisRegion;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FVector> FastTravelLocations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FString> SubLevelNameToMapName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowDebugMapPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowPathDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowZoneBanner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMapLocationActor*> LocationActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapIconTier3ScaleFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MapIconTier4ScaleFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultIconScale;
    
    UMapHogwarts();
private:
    UFUNCTION(BlueprintCallable)
    void WayPointCallbackHogwarts(UTexture2D* Texture, UObject* Param);
    
public:
    UFUNCTION(BlueprintCallable)
    static void UnregisterMarkupActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void TestEvent();
    
    UFUNCTION(BlueprintCallable)
    void ShowPortraitTravel(const TMap<FString, FVector>& Locations);
    
    UFUNCTION(BlueprintCallable)
    void SetZoomType(EMapZoomTypes::Type ZoomType);
    
    UFUNCTION(BlueprintCallable)
    void SetUseNewIcons(bool pUseNewIcons);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterMarkupActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void OverlandMapZoom(float Val);
    
private:
    UFUNCTION()
    void OnStartPathing(const UObject* i_caller, uint32 BeaconHandle);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMapItemSelected_Event(const FString& ItemString, const int32 ItemIndex, const bool WasCanceled);
    
    UFUNCTION(BlueprintCallable)
    void OnMapItemSelected(FString& ItemString, int32 ItemIndex, bool WasCanceled);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnCameraBlendComplete();
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsBannerActive();
    
    UFUNCTION(BlueprintCallable)
    bool InHogwartsLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    bool InHogwarts();
    
private:
    UFUNCTION(BlueprintCallable)
    void HandleMapLocationChanged(const UObject* Caller, const FString& CurrentMapLocationName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GiveMeHelp_Event();
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EMapZoomTypes::Type> GetZoomType(float Zoom);
    
    UFUNCTION(BlueprintCallable)
    bool GetUseNewIcons();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetMissionsForThisRegion();
    
    UFUNCTION(BlueprintCallable)
    FVector GetMapTransform();
    
    UFUNCTION(BlueprintCallable)
    UHogwartsMapScreen* GetMapScreenWidget();
    
    UFUNCTION(BlueprintCallable)
    FString GetMapLocationName();
    
    UFUNCTION(BlueprintCallable)
    void GetAllActorsWithTag(UWorld* World, FName Tag, TArray<AActor*>& Actors);
    
    UFUNCTION(BlueprintCallable)
    void GetAllActorsOfClass(UWorld* World, TSubclassOf<AActor> ActorClass, TArray<AActor*>& Actors);
    
private:
    UFUNCTION(BlueprintCallable)
    void CheckLoadedProperly();
    
public:
    UFUNCTION(BlueprintCallable)
    void ChangeTier();
    
    UFUNCTION(BlueprintCallable)
    float CalulatePathDistance(TArray<FVector> InPathPoints);
    
    UFUNCTION(BlueprintCallable)
    void ActivateFastTravelByIcon();
    
    UFUNCTION(BlueprintCallable)
    void ActivateFastTravel(const FString& LocationID, FVector FastTravelDestination);
    
    UFUNCTION(BlueprintCallable)
    void ActivateBanner(bool ACTIVE);
    
};

