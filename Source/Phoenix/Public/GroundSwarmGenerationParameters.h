#pragma once
#include "CoreMinimal.h"
#include "GroundSwarmGenerationParameters.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FGroundSwarmGenerationParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Members;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* MemberMesh;
    
    PHOENIX_API FGroundSwarmGenerationParameters();
};

