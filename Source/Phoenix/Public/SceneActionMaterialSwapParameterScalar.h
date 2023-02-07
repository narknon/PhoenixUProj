#pragma once
#include "CoreMinimal.h"
#include "SceneActionMaterialSwapParameter.h"
#include "SceneActionMaterialSwapParameterScalar.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct FSceneActionMaterialSwapParameterScalar : public FSceneActionMaterialSwapParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Value;
    
    PHOENIX_API FSceneActionMaterialSwapParameterScalar();
};

