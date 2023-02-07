#pragma once
#include "CoreMinimal.h"
#include "InstancedMeshPositionalSource.generated.h"

class UAkComponent;

USTRUCT(BlueprintType)
struct FInstancedMeshPositionalSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Instance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* SoundComponent;
    
    PHOENIX_API FInstancedMeshPositionalSource();
};

