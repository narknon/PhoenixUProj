#pragma once
#include "CoreMinimal.h"
#include "AblAbilityTargetTypeLocation.h"
#include "AblParticleEffectParam.h"
#include "AblParticleEffectParamLocation.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblParticleEffectParamLocation : public UAblParticleEffectParam {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAblAbilityTargetTypeLocation m_Location;
    
public:
    UAblParticleEffectParamLocation();
};

