#pragma once
#include "CoreMinimal.h"
#include "AttachmentKey.generated.h"

class UDynamicSplineSet;
class UStaticMeshComponent;

USTRUCT(BlueprintType)
struct FAttachmentKey {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicSplineSet* ParentSplineSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* HostMesh;
    
    DYNAMICSPLINESRUNTIME_API FAttachmentKey();
};

