#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraStackData.h"
#include "ECameraStackBehaviorSorting.h"
#include "OptionalTriplet.h"
#include "Templates/SubclassOf.h"
#include "CameraStack.generated.h"

class ACameraStackActor;
class UCameraStackBehavior;
class UCameraStackBehaviorCore;
class UCameraStackBehaviorMultiBehaviorBlend;

UCLASS(Blueprintable, DefaultToInstanced)
class CAMERASTACK_API UCameraStack : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UCameraStackBehavior*> Behaviors;
    
public:
    UCameraStack();
    UFUNCTION(BlueprintCallable)
    bool UnpauseBehavior(UCameraStackBehavior* InBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool ResetBehaviors(UCameraStackBehaviorCore* InBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool ReplaceCoreBehavior(UCameraStackBehaviorCore* InBehavior, float InBlendOutDuration, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable)
    bool ReplaceBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InPredecessorBehavior, float InBlendOutDuration, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable)
    bool RemoveBehavior(UCameraStackBehavior* InBehavior, float InBlendOutDuration);
    
    UFUNCTION(BlueprintCallable)
    bool PauseBehavior(UCameraStackBehavior* InBehavior);
    
    UFUNCTION(BlueprintCallable)
    bool InsertBeforeBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InBeforeBehavior, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable)
    bool InsertAfterBehavior(UCameraStackBehavior* InBehavior, const UCameraStackBehavior* InAfterBehavior, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackBehavior* GetTopmostBehavior() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool GetRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACameraStackActor* GetOwner() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetFocusDistanceLimits(float& OutMin, float& OutMax);
    
    UFUNCTION(BlueprintCallable)
    bool GetFieldOfViewLimits(float& OutMin, float& OutMax);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackBehaviorCore* GetCoreBehavior() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool GetCameraSpaceTranslationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax);
    
    UFUNCTION(BlueprintCallable)
    bool GetCameraSpaceRotationLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackBehavior* GetBehaviourWithType(TSubclassOf<UCameraStackBehavior> InType, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraStackBehavior* GetBehaviorWithTypes(const TArray<TSubclassOf<UCameraStackBehavior>>& InTypes, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UCameraStackBehavior*> GetBehaviorsWithTypes(const TArray<TSubclassOf<UCameraStackBehavior>>& InTypes, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UCameraStackBehavior*> GetBehaviorsWithType(TSubclassOf<UCameraStackBehavior> InType, ECameraStackBehaviorSorting InSorting, int32 FilterFlags) const;
    
protected:
    UFUNCTION(BlueprintCallable)
    bool GetArmOriginLimits(FOptionalTriplet& OutMin, FOptionalTriplet& OutMax);
    
public:
    UFUNCTION(BlueprintCallable)
    bool GetArmLengthLimits(float& OutMin, float& OutMax);
    
    UFUNCTION(BlueprintCallable)
    bool GetApertureLimits(float& OutMin, float& OutMax);
    
    UFUNCTION(BlueprintCallable)
    bool EnableBehavior(UCameraStackBehavior* InBehavior, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable)
    bool DisableBehavior(UCameraStackBehavior* InBehavior, float InBlendOutDuration);
    
    UFUNCTION(BlueprintCallable)
    UCameraStackBehavior* CreateNonCoreBehavior(TSubclassOf<UCameraStackBehavior> BehaviorClass, UObject* Template);
    
    UFUNCTION(BlueprintCallable)
    UCameraStackBehaviorCore* CreateCoreBehavior(TSubclassOf<UCameraStackBehaviorCore> BehaviorClass, UObject* Template);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ContainsBehaviorWithType(const TSubclassOf<UCameraStackBehavior>& InType, int32 FilterFlags) const;
    
    UFUNCTION(BlueprintCallable)
    UCameraStackBehaviorMultiBehaviorBlend* AddStackBehaviors(const FCameraStackData& InStackData, float InBlendInDuration);
    
    UFUNCTION(BlueprintCallable)
    bool AddBehavior(UCameraStackBehavior* InBehavior, float InBlendInDuration, bool bInSkipFlags);
    
};

