#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "TransfigurationSpellToolBase.h"
#include "TransformationSpellTool.generated.h"

class AActor;
class ATransfigurationPlaceholder;
class ATransfigurationPreviewActor;
class ATransformationStyleBase;

UCLASS(Blueprintable)
class ATransformationSpellTool : public ATransfigurationSpellToolBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetObjectName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationPreviewActor* LeftBehindPreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TransformationDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<ATransformationStyleBase>> TransformationStyles;
    
public:
    ATransformationSpellTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void TransformPlaceholder(ATransfigurationPlaceholder* Placeholder, AActor* ExistingActor, FVector FxInfoCenter, FVector FxInfoExtent);
    
    UFUNCTION(BlueprintCallable)
    void StartHoldTransforming();
    
    UFUNCTION(BlueprintCallable)
    void SpawnPlaceholderNow(ATransfigurationPlaceholder* Placeholder);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPreviewDestroyed(AActor* DestroyedActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void FinishHoldTransforming();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ExitTransformAll();
    
    UFUNCTION(BlueprintCallable)
    void EnterTransformAll();
    
public:
    UFUNCTION(BlueprintCallable)
    void CancelHoldTransforming();
    
};

