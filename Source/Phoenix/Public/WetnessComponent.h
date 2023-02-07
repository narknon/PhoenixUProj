#pragma once
#include "CoreMinimal.h"
#include "StateEffectComponent.h"
#include "WetnessComponent.generated.h"

class UMaterialPropertyData;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UWetnessComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialValue;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMaterialPropertyData* MaterialPropertyData;
    
public:
    UWetnessComponent();
    UFUNCTION(BlueprintCallable)
    void SetInWater(bool inWater);
    
};

