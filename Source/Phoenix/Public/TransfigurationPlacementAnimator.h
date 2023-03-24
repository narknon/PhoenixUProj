#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransfigurationPlacementAnimator.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable)
class ATransfigurationPlacementAnimator : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ATransfigurationPreviewActor> PreviewActor;
    
public:
    ATransfigurationPlacementAnimator(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SelectAnimationIndex();
    
    UFUNCTION(BlueprintCallable)
    int32 GetSelectedAnimIndex();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void DetachPreviewObject();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AttachPreviewObject(ATransfigurationPreviewActor* InPreviewActor);
    
};

