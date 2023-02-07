#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "MappedTimedParticleEffect.h"
#include "AnimNotifyState_SharedTimedParticleEffect.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew, MinimalAPI)
class UAnimNotifyState_SharedTimedParticleEffect : public UAnimNotifyState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USkeletalMesh*, FMappedTimedParticleEffect> SharedTimedParticleEffects;
    
    UAnimNotifyState_SharedTimedParticleEffect();
};

