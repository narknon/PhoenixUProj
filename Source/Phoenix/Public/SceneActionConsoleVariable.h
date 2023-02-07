#pragma once
#include "CoreMinimal.h"
#include "SceneActionConsoleVariable.generated.h"

USTRUCT(BlueprintType)
struct FSceneActionConsoleVariable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Value;
    
    PHOENIX_API FSceneActionConsoleVariable();
};

