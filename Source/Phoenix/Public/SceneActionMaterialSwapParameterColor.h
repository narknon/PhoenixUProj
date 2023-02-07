#pragma once
#include "CoreMinimal.h"
#include "SceneActionMaterialSwapParameter.h"
#include "SceneActionMaterialSwapParameterColor.generated.h"

class UColorProvider;

USTRUCT(BlueprintType)
struct FSceneActionMaterialSwapParameterColor : public FSceneActionMaterialSwapParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UColorProvider* Value;
    
    PHOENIX_API FSceneActionMaterialSwapParameterColor();
};

