#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DynamicBucketGroupStack.h"
#include "ETickSequencerGroup.h"
#include "TickSequencerUpdateBucketList.h"
#include "TickSequencerSingleton.generated.h"

class UTickSequencerBucketSetup;
class UTickSequencerUpdateComponent;
class UTickSequencerUpdateComponentDelegateUpdate;

UCLASS(Blueprintable, NotPlaceable, Transient)
class TICKSEQUENCER_API ATickSequencerSingleton : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTickSequencerBucketSetup* BucketSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponent* PrePhysicsBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponent* DuringPhysicsBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponent* PostPhysicsBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponent* PostUpdateWorkBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponentDelegateUpdate* PreActorTickBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTickSequencerUpdateComponentDelegateUpdate* PostActorTickBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTickSequencerUpdateBucketList DynamicBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDynamicBucketGroupStack DynamicBucketGroupStack;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 LastGetExtraBucketsFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETickSequencerGroup CachedDynamicBucketGroup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bUseExternalPostActorTick;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    uint32 ManualTickFrame;
    
public:
    ATickSequencerSingleton(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ForceTick();
    
};

