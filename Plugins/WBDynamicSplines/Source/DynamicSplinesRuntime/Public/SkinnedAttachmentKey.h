#pragma once
#include "CoreMinimal.h"
#include "SkinnedAttachmentKey.generated.h"

class UDynamicSplineSet;
class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct FSkinnedAttachmentKey {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicSplineSet* ParentSplineSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* HostMesh;
    
    DYNAMICSPLINESRUNTIME_API FSkinnedAttachmentKey();
};

