#pragma once
#include "CoreMinimal.h"
#include "SceneActionSkinFXProviderParameter.h"
#include "SceneActionSkinFXProviderParameterScalar.generated.h"

class UFloatProvider;

USTRUCT(BlueprintType)
struct FSceneActionSkinFXProviderParameterScalar : public FSceneActionSkinFXProviderParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Value;
    
    PHOENIX_API FSceneActionSkinFXProviderParameterScalar();
};

