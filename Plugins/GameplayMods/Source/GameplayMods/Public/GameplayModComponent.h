#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ModEntry.h"
#include "PropertyList.h"
#include "GameplayModComponent.generated.h"

class UGameplayPropertyMod;
class UGameplayPropertyModGroup;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GAMEPLAYMODS_API UGameplayModComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ModEntries, meta=(AllowPrivateAccess=true))
    TArray<FModEntry> ModEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FModEntry> LocalModEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FModEntry> UnreplicatedModEntries;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UObject*, FPropertyList> ModdableObjectProperties;
    
public:
    UGameplayModComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetModBlackboardValue(const FGameplayTag& Tag, float Value, bool bForceRecomputeProperties);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveMod(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveGroup(const UGameplayPropertyModGroup* InModGroup);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddMod(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddGroup(const UGameplayPropertyModGroup* InModGroup);
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveTargetModdable(UObject* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void RemoveModReplicated(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable)
    void RemoveMod(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGroupReplicated(const UGameplayPropertyModGroup* InModGroup);
    
    UFUNCTION(BlueprintCallable)
    void RemoveGroup(const UGameplayPropertyModGroup* InModGroup);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ModEntries();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetModBlackboardValue(const FGameplayTag& Tag, float& OutValue) const;
    
    UFUNCTION(BlueprintCallable)
    void ExpungeTargetModdable(UObject* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void DelayedRemoveMod(const UGameplayPropertyMod* InMod);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientRemoveModManualReplication(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientRemoveGroupManualReplication(const UGameplayPropertyModGroup* InModGroup);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientAddModManualReplication(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientAddGroupManualReplication(const UGameplayPropertyModGroup* InModGroup);
    
public:
    UFUNCTION(BlueprintCallable)
    void AutoDetectModdables();
    
    UFUNCTION(BlueprintCallable)
    void AddTargetModdable(UObject* InTarget);
    
    UFUNCTION(BlueprintCallable)
    void AddModReplicated(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable)
    void AddMod(const UGameplayPropertyMod* InMod);
    
    UFUNCTION(BlueprintCallable)
    void AddGroupReplicated(const UGameplayPropertyModGroup* InModGroup);
    
    UFUNCTION(BlueprintCallable)
    void AddGroup(const UGameplayPropertyModGroup* InModGroup);
    
};

