#pragma once
#include "CoreMinimal.h"
#include "SceneActionSkinFXProviderParameter.generated.h"

USTRUCT(BlueprintType)
struct FSceneActionSkinFXProviderParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Parameter;
    
    PHOENIX_API FSceneActionSkinFXProviderParameter();
};

