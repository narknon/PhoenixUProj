#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "EFootPlantEnum.h"
#include "EStandardManagedPriority.h"
#include "AnimationRequestLayer.h"
#include "AnimationRequestLayerHost.h"
#include "EAnimationDirectionSource.h"
#include "EAnimationDirections.h"
#include "Templates/SubclassOf.h"
#include "AnimationComponent.generated.h"

class UAnimAsset_TickAssetPlayerProxy;
class UAnimLayersAsset;
class UAnimSequence;
class UControlRig;
class UFloatProvider;
class UIKDriver;
class UObject;
class UTransformProvider;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AVAANIMATION_API UAnimationComponent : public UActorComponent, public IAnimationRequestLayerHost {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationRequestLayer> Layers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimLayersAsset* LayersAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UControlRig> ControlRigClass;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UControlRig* ControlRig;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UIKDriver*> IKDrivers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LadderContactEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HighestLODLevelForIK;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOD_IKBlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LOD_IKBlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StrideWarpFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EFootPlantEnum FootPlant;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bHoldFootPositionWhenPlanted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CapsuleInterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAnimationDirections, FVector> DefaultDirectionInComponentSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<bool> ResetDefaultDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxLookAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFloatProvider* TimeDelayProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFloatProvider* BlendInTimeProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequence* LastSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float LastSequenceTime;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAnimAsset_TickAssetPlayerProxy* TickAssetPlayerProxy;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FGameplayTag, UTransformProvider*> TaggedTransformProviders;
    
public:
    UAnimationComponent();
    UFUNCTION(BlueprintCallable)
    void StartSettingPoseFixupEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingLookAtEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingIKEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingFloorContactEnabled(const bool bInEnabled, const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void StartIKBlendOut(float Duration);
    
    UFUNCTION(BlueprintCallable)
    void StartIKBlendIn(float Duration);
    
    UFUNCTION(BlueprintCallable)
    static void SetPlayerIKEnabled(bool State);
    
    UFUNCTION(BlueprintCallable)
    void SetLadderInfo(float BottomRungZ, float TopRungZ, float RungSpacing, FVector LadderWorldPos, FVector LadderFaceNormal);
    
    UFUNCTION(BlueprintCallable)
    void SetLadderIKEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    static void SetGlobalIKEnabled(bool State);
    
    UFUNCTION(BlueprintCallable)
    void SetDirectionWeight(EAnimationDirections Direction, EAnimationDirectionSource Source, float weight);
    
    UFUNCTION(BlueprintCallable)
    void SetDirectionTargetAndWeightNoCap(EAnimationDirections Direction, EAnimationDirectionSource Source, FVector TargetInWorldSpace, float weight);
    
    UFUNCTION(BlueprintCallable)
    void SetDirectionTargetAndWeight(EAnimationDirections Direction, EAnimationDirectionSource Source, FVector TargetInWorldSpace, float weight);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimLayersAsset(UAnimLayersAsset* InLayersAsset);
    
    UFUNCTION(BlueprintCallable)
    void ResetDefaultDirectionNow(EAnimationDirections Direction);
    
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerIKEnabled();
    
    UFUNCTION(BlueprintCallable)
    static bool IsGlobalIKEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UIKDriver* GetIKDriverFromClass(TSubclassOf<UIKDriver> IKDriverClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetIKBlendWeight() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDirectionTargetAndWeight(EAnimationDirections Direction, FVector& OutTargetInWorldSpace, float& OutWeight) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetDefaultDirection(EAnimationDirections Direction, FVector& OutDefaultDirectionInComponentSpace) const;
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingPoseFixupEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingLookAtEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingIKEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingFloorContactEnabled(const EStandardManagedPriority InPriority, const UObject* Provider, const float InBlendDuration);
    
    
    // Fix for true pure virtual functions not being implemented
};

