#pragma once
#include "CoreMinimal.h"
#include "ESanctuaryIdentity.h"
#include "ParticleSystemsData.h"
#include "IdentityParticleSystemsData.generated.h"

USTRUCT(BlueprintType)
struct FIdentityParticleSystemsData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESanctuaryIdentity, FParticleSystemsData> IdentityOverrides;
    
    PHOENIX_API FIdentityParticleSystemsData();
};

