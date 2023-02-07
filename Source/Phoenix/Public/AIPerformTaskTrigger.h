#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "AIPerformTaskBase.h"
#include "AIPerformTaskTrigger.generated.h"

class AActor;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(Blueprintable, EditInlineNew)
class UAIPerformTaskTrigger : public UAIPerformTaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector WaitTriggerScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* WaitTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOrientToPlayer;
    
    UAIPerformTaskTrigger();
private:
    UFUNCTION(BlueprintCallable)
    void OnWaitTriggerOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

