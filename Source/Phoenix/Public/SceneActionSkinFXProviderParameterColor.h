#pragma once
#include "CoreMinimal.h"
#include "SceneActionSkinFXProviderParameter.h"
#include "SceneActionSkinFXProviderParameterColor.generated.h"

class UColorProvider;

USTRUCT(BlueprintType)
struct FSceneActionSkinFXProviderParameterColor : public FSceneActionSkinFXProviderParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UColorProvider* Value;
    
    PHOENIX_API FSceneActionSkinFXProviderParameterColor();
};

