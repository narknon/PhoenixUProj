#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ObjectStateCollisionPair.h"
#include "OriginalInfo.h"
#include "ObjectStateManager.generated.h"

class AActor;
class ABase_Character;
class UCharacterStateInfo;
class UContextFilterComponent;
class UMaterialPropertyData;
class UObjectStateInfo;
class UObjectStateManager;
class UReparoData;
class UUnloadLevelTracker;
class UWorld;

UCLASS(Blueprintable, Transient)
class PHOENIX_API UObjectStateManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, UObjectStateInfo*> OsiMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObjectStateInfo*> OsiActiveList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObjectStateInfo*> OsiInactiveList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObjectStateInfo*> OsiToActivateLater;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<AActor*, AActor*> OverrideRepairLocationMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UMaterialPropertyData*> MaterialPropertyMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> PlayerActorList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FObjectStateCollisionPair> CollisionPairs;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> World;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FOriginalInfo> OriginalInfoMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UObjectStateInfo*> OsiRemovedMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UContextFilterComponent* ContextFilterComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UUnloadLevelTracker*> UnloadTrackerArray;
    
public:
    UObjectStateManager();
    UFUNCTION(BlueprintCallable)
    void UpdateOriginalInfo(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    void SetOriginalTransform(AActor* InActor, FTransform InTransform);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnActorEndPlay(AActor* DestroyedActor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
public:
    UFUNCTION(BlueprintCallable)
    static bool IsRevelioActor(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static void HighlightActorWithRevelio(AActor* InActor, bool bHighlight);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContext"))
    static UObjectStateManager* GetObjectStateManager(const UObject* WorldContext);
    
    UFUNCTION(BlueprintCallable)
    static UObjectStateInfo* GetObjectStateInfo(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetDbUniqueId(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetDbSubType(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetDbId(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static FName GetDbClassId(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static UCharacterStateInfo* GetCharacterStateInfo(const ABase_Character* InCharacter);
    
    UFUNCTION(BlueprintCallable)
    static UObjectStateManager* Get(UWorld* NewWorld);
    
    UFUNCTION(BlueprintCallable)
    static void EnableCcdForXSeconds(AActor* InActor, float Time);
    
    UFUNCTION(BlueprintCallable)
    static bool EnableCcd(AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    static void EnableAutoRepair(UObject* InObject, float MinRepairDelay, float MaxRepairDelay, UReparoData* ReparoDataOverride);
    
    UFUNCTION(BlueprintCallable)
    static void DisableAutoRepair(UObject* InObject);
    
};

