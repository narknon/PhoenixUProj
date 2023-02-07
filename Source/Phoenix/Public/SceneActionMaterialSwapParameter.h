#pragma once
#include "CoreMinimal.h"
#include "SceneActionMaterialSwapParameter.generated.h"

USTRUCT(BlueprintType)
struct FSceneActionMaterialSwapParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    PHOENIX_API FSceneActionMaterialSwapParameter();
};

