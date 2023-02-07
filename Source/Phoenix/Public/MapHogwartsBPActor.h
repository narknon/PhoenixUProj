#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "EMap3DState.h"
#include "LocationGroup.h"
#include "MapBaseActor.h"
#include "PathLocationData.h"
#include "MapHogwartsBPActor.generated.h"

class AActor;
class AMapLocationActor;
class ULevelData;
class ULevelStreamingDynamic;
class UMapCameraParameters;
class UMapData;
class UMapHogwarts;
class UMapLocation;
class UMapMarkupComponent;
class UMapObjectComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UScheduledEntity;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class AMapHogwartsBPActor : public AMapBaseActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PathMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* PostProcessMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* PostProcessMaterialInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapLocation* TestLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TargetNPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HasTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorScaleFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector DecalSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 MapBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector4 ScreenBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CursorSnapDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMapTargetScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UScheduledEntity* MapTargetScheduledEntity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsMapTargetWorldLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector MapTargetWorldLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPathLocationData> PathMapLocationList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowFloors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseNavPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PathWorldMarkerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UpdatePathOnPrimaryLocationChange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePointsOfInterest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FVector> PointsOfInterest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, FLocationGroup> Groups;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WorldToMapOffset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapData* MapData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapData* FloorData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapData* StairData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PlayerMarkerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* FocusPointActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* PathEndActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* IsolationMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BaseColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor OriginColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor PathColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseZoomMaterailForPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UVDistanceMul;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelData*> LevelData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseComplexCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapCameraParameters* CameraParametersBirdsEye;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMapObjectComponent* DefaultStartComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DebugStairVolumeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DebugRoomVolumeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DebugFloorVolumeMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TranslateSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> PathPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* NextPathPointActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LastLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString TargetName;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelData*> PathStructures;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMapLocation* LastMapLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> HitPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> MissPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> DebugRayStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> DebugRayEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULevelStreamingDynamic* NavMeshLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> DebugActors;
    
public:
    AMapHogwartsBPActor();
    UFUNCTION(BlueprintCallable)
    void SetStaticMapTarget(FVector Target);
    
    UFUNCTION(BlueprintCallable)
    void SetNextState(EMap3DState NewState);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicMapTarget(UScheduledEntity* Target);
    
private:
    UFUNCTION(BlueprintCallable)
    void PushLocationListToScreen(const TArray<FString> InLocationList, int32 InStartIndex);
    
    UFUNCTION(BlueprintCallable)
    void PushLocaitonNameToScreen(const FString& LocationName);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToSingleState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToSingleState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToSingleState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToGroupState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToGroupState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToGroupState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToCastleState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToCastleState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransitionToCastleState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSingleState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSingleState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSingleState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGroupState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGroupState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGroupState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFastTravelState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFastTravelState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFastTravelState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDiscoverState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDiscoverState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDiscoverState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCastleState_Update_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCastleState_Start_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCastleState_Exit_Event();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivate_Event(bool Activate);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GiveMeHelp_Event();
    
    UFUNCTION(BlueprintCallable)
    void GiveMeHelp();
    
public:
    UFUNCTION(BlueprintCallable)
    EMap3DState GetState();
    
    UFUNCTION(BlueprintCallable)
    FString GetRoomStairFloorString(UMapMarkupComponent* MapLocation, UMapMarkupComponent* StairLocation, UMapLocation* FloorLocation, UMapLocation* PrimaryrLocation, bool IsOnlyPrimaryLocation);
    
    UFUNCTION(BlueprintCallable)
    bool GetIsActive();
    
    UFUNCTION(BlueprintCallable)
    UMapHogwarts* GetHogwartsMap();
    
    UFUNCTION(BlueprintCallable)
    AMapLocationActor* FindLocationActorThatContainsPoint(FVector Point);
    
    UFUNCTION(BlueprintCallable)
    AMapLocationActor* FindLocationActorBelowPoint(FVector Point);
    
    UFUNCTION(BlueprintCallable)
    void DoUp();
    
    UFUNCTION(BlueprintCallable)
    void DoSelect();
    
    UFUNCTION(BlueprintCallable)
    void DoDown();
    
    UFUNCTION(BlueprintCallable)
    void DoBack();
    
    UFUNCTION(BlueprintCallable)
    void ClearMapTarget();
    
};

