#pragma once
#include "CoreMinimal.h"
#include "CogTargetSceneComponent.h"
#include "CogTargetAimSceneComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCogTargetAimSceneComponent : public UCogTargetSceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timer;
    
    UCogTargetAimSceneComponent();
    UFUNCTION(BlueprintCallable)
    void TimerExpired();
    
};

