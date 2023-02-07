#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightExtraParameterRuntime.h"
#include "AnimatedLightExtraNiagaraParameter.generated.h"

class UNiagaraComponent;

USTRUCT(BlueprintType)
struct ANIMATEDLIGHTS_API FAnimatedLightExtraNiagaraParameter : public FAnimatedLightExtraParameterRuntime {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNiagaraComponent> NiagaraComponent;
    
    FAnimatedLightExtraNiagaraParameter();
};

