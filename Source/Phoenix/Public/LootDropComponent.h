#pragma once
#include "CoreMinimal.h"
#include "LootDropInfo.h"
#include "Components/ActorComponent.h"
#include "InventoryResult.h"
#include "LootSlot.h"
#include "OnInventoryUpdatedDelegate.h"
#include "LootDropComponent.generated.h"

class AActor;
class ULootDropComponent;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ULootDropComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLootDropInfo DbLootDropInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LootDropLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> LootContainers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLootSlot> LootItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlayerLevelOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SecondsBeforeRerollingLoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCogOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PersistentID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetExpiryIfUnique;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnInventoryUpdated OnInventoryUpdated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreloadLootDropItemsFromDb;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> LootDropAssetTypes;
    
public:
    ULootDropComponent();
    UFUNCTION(BlueprintCallable)
    void SetupInventory();
    
    UFUNCTION(BlueprintCallable)
    void SetLootLevel(int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void SetLoopGroup(const FString& lootGroup);
    
    UFUNCTION(BlueprintCallable)
    void SetCurrentLootCategoryID();
    
    UFUNCTION(BlueprintCallable)
    void SaveLootToInventory();
    
    UFUNCTION(BlueprintCallable)
    void SaveLootItemsToInventory(TArray<FLootSlot>& InLootItems);
    
    UFUNCTION(BlueprintCallable)
    bool IsContainerEmpty();
    
    UFUNCTION(BlueprintCallable)
    int32 GetLootLevel();
    
    UFUNCTION(BlueprintCallable)
    TArray<FLootSlot> GetLootItems();
    
    UFUNCTION(BlueprintCallable)
    static ULootDropComponent* GetLootDropComponent(const AActor* InActor);
    
    UFUNCTION(BlueprintCallable)
    TArray<FInventoryResult> GetInventoryInfo();
    
    UFUNCTION(BlueprintCallable)
    void FillFromInventory();
    
    UFUNCTION(BlueprintCallable)
    static void ClearCurrentLootCategoryID();
    
};

