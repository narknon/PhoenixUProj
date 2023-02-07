#pragma once
#include "CoreMinimal.h"
#include "ArrestoData.h"
#include "StateEffectComponent.h"
#include "ArrestoMomentumComponent.generated.h"

class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UArrestoMomentumComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FArrestoData ArrestoData;
    
public:
    UArrestoMomentumComponent();
    UFUNCTION(BlueprintCallable)
    void OnBroken(AActor* Actor);
    
};

