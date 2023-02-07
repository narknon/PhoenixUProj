#pragma once
#include "CoreMinimal.h"
#include "ImperiusData.h"
#include "StateEffectComponent.h"
#include "ImperiusComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UImperiusComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FImperiusData ImperiusData;
    
    UImperiusComponent();
    UFUNCTION(BlueprintCallable)
    void BP_EndEffect();
    
    UFUNCTION(BlueprintCallable)
    void AttachEmitters();
    
};

