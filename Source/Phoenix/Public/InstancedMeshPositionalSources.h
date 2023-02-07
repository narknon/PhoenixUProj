#pragma once
#include "CoreMinimal.h"
#include "InstancedMeshPositionalSource.h"
#include "InstancedMeshPositionalSources.generated.h"

USTRUCT(BlueprintType)
struct FInstancedMeshPositionalSources {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInstancedMeshPositionalSource> Sources;
    
    PHOENIX_API FInstancedMeshPositionalSources();
};

