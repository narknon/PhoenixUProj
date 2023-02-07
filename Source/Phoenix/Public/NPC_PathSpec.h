#pragma once
#include "CoreMinimal.h"
#include "OdcPathSpec.h"
#include "ENPC_PathSpec.h"
#include "NPC_PathSpec.generated.h"

USTRUCT(BlueprintType)
struct FNPC_PathSpec {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_PathSpec Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOdcPathSpec PathSpec;
    
    PHOENIX_API FNPC_PathSpec();
};

