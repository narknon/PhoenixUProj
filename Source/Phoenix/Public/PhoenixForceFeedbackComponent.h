#pragma once
#include "CoreMinimal.h"
#include "Components/ForceFeedbackComponent.h"
#include "PhoenixForceFeedbackComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPhoenixForceFeedbackComponent : public UForceFeedbackComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CadenceMultiplier;
    
    UPhoenixForceFeedbackComponent();
    UFUNCTION(BlueprintCallable)
    void SetCadenceMultiplier(float NewCadenceMultiplier);
    
};

