#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnActiveIslandSetDelegate.h"
#include "OnMinimumLoadCompleteDelegate.h"
#include "OnZoneIsReadyCallbackDelegate.h"
#include "OnZoneIsVisibleDelegate.h"
#include "SanctuaryStreamingIslandDefinition.h"
#include "SanctuaryStreamingController.generated.h"

class ASanctuaryStreamingController;
class UObject;
class UWorld;

UCLASS(Blueprintable)
class ASanctuaryStreamingController : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UWorld>> GlobalLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSanctuaryStreamingIslandDefinition> Islands;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTreatLightingLevelsAsMinimalLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ActiveIsland;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bTeleportLockActive;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnActiveIslandSet OnActiveIslandSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMinimumLoadComplete OnMinimumLoadComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnZoneIsVisible OnZoneIsVisible;
    
    ASanctuaryStreamingController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UnlockLockForZone(FName ZoneName);
    
    UFUNCTION(BlueprintCallable)
    void UnloadZoneExplicitly(FName ZoneName);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveIslandFromZone(FName InZoneName);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveIsland(FName InActiveIsland);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void RequestZoneReadyToEnter(UObject* WorldContextObject, FName ZoneName, FOnZoneIsReadyCallback OnZoneIsReady, bool bIgnoreLock);
    
    UFUNCTION(BlueprintCallable)
    void RequestZoneLoad(FName ZoneName, bool bMakeVisible, bool bIgnoreLock);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnUpdateStreamingState();
    
public:
    UFUNCTION(BlueprintCallable)
    void MakeZoneVisible(FName ZoneName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneUnlocked(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneReadyToEnter(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneMinimumLoadVisible(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneMinimumLoadComplete(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneCompletelyVisible(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable)
    void HideParallelLevelsInInactiveIslands();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetIslandForZone(FName InZoneName) const;
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static ASanctuaryStreamingController* Get(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesZoneExist(FName ZoneName) const;
    
    UFUNCTION(BlueprintCallable)
    void BlockingMinimalZoneLoad(FName ZoneName, bool bMakeVisible);
    
};

