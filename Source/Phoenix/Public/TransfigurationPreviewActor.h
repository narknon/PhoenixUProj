#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ETransfigurationSnapping.h"
#include "TransfigurationResource.h"
#include "TransfigurationPreviewActor.generated.h"

class ATransfigurationMovementStyleBase;
class ATransfigurationPreviewActor;
class ATransformationStyleBase;
class AVanishmentStyleBase;
class UActorComponent;
class UAnimInstance;
class UMeshComponent;
class USceneComponent;

UCLASS(Abstract, Blueprintable)
class ATransfigurationPreviewActor : public AActor {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTransfigurationPreviewMeshLoaded);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationMovementStyleBase* MovementStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TwirlDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, USceneComponent*> CopiedPlantComponentMap;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransfigurationPreviewMeshLoaded PreviewMeshLoadedDelegate;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector SurfaceNormal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETransfigurationSnapping Snapping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bSurfaceFound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCopyDecalComponents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMaintainCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<UAnimInstance>> AnimBPsExcludedFromBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* PreviewMeshRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTestFixedLoadDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FixedLoadDuration;
    
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UActorComponent>> CopiedComponents;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> AssociatedObjects;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ATransfigurationPreviewActor> DependentPreview;
    
public:
    ATransfigurationPreviewActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool UsesSurfacePlacement() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateMeshOpacity(float Opacity);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHoldConjuring(float TimeRatio, const TArray<FTransfigurationResource>& Resources, FVector WandPos);
    
protected:
    UFUNCTION(BlueprintCallable)
    void UnpauseAssociatedSkeletalMeshComponents();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TransformedFromOtherPreview(ATransfigurationPreviewActor* InPreviousPreview);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SwitchToNewMesh();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartHoldVanishing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartHoldTransforming();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartHoldConjuring(float TotalConjurationDuration, const TArray<FTransfigurationResource>& Resources, FVector WandPos);
    
    UFUNCTION(BlueprintCallable)
    AVanishmentStyleBase* SpawnVanishmentStyle();
    
    UFUNCTION(BlueprintCallable)
    ATransformationStyleBase* SpawnTransformationStyle(ATransfigurationPreviewActor* InNewActor);
    
    UFUNCTION(BlueprintCallable)
    void SetSurfaceNormal(const bool bInSurfaceFound, const FVector& InSurfaceNormal);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawningIn(bool bIsSpawning);
    
    UFUNCTION(BlueprintCallable)
    void SetCanPlace(const bool bInCanPlace);
    
    UFUNCTION(BlueprintCallable)
    void SetAssociatedObjectActors(TArray<AActor*> InActorList);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ResetToOriginalScale();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnVanishStart();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnTransformWithoutStyle();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnTransformStart(ATransfigurationPreviewActor* InNewPreview);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSizeChange(float StartScale, float EndScale);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreviewMeshLoaded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFakeLoadDurationTimerElapsed();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ObjectSelected();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectDeselected(AActor* InNewActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void ObjectConfirmed(const TArray<AActor*>& InNewActors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStationary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawningIn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool IsReadyForPlacement() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsPreviewInTransition() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPrefab() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocked() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBeingRemoved() const;
    
    UFUNCTION(BlueprintCallable)
    void HideActorAndChildren(AActor* InActor, bool bHide);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetTransfigurationFxInfos(FVector& OutObjectCenter, FVector& OutObjectExtent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetTransfigurationClass() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetTargetTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPreviewBounds(FVector& OutCenter, FVector& OutExtent) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetObjectType() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetObjectCategory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsPreviewMeshLoaded() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetColor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetAttachmentTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetActorLocalPreviewBounds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FinishHoldVanishing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FinishHoldTransforming();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FinishHoldConjuring(const TArray<FTransfigurationResource>& Resources, FVector WandPos);
    
    UFUNCTION(BlueprintCallable)
    TArray<UMeshComponent*> DuplicateMeshComponents();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ConjuredFromThinAir();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ColorAboutToChange();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlace() const;
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CannotHoldConjuring();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanChangeColor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void CancelledIntoThinAir();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelHoldVanishing();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelHoldTransforming();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CancelHoldConjuring(float TimeRatio, const TArray<FTransfigurationResource>& Resources, FVector WandPos);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnTransformationLoaded();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BlueprintInitialize();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreResourceRequirementsMet() const;
    
};

