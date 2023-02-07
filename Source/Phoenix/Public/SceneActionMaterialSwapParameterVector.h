#pragma once
#include "CoreMinimal.h"
#include "SceneActionMaterialSwapParameter.h"
#include "SceneActionMaterialSwapParameterVector.generated.h"

class UVectorProvider;

USTRUCT(BlueprintType)
struct FSceneActionMaterialSwapParameterVector : public FSceneActionMaterialSwapParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* Value;
    
    PHOENIX_API FSceneActionMaterialSwapParameterVector();
};

