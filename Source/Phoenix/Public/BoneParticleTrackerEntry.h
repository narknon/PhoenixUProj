#pragma once
#include "CoreMinimal.h"
#include "BoneParticleTrackerEntry.generated.h"

class UParticleSystemComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FBoneParticleTrackerEntry {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> ParentComponent;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UParticleSystemComponent> ParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachBone;
    
    PHOENIX_API FBoneParticleTrackerEntry();
};

