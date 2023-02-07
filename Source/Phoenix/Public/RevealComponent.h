#pragma once
#include "CoreMinimal.h"
#include "RevealData.h"
#include "StateEffectComponent.h"
#include "RevealComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class URevealComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRevealData RevealData;
    
public:
    URevealComponent();
};

