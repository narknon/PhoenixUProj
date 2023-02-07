#pragma once
#include "CoreMinimal.h"
#include "SceneActionSkinFXProviderParameter.h"
#include "SceneActionSkinFXProviderParameterVector.generated.h"

class UVectorProvider;

USTRUCT(BlueprintType)
struct FSceneActionSkinFXProviderParameterVector : public FSceneActionSkinFXProviderParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVectorProvider* Value;
    
    PHOENIX_API FSceneActionSkinFXProviderParameterVector();
};

