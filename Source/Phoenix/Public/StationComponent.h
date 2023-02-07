#pragma once
#include "CoreMinimal.h"
#include "ECalloutActions.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DbDoubleColumnInfo.h"
#include "DbSingleColumnInfo.h"
#include "Components/ActorComponent.h"
#include "EEnterExitAnimVariants.h"
#include "ESpawnedStationTypes.h"
#include "EStationDataType.h"
#include "EStationInteraction.h"
#include "EStationPlayerInteractionPermissions.h"
#include "EStationSnapConnectionsToGround.h"
#include "EVolumeType.h"
#include "PropTypeIDs.h"
#include "StationQueryData.h"
#include "StationValidationError.h"
#include "StoryDirector_Interface.h"
#include "Templates/SubclassOf.h"
#include "StationComponent.generated.h"

class APawn;
class UBoxComponent;
class UMeshComponent;
class UObject;
class UPhxAnimationSharingSetup;
class UPrimitiveComponent;
class USkeletalMesh;
class UStaticMesh;
class UStoryTeller;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class PHOENIX_API UStationComponent : public UActorComponent, public IStoryDirector_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsDeprecated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 m_Version;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_IsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationDataType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ESpawnedStationTypes> SpawnedStationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_DbLocationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_DbStudentID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbDoubleColumnInfo StationInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo StationPropInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* PropStaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* PropSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo CollisionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisallowSpellReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_DbParentLocationID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bGeneratePathing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimationPickingRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StitchingActivateRadius;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoryTeller* StoryTeller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SetupFlags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool EavesdropStation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowT4s;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPhxAnimationSharingSetup> T4AnimSharingSetupMaleFemale[2];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowStitching;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableIKFloorContact;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationPlayerInteractionPermissions> PIP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 SetupHouseAndGender;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> ProhibitedSubTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> ExclusiveSubTypes;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEnterExitAnimVariants> EnterExitAnimations[9];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EStationSnapConnectionsToGround> SnapConnectionsToTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CreateDynamicObstacle;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_DbReferenceNPCID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECalloutActions InteractionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsVisible;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVolumeType VolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Volume;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PatrolStationPriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PatrolStationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LimitPatrolToSingleUsePerCycle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bProhibitAutoLocationSetting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PlayerInVicinityVolumeExtents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UBoxComponent* PlayerInVicinityVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString PropMeshFullPath;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMeshComponent* MeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EnterBlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAnimDriveStiffness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ForceParticipateInSit;
    
    UStationComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool WillParticipateInSit() const;
    
    UFUNCTION(BlueprintCallable)
    void ValidateStation(TArray<FStationValidationError>& OutErrors);
    
    UFUNCTION(BlueprintCallable)
    void SetStationActive(bool Inactive);
    
    UFUNCTION(BlueprintCallable)
    void SetPropSelection(const FString& DesiredProp);
    
    UFUNCTION(BlueprintCallable)
    bool RequestAssetPreload();
    
    UFUNCTION(BlueprintCallable)
    bool IsStationBreakable();
    
    UFUNCTION(BlueprintCallable)
    bool IsStationActive();
    
    UFUNCTION(BlueprintCallable)
    bool IsAChair();
    
    UFUNCTION(BlueprintCallable)
    bool IsABookShelf();
    
    UFUNCTION(BlueprintCallable)
    bool IsABed();
    
    UFUNCTION(BlueprintCallable)
    int32 InitializeStationInteraction(UObject* InObject, EStationInteraction InDesiredInteraction, const FStationQueryData& InStationData, bool InDeferred, bool InWantCallback, float InTimeRequest, bool InJustGettingOptions);
    
    UFUNCTION(BlueprintCallable)
    bool GetStationUsers(TArray<UObject*>& outStationUsers);
    
    UFUNCTION(BlueprintCallable)
    FTransform GetSocketTransform(FName InSocketName);
    
    UFUNCTION(BlueprintCallable)
    TEnumAsByte<PropTypeIDs> GetPropType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumConnections();
    
    UFUNCTION(BlueprintCallable)
    FString GetMeshName();
    
    UFUNCTION(BlueprintCallable)
    UMeshComponent* GetMeshComponent();
    
    UFUNCTION(BlueprintCallable)
    ECalloutActions GetInteractionText();
    
    UFUNCTION(BlueprintCallable)
    EStationInteraction GetCurrentInteraction(int32 InInteractionID);
    
    UFUNCTION(BlueprintCallable)
    FTransform GetConnectionStartTransform(int32 InIndex);
    
    UFUNCTION(BlueprintCallable)
    int32 GetClosestConnection(APawn* PlayerPawn);
    
    
    // Fix for true pure virtual functions not being implemented
};

