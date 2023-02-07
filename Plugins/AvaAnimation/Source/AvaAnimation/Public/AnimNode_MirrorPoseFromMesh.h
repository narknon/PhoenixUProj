#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_MirrorPoseFromMesh.generated.h"

class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimNode_MirrorPoseFromMesh : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkeletalMeshComponent> SourceMeshComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseAttachedParent: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bCopyCurves: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCopyCustomAttributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bUseMeshPose: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RootBoneToCopy;
    
    FAnimNode_MirrorPoseFromMesh();
};

