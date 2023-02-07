#pragma once
#include "CoreMinimal.h"
#include "PetrificusData.h"
#include "StateEffectComponent.h"
#include "PetrificusComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPetrificusComponent : public UStateEffectComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPetrificusData PetrificusData;
    
public:
    UPetrificusComponent();
};

