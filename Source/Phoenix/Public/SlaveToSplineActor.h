#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SlaveToSplineSlave.h"
#include "SlaveToSplineActor.generated.h"

class USplineComponent;

UCLASS(Blueprintable)
class ASlaveToSplineActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* FollowSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSlaveToSplineSlave> Slaves;
    
    ASlaveToSplineActor();
    UFUNCTION(BlueprintCallable)
    void ResetAll();
    
};

