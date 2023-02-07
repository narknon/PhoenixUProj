#pragma once
#include "CoreMinimal.h"
#include "BTCustomAction.h"
#include "ChannelingSpellTool.h"
#include "ETransfigurationPlacementError.h"
#include "LockableTransfigurationItem.h"
#include "TransfigurationResource.h"
#include "TransfigurationSpellToolBase.generated.h"

class ATransfigurationPreviewActor;
class UTransformationSpellToolComponent;

UCLASS(Abstract, Blueprintable)
class ATransfigurationSpellToolBase : public AChannelingSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBTCustomAction TransfigurationAction;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName ObjectCategoryName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLockableTransfigurationItem> TransformationOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLockableTransfigurationItem SelectedTransformationOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FLockableTransfigurationItem> ColorOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FLockableTransfigurationItem SelectedColorOption;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FName> CategoryBreadcrumbs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float TwirlDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldingDurationBeforeTransfigurationTimerStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWaitForCharacterAnimations;
    
public:
    ATransfigurationSpellToolBase();
    UFUNCTION(BlueprintCallable)
    void TransformObject_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    void SetTransformComponentRef(UTransformationSpellToolComponent* TC);
    
    UFUNCTION(BlueprintCallable)
    void ScaleUp();
    
    UFUNCTION(BlueprintCallable)
    void ScaleDown();
    
    UFUNCTION(BlueprintCallable)
    void RotateRight_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    void RotateRight();
    
    UFUNCTION(BlueprintCallable)
    void RotateLeft_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    void RotateLeft();
    
    UFUNCTION(BlueprintCallable)
    bool PrevTransformation();
    
    UFUNCTION(BlueprintCallable)
    void PrevColor();
    
    UFUNCTION(BlueprintCallable)
    void PrepareToExit();
    
    UFUNCTION(BlueprintCallable)
    void PrepareToBack();
    
    UFUNCTION(BlueprintCallable)
    bool NextTransformation();
    
    UFUNCTION(BlueprintCallable)
    void NextColor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectStationary() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectScalable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsObjectRotatable() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTransformationOptions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasColorOptions() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTransfigurationDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTransfigurationResource> GetRequiredResources() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ATransfigurationPreviewActor* GetPreviewActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ETransfigurationPlacementError GetPlacementError() const;
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHoldingDurationBeforeTransfigurationTimerStart() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void Exit();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool DoesObjectSupportSnapping() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ConsumesSanctuaryContextResources() const;
    
    UFUNCTION(BlueprintCallable)
    void ConjurePreview_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    void ConfirmTransfiguration_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    bool ConfirmTransfiguration();
    
    UFUNCTION(BlueprintCallable)
    void ColorObject_FromMotion();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanPlaceItem() const;
    
    UFUNCTION(BlueprintCallable)
    void CancelPreview_FromMotion();
    
    UFUNCTION(BlueprintCallable)
    void Back();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreResourceRequirementsMet() const;
    
};

