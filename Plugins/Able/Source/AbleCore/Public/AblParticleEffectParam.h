#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AblParticleEffectParam.generated.h"

UCLASS(Abstract, Blueprintable)
class UAblParticleEffectParam : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName m_ParameterName;
    
public:
    UAblParticleEffectParam();
};

