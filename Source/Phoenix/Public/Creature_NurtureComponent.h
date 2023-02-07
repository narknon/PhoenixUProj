#pragma once
#include "CoreMinimal.h"
#include "ESocialCombatMode.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "Creature_NurtureComponent.generated.h"

class AActor;
class ACreature_Character;
class UCreatureVariationDataAsset;
class UObjectArchitectAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCreature_NurtureComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCreatureVariationDataAsset* VariationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_TameTargetPriorityWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TameTargetPriorityWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOverride_TameTargetMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESocialCombatMode TameTargetMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AActor> NurtureCalloutsActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NurtureCalloutsSocket;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector NurtureCalloutsOffset;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACreature_Character* CreatureCharacter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UObjectArchitectAsset* LoadedAudioAsset;
    
public:
    UCreature_NurtureComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsMale() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsAlbino() const;
    
};

