#pragma once
#include "CoreMinimal.h"
#include "PoseSampler.h"
#include "PoseSampler_AnimCurves.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class UPoseSampler_AnimCurves : public UPoseSampler {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LODThreshold;
    
    UPoseSampler_AnimCurves();
};

