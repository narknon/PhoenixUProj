#pragma once
#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "Styling/SlateBrush.h"
#include "FlooTarget.generated.h"

class AEmitter;

UCLASS(Blueprintable)
class AFlooTarget : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEmitter* AvailableEmitter;
    
    AFlooTarget(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Handle_SetAvailable(bool availableIn);
    
    UFUNCTION(BlueprintCallable)
    bool GetAvailable();
    
};

