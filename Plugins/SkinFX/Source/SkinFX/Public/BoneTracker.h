#pragma once
#include "CoreMinimal.h"
#include "ActorTracker.h"
#include "BoneTracker.generated.h"

class USkinnedMeshComponent;

USTRUCT(BlueprintType)
struct SKINFX_API FBoneTracker : public FActorTracker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkinnedMeshComponent> BoneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BoneIndex;
    
public:
    FBoneTracker();
};

