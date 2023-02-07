#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightExtraParameter.h"
#include "AnimatedLightExtraSetupNiagaraParameter.generated.h"

class UNiagaraComponent;

USTRUCT(BlueprintType)
struct ANIMATEDLIGHTS_API FAnimatedLightExtraSetupNiagaraParameter : public FAnimatedLightExtraParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
    FAnimatedLightExtraSetupNiagaraParameter();
};

