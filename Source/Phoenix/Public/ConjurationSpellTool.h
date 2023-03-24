#pragma once
#include "CoreMinimal.h"
#include "ConjuredHistoryItem.h"
#include "LockableTransfigurationItem.h"
#include "Templates/SubclassOf.h"
#include "TransfigurationSpellToolBase.h"
#include "ConjurationSpellTool.generated.h"

class ATransfigurationPreviewActor;
class ATransformationStyleBase;

UCLASS(Blueprintable)
class AConjurationSpellTool : public ATransfigurationSpellToolBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedCategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedSubcategory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SelectedIcon;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurrentItemID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FConjuredHistoryItem> LastConjuredItems;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementThresholdToSpawnNextPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleThresholdToSpawnNextPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinConjurationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxConjurationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNumItemsForConjurationDurationMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDefaultVanishmentForSingleObjectUndo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ATransfigurationPreviewActor> UndoPreviewActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinSecondsBetweenUndoVanishments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ATransformationStyleBase>> TransformationStyles;
    
public:
    AConjurationSpellTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdatePreviewResourceRequirementsMet();
    
    UFUNCTION(BlueprintCallable)
    void UpdateHoldConjuring(float TimeRatio);
    
    UFUNCTION(BlueprintCallable)
    void UndoLastConjuredItem();
    
    UFUNCTION(BlueprintCallable)
    void StartHoldConjuring();
    
    UFUNCTION(BlueprintCallable)
    void ShowItemPreview(FName InItemID, FName InColorID);
    
    UFUNCTION(BlueprintCallable)
    void SetCategory(FName CategoryID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FLockableTransfigurationItem> GetSubCategories(const FName CategoryName);
    
    UFUNCTION(BlueprintCallable)
    TArray<FLockableTransfigurationItem> GetItemList();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLockableTransfigurationItem GetItemData(FName ItemOrCategoryName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCurrentCategory() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetCategoryTextKey() const;
    
    UFUNCTION(BlueprintCallable)
    void FinishHoldConjuring();
    
    UFUNCTION(BlueprintCallable)
    void ConjureMenuFullStop();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanUndoLastItem() const;
    
    UFUNCTION(BlueprintCallable)
    void CannotHoldConjuring();
    
    UFUNCTION(BlueprintCallable)
    void CancelHoldConjuring(float TimeRatio);
    
};

