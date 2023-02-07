#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EHighContrastGameplayBucket.h"
#include "HighContrastGameplayBucketPrimitiveState.h"
#include "PerWorldAccessibilitySettings.generated.h"

class UMaterialParameterCollection;
class UPrimitiveComponent;

UCLASS(Blueprintable, NotPlaceable, Transient)
class ACCESSIBILITYSETTINGS_API APerWorldAccessibilitySettings : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* HighContrastMPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* ExtraHighContrastMPC;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> CurrentTarget;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> OutlineTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 TargetStencilValue;
    
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UPrimitiveComponent>, FHighContrastGameplayBucketPrimitiveState> PrimitiveStateBuckets;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, uint32> MeshChangedActorMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 SetBaseStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastSetTargetStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastFadeToBlackBlend;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastExtraValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StateAlpha;
    
public:
    APerWorldAccessibilitySettings();
    UFUNCTION(BlueprintCallable)
    static void RemovePrimitiveFromHighContrastGameplayBuckets(UPrimitiveComponent* PrimitiveComponent);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActorFromHighContrastGameplayBuckets(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveActorFromHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void PrimitiveIsInHighContrastGameplayBucket(UPrimitiveComponent* PrimitiveComponent, EHighContrastGameplayBucket& Bucket, bool& bFound);
    
    UFUNCTION(BlueprintCallable)
    static void AddPrimitiveToHighContrastGameplayBucket(UPrimitiveComponent* PrimitiveComponent, EHighContrastGameplayBucket Bucket);
    
    UFUNCTION(BlueprintCallable)
    static void AddActorToHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void ActorIsInHighContrastGameplayBucket(AActor* Actor, EHighContrastGameplayBucket Bucket, bool& bFound);
    
};

