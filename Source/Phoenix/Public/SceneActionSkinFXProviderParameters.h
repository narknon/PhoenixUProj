#pragma once
#include "CoreMinimal.h"
#include "SceneActionSkinFXProviderParameterColor.h"
#include "SceneActionSkinFXProviderParameterScalar.h"
#include "SceneActionSkinFXProviderParameterVector.h"
#include "SceneActionSkinFXProviderParameters.generated.h"

USTRUCT(BlueprintType)
struct FSceneActionSkinFXProviderParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionSkinFXProviderParameterScalar> Scalars;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionSkinFXProviderParameterVector> Vectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSceneActionSkinFXProviderParameterColor> Colors;
    
    PHOENIX_API FSceneActionSkinFXProviderParameters();
};

