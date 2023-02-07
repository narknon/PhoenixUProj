#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "MappedParticleEffect.h"
#include "AnimNotify_PlaySharedParticleEffect.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_PlaySharedParticleEffect : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USkeletalMesh*, FMappedParticleEffect> SharedParticleEffects;
    
    UAnimNotify_PlaySharedParticleEffect();
};

