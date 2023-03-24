#pragma once
#include "CoreMinimal.h"
#include "BeaconableObject.h"
#include "EInventoryObjectSpawnType.h"
#include "WorldObject.h"
#include "InventoryObject.generated.h"

class UAkAudioEvent;

UCLASS(Blueprintable)
class AInventoryObject : public AWorldObject, public IBeaconableObject {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPickedUpHandlerMulti, FName, ItemId, int32, ItemCount);
    DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnPickedUpHandler, FName, ItemId, int32, ItemCount);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UnitCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsStolen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsUnique;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variation;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    int64 RespawnTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EInventoryObjectSpawnType> SpawnType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* m_pickupSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BeaconableObjectID;
    
    AInventoryObject(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetItemData(FName ItemId, int32 ItemCount, FName InVariation, bool InIsStolen, bool InIsUnique);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyPickedUp(FName ItemId, int32 ItemCount);
    
    UFUNCTION(BlueprintCallable)
    void AddPickedUpHandler(const AInventoryObject::FOnPickedUpHandler& Handler);
    
    
    // Fix for true pure virtual functions not being implemented
};

