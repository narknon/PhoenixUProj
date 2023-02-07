#pragma once
#include "CoreMinimal.h"
#include "DeflectionData.h"
#include "StateEffectComponent.h"
#include "DeflectionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDeflectionComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FDeflectionData Data;
    
public:
    UDeflectionComponent();
private:
    UFUNCTION(BlueprintCallable)
    void SetupDelegate();
    
};

