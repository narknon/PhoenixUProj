#pragma once
#include "CoreMinimal.h"
#include "AblParticleEffectParam.h"
#include "EAblAbilityTargetType.h"
#include "AblParticleEffectParamContextActor.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblParticleEffectParamContextActor : public UAblParticleEffectParam {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EAblAbilityTargetType> m_ContextActor;
    
public:
    UAblParticleEffectParamContextActor();
};

