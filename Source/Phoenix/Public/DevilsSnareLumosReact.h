#pragma once
#include "CoreMinimal.h"
#include "DevilsSnareLumosReact.generated.h"

USTRUCT(BlueprintType)
struct FDevilsSnareLumosReact {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RecoilPercent;
    
    PHOENIX_API FDevilsSnareLumosReact();
};

