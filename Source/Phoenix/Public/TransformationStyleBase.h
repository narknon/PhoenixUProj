#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TransformationStyleBase.generated.h"

class ATransfigurationPreviewActor;

UCLASS(Blueprintable)
class ATransformationStyleBase : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationPreviewActor* OldPreviewActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ATransfigurationPreviewActor* NewPreviewActor;
    
    ATransformationStyleBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void StartTransformation();
    
};

