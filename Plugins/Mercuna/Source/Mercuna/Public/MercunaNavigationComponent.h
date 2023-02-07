#pragma once
#include "CoreMinimal.h"
#include "AITypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Engine/LatentActionManager.h"
#include "EMercunaMoveResult.h"
#include "MercunaNavigationConfiguration.h"
#include "MercunaPawnUsageFlags.h"
#include "MercunaNavigationComponent.generated.h"

class AActor;
class AMercunaNavOctree;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class MERCUNA_API UMercunaNavigationComponent : public UActorComponent {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMercunaMoveComplete, FAIRequestID, RequestID, const TEnumAsByte<EMercunaMoveResult::Type>, Result);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaMoveComplete OnMoveCompleted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaNavigationConfiguration Configuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AMercunaNavOctree* NavOctree;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Pathfinding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DynamicAvoidance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMercunaPawnUsageFlags UsageFlags;
    
public:
    UMercunaNavigationComponent();
    UFUNCTION(BlueprintCallable)
    void TrackActor(AActor* Actor, float Distance, float Speed, bool SkipCheckNav);
    
    UFUNCTION(BlueprintCallable)
    void Stop();
    
    UFUNCTION(BlueprintCallable)
    void SetUsageFlags(FMercunaPawnUsageFlags& NewUsageFlags);
    
    UFUNCTION(BlueprintCallable)
    void SetNavOctree(AMercunaNavOctree* NewNavOctree);
    
    UFUNCTION(BlueprintCallable)
    void SetEnabled(bool bEnable);
    
    UFUNCTION(BlueprintCallable)
    void SetAvoidanceAgainst(AActor* Actor, bool Enable);
    
    UFUNCTION(BlueprintCallable)
    void ResumeNavigation();
    
    UFUNCTION(BlueprintCallable)
    void PauseNavigation();
    
    UFUNCTION(BlueprintCallable)
    void MoveToLocations(const TArray<FVector>& Destinations, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav);
    
    UFUNCTION(BlueprintCallable)
    void MoveToLocation(const FVector& Destination, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav);
    
    UFUNCTION(BlueprintCallable)
    void MoveToActor(AActor* Actor, float EndDistance, float Speed, bool UsePartialPath, bool SkipCheckNav);
    
    UFUNCTION(BlueprintCallable)
    void LookInDirection(FVector Direction, float MaxPitch);
    
    UFUNCTION(BlueprintCallable)
    void LookAt(AActor* Actor, float MaxPitch);
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    void IsReachable(FVector Point, bool& Success, UObject* WorldContextObject, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable)
    void GetPathInfo(bool& Valid, float& DistanceToEnd, FVector& NextPathPoint, bool& bIsFinalPoint);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMercunaNavOctree* GetNavOctree() const;
    
    UFUNCTION(BlueprintCallable)
    void ConfigureMovement(bool bUsePathfinding, bool bUseDynamicAvoidance);
    
    UFUNCTION(BlueprintCallable)
    void Configure(const FMercunaNavigationConfiguration& NewConfiguration);
    
    UFUNCTION(BlueprintCallable)
    void ClearAvoidanceExclusions();
    
    UFUNCTION(BlueprintCallable, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    void CheckReachable(FVector Point, bool& Success, UObject* WorldContextObject, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable)
    void CancelMovement();
    
    UFUNCTION(BlueprintCallable)
    void CancelLookAt();
    
    UFUNCTION(BlueprintCallable)
    void AddDestinationLocation(FVector NextDestination);
    
};

