#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "Engine/EngineTypes.h"
#include "StreamingPlaceholderActor.h"
#include "SanctuaryHousekeepingPlaceholder.generated.h"

class AActor;
class AForagable;
class UObject;
class UStaticMesh;

UCLASS(Blueprintable)
class ASanctuaryHousekeepingPlaceholder : public AStreamingPlaceholderActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo HousekeepingType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo ZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LockId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LockID2;
    
    UPROPERTY(EditAnywhere, TextExportTransient, meta=(AllowPrivateAccess=true))
    uint32 UID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* StaticMeshOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo LootID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsAliveOnFirstLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsSpawnedInAsOwnActor;
    
public:
    ASanctuaryHousekeepingPlaceholder(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void OnForagableCollected(AForagable* Actor);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnChildActorEndPlay(AActor* Actor, TEnumAsByte<EEndPlayReason::Type> EndPlayReason);
    
public:
    UFUNCTION(BlueprintCallable)
    void HandleBreakableDestroyed(const UObject* i_caller);
    
};

